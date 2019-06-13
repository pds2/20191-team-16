#include "mail.h"
#include "gerais.h"

#include <string>
#include <fstream>
#include <iostream>
#include <sys/stat.h>

#define ACESS 0777

#define LIMITE 20
//Submetodos
void Mail::criar_log()
{
    mkdir("Data", ACESS);

    std::fstream create_log;
    create_log.open("Data/log.txt", std::ios::out);
    create_log.close();
}

/*Funcao que verifica se a string nao possui
  caracteres que impessam a criacao de diretorios*/
bool Mail::scan_nome(std::string nome)
{
    /*No caso do Linux/Unix (incluindo Mac OS), o unico
      caractere proibido e o "/" (foward slash) */

    for (unsigned int i = 0; i < nome.size(); i++)
    {
        if (nome[i] == '/')
        {
            std::fstream registroerror1;
            registroerror1.open("Assets/Registro/registroerror1.txt");

            display_caixa(registroerror1, "\033[31m");

            botao_enter();

            return false;
        }
    }

    if (nome.size() > LIMITE)
    {
        std::fstream registroerror2;
        registroerror2.open("Assets/Registro/registroerror2.txt");

        display_caixa(registroerror2, "\033[31m");

        botao_enter();

        return false;
    }
    return true;
}

//Funcao para achar um nome dentro do log.txt
bool Mail::match_log(std::string nome)
{
    std::fstream read_log;
    read_log.open("Data/log.txt", std::ios::in);

    if (!read_log)
    {
        std::cout << "\n[Arquivo log.txt nao encontrado]" << std::endl;
        exit(0);
    }

    //String para comparacao
    std::string compr;

    while (true)
    {
        //Quebrar o loop quando chegar ao fim do arquivo
        if (read_log.eof()) break;

        read_log >> compr;

        if (nome == compr)
        {
            read_log.close();
            return true;
        }
        else compr.clear();
    }

    read_log.close();
    return false;
}

/*Funcao que cria os diretorios para armazenamento de mensagens e senha do
  usuario*/

void Mail::criar_user(std::string nome, std::string senha)
{

    mkdir(("Data/" + nome).c_str(), ACESS);
    mkdir(("Data/" + nome + "/inbox").c_str(), ACESS);
    mkdir(("Data/" + nome + "/outbox").c_str(), ACESS);

    //Criando e escrevendo nos arquivos de texto

    std::fstream log_in;
    log_in.open(("Data/" + nome + "/inbox/log_in.txt").c_str(), std::ios::out);
    log_in.close();

    std::fstream log_out;
    log_out.open(("Data/" + nome + "/outbox/log_out.txt").c_str(), std::ios::out);
    log_out.close();

    std::fstream write_pass;

    write_pass.open(("Data/" + nome + "/password.txt").c_str(), std::ios::out);
    write_pass << senha << std::endl;
    write_pass.close();

    std::fstream write_log;
    write_log.open("Data/log.txt", std::ios::ate | std::ios::in | std::ios::out);

    if (!write_log)
    {
        std::cout << "\n[Arquivo log.txt nao encontrado]" << std::endl;
        exit(0);
    }

    write_log << nome << std::endl;
    write_log.close();
}

//Metodos
short Mail::init()
{
    short esc;

    while (true)
    {
        //Funcao que oferece as tres opcoes do inicio do programa (Login, Registro, Sair)
        std::fstream title;
        title.open("Assets/Init/title.txt", std::ios::in);

        display_caixa(title, "\033[m");

        std::cout << "                                   [1]Login"    << std::endl;
        std::cout << "                                   [2]Registro" << std::endl;
        std::cout << "                                   [3]Sair"     << std::endl;

        std::cout << "\n                                   Escolha: ";

        std::cin  >> esc;

        limpar_buffer();

        if ((esc > 3) || (esc < 1))
        {


            std::fstream initerror;
            initerror.open("Assets/Init/initerror.txt", std::ios::in);

            display_caixa(initerror, "\033[31m");

            botao_enter();

            continue;
        }

        else break;
    }

    return esc;
}

