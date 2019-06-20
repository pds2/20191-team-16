#include "mail.h"
#include "gerais.h"

#include <string>
#include <fstream>
#include <iostream>
#include <sys/stat.h>

/*Valor da funcao mkdir que define as permissoes de acesso aos diretorios criados
  0777 = acesso de todos os grupo*/
#define ACESS 0777

//Numero maximo de caracteres permitidos para nome
#define LIMITE 20

//Valor da cor dos textos para a funcao display_caixa
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define DEFAULT "\033[m"

//Submetodos
void Mail::criar_log()
{
    mkdir("Data", ACESS);

    std::fstream create_log;
    create_log.open("Data/log.txt", std::ios::out);
    create_log.close();
}

bool Mail::scan_nome(std::string nome)
{
    /*No caso do Linux/Unix (incluindo Mac OS), o unico
      caractere proibido e o "/" (foward slash) */

    for (unsigned int i = 0; i < nome.size(); i++)
    {
        if (nome[i] == '/')
        {
            display_caixa("Assets/Registro/registroerror1.txt", RED);
            botao_enter();

            return false;
        }
    }

    if (nome.size() > LIMITE)
    {
        display_caixa("Assets/Registro/registroerror2.txt", RED);
        botao_enter();

        return false;
    }
    return true;
}

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
        display_caixa("Assets/Init/title.txt", DEFAULT);

        std::cout << "                                   [1]Login"    << std::endl;
        std::cout << "                                   [2]Registro" << std::endl;
        std::cout << "                                   [3]Sair"     << std::endl;

        std::cout << "\n                                   Escolha: ";

        std::cin  >> esc;

        limpar_buffer();

        if ((esc > 3) || (esc < 1))
        {
            display_caixa("Assets/Init/initerror.txt", RED);
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
        display_caixa("Assets/Login/login0.txt", DEFAULT);
        botao_enter();

        // ENTRADA DO NOME DE USUARIO
        display_caixa("Assets/Login/login1.txt", DEFAULT);

        std::cout << "                                $: ";
        std::cin >> nome;

        limpar_buffer();

        // RETURN CASO NOME = --SAIR
        if(nome=="--sair")
        {
            display_caixa("Assets/Login/logincancel.txt", DEFAULT);
            botao_enter();

            return "false";
        }
        // ENTRADA DA SENHA
        display_caixa("Assets/Login/login2.txt", DEFAULT);

        std::cout << "                                $: ";
        std::cin >> senha;

        limpar_buffer();

        // RETURN CASO SENHA = --SAIR
        if(senha=="--sair")
        {
            display_caixa("Assets/Login/logincancel.txt", DEFAULT);
            botao_enter();

            return "false";
        }

        //VERIFICA-SE A EXISTENCIA DO USUARIO
        if(match_log(nome))
        {
            //ABERTURA DO PASSWORD.TXT NA PASTA DO USUARIO
            read_pass.open(("Data/" + nome + "/password.txt").c_str(), std::ios::in);
            if(!read_pass)
            {
                display_caixa("Assets/Login/loginerror1.txt", RED);
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

                    display_caixa("Assets/Login/loginsuccess.txt", GREEN);
                    botao_enter();

                    return nome;
                }
                else
                {   //CASO AS SENHAS NAO COINCIDAM
                    nome.clear();
                    senha.clear();
                    senha_cmpr.clear();
                    read_pass.close();

                    display_caixa("Assets/Login/loginerror2.txt", RED);
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

            display_caixa("Assets/Login/loginerror2.txt", RED);
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
        display_caixa("Assets/Registro/registro0.txt", DEFAULT);
        botao_enter();

        while (true)
        {
            //Definindo nome
            display_caixa("Assets/Registro/registro1.txt", DEFAULT);

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
                display_caixa("Assets/Registro/registrocancel.txt", DEFAULT);
                botao_enter();

                return;
            }

            read_log.open("Data/log.txt", std::ios::in);

            if (read_log)
            {
                if (match_log(nome))
                {
                    display_caixa("Assets/Registro/registroerror3.txt", RED);
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

        //Definindo senha
        display_caixa("Assets/Registro/registro2.txt", DEFAULT);

        std::cout << "                                $: ";
        std::cin  >> senha;

        limpar_buffer();

        if (senha == "--sair")
        {
            display_caixa("Assets/Registro/registrocancel.txt", DEFAULT);
            botao_enter();

            return;
        }

        display_caixa("Assets/Registro/registro3.txt", DEFAULT);

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

    display_caixa("Assets/Registro/registrosuccess.txt", GREEN);
    botao_enter();
}