std::string Mail::login()
{
    // Funcao para Login do usuario no sistema de email
    // Pede-se a entrada de um nome e uma senha que serao verificadas
    // Se os dados entrados estiverem corretos, retorna-se o nome
    // do usuario, caso contrário os dados são limpados e o processo de login
    // e reiniciado.
    // A funcao para quando o usuario digita --sair, retornando "false".
    std::string nome;
    std::string senha;
    std::string senha_cmpr; // String para comparar as senhas
    std::fstream read_pass;

    while (true)
    {
        std::fstream login0;
        login0.open("Assets/Login/login0.txt", std::ios::in);

        display_caixa(login0, "\033[m");

        botao_enter();

        // ENTRADA DO NOME DE USUARIO
        std::fstream login1;
        login1.open("Assets/Login/login1.txt", std::ios::in);

        display_caixa(login1, "\033[m");

        std::cout << "                                $: ";
        std::cin >> nome;

        limpar_buffer();

        // RETURN CASO NOME = --SAIR
        if(nome=="--sair")
        {
            std::fstream logincancel;
            logincancel.open("Assets/Login/logincancel.txt", std::ios::in);

            display_caixa(logincancel, "\033[m");

            botao_enter();

            return "false";
        }
        // ENTRADA DA SENHA
        std::fstream login2;
        login2.open("Assets/Login/login2.txt", std::ios::in);

        display_caixa(login2, "\033[m");

        std::cout << "                                $: ";
        std::cin >> senha;

        limpar_buffer();

        // RETURN CASO SENHA = --SAIR
        if(senha=="--sair")
        {
            std::fstream logincancel;
            logincancel.open("Assets/Login/logincancel.txt", std::ios::in);

            display_caixa(logincancel, "\033[m");

            botao_enter();
            return "false";
        }

        //VERIFICA-SE A EXISTENCIA DO USUARIO
        if(match_log(nome))
        {
            //ABERTURA DO PASSWORD.TXT NA PASTA DO USUARIO
            read_pass.open(("Data/"+ nome +"/password.txt").c_str(), std::ios::in);
            if(!read_pass)
            {
                std::fstream loginerror1;
                loginerror1.open("Assets/Login/loginerror1.txt", std::ios::in);

                display_caixa(loginerror1, "\033[31m");

                botao_enter();

                return "false";
            }
            else
            {
                //COMPARANDO A SENHA REGISTRADA COM A ENTRADA DO USER
                read_pass >> senha_cmpr;
                if(senha_cmpr == senha)
                {   //CASO AS SENHAS COINCIDAM
                    senha.clear();
                    senha_cmpr.clear();
                    read_pass.close();

                    std::fstream loginsuccess;
                    loginsuccess.open("Assets/Login/loginsuccess.txt", std::ios::in);

                    display_caixa(loginsuccess, "\033[32m");

                    botao_enter();

                    return nome;
                }
                else
                {   //CASO AS SENHAS NAO COINCIDAM
                    nome.clear();
                    senha.clear();
                    senha_cmpr.clear();
                    read_pass.close();

                    std::fstream loginerror2;
                    loginerror2.open("Assets/Login/loginerror2.txt", std::ios::in);

                    display_caixa(loginerror2, "\033[31m");

                    botao_enter();

                    continue;
                }
            }
        }
        else
        {   //RETORNANDO AO INICIO DO PROCESSO CASO O USUARIO NAO EXISTA
            nome.clear();
            senha.clear();
            senha_cmpr.clear();
            std::fstream loginerror2;
            loginerror2.open("Assets/Login/loginerror2.txt", std::ios::in);

            display_caixa(loginerror2, "\033[31m");

            botao_enter();

            continue;
        }
    }
}

void Mail::registro()
{
    std::string nome;
    std::string senha;
    std::fstream read_log;

    while (true)
    {
        std::fstream registro0;
        registro0.open("Assets/Registro/registro0.txt");

        display_caixa(registro0, "\033[m");

        botao_enter();

        while (true)
        {
            std::fstream registro1;
            registro1.open("Assets/Registro/registro1.txt");

            display_caixa(registro1, "\033[m");

            std::cout << "                                $: ";
            std::cin  >> nome;

            limpar_buffer();

            if (!scan_nome(nome))
            {
                nome.clear();
                continue;
            }

            if (nome == "--sair")
            {
                std::fstream registrocancel;
                registrocancel.open("Assets/Registro/registrocancel.txt", std::ios::in);

                display_caixa(registrocancel, "\033[m");

                botao_enter();

                return;
            }

            read_log.open("Data/log.txt", std::ios::in);

            if (read_log)
            {
                if(match_log(nome))
                {
                    std::fstream registroerror3;
                    registroerror3.open("Assets/Registro/registroerror3.txt", std::ios::in);

                    display_caixa(registroerror3, "\033[31m");

                    botao_enter();

                    read_log.close();
                    continue;
                }
            }
            else
            {
                read_log.close();
                criar_log();
            }

            break;
        }

        std::fstream registro2;
        registro2.open("Assets/Registro/registro2.txt", std::ios::in);

        display_caixa(registro2, "\033[m");

        std::cout << "                                $: ";
        std::cin  >> senha;

        limpar_buffer();

        if (senha == "--sair")
        {
            std::fstream registrocancel;
            registrocancel.open("Assets/Registro/registrocancel.txt", std::ios::in);

            display_caixa(registrocancel, "\033[m");

            botao_enter();

            return;
        }

        std::fstream registro3;
        registro3.open("Assets/Registro/registro3.txt", std::ios::in);

        display_caixa(registro3, "\033[m");

        char esc;

        std::cout << "                                $: ";
        std::cin  >> esc;

        limpar_buffer();

        if ((esc == 'S') || (esc == 's'))
            break;

        else
        {
            //Limpando as strings de nome e senha
            nome.clear();
            senha.clear();
            continue;
        }
    }

    criar_user(nome, senha);

    std::fstream registrosuccess;
    registrosuccess.open("Assets/Registro/registrosuccess.txt", std::ios::in);

    display_caixa(registrosuccess, "\033[32m");

    botao_enter();
}
