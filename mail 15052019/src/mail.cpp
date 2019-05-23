#include "mail.h"

#include <string>
#include <fstream>
#include <iostream>

//Construtor
Mail::Mail(bool run)
{
    _run = run;
}

//Destrutor
Mail::~Mail()
{
    //Place holder
}

//Submetodos
void Mail::limpar_buffer()
{
    //Limpa o buffer de entrada do teclado
    std::cin.clear();
    std::cin.ignore(10000,'\n');
}

void Mail::criar_log()
{
    system("mkdir Data");
    system("touch Data/log.txt");
}

bool Mail::scan_nome(std::string nome)
{
    /*Funcao que verifica se a string nao possui
      caracteres que impessam a criacao de diretorios*/

    /*No caso do Linux/Unix (incluindo Mac OS), o unico 
      caractere proibido e o "/" (foward slash) */

    for (unsigned int i = 0; i < nome.size(); i++)
    {
        /*Verificacao de acordo com a tabela ASCII,
          no formato decimal */
        if (nome[i] == 47)
        {
            std::cout << "\n[O nome inserido possui o caractere invalido (/)]" << std::endl;
            return false;
        }
    }

    /*Por coveniencia o numero maximo de caracteres
      permitidos e 20 */

    if (nome.size() > 20)
    {
        std::cout << "\n[O nome inserido extrapolou o limite de 20 caracteres]" << std::endl;
        return false;
    }
    return true;
}

bool Mail::match_log(std::string nome)
{
    //Funcao para achar um nome dentro do log.txt
    
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

void Mail::criar_user(std::string nome, std::string senha)
{
    //Criando os diretorios
    system(("mkdir Data/" + nome).c_str());
    system(("mkdir Data/" + nome + "/inbox ").c_str());
    system(("mkdir Data/" + nome + "/outbox").c_str());

    //Criando os arquivos de texto
    system(("touch Data/" + nome + "/password.txt").c_str());
    system(("touch Data/" + nome + "/inbox/log_in.txt").c_str());
    system(("touch Data/" + nome + "/outbox/log_out.txt").c_str());

    //Escrevendo nos arquivos de texto
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

    /*Criando email de boas vindas W.I.P (Ainda e preciso determinar a forma como
      as mensagens serao salvas no disco e  tambem determinar a funcao que setta 
      a hora de envio da mensagem) */
}

//Metodos
short Mail::init()
{
    //Funcao que oferece as tres opcoes do inicio do programa (Login, Registro, Sair)

    std::cout << "\n[Nome do programa]" << std::endl;

    short esc;

    while (true)
    {
        std::cout << "\n[1]Login"    << std::endl;
        std::cout <<   "[2]Registro" << std::endl;
        std::cout <<   "[3]Sair"     << std::endl;

        std::cout << "\nEscolha: ";
        std::cin  >> esc;

        limpar_buffer();

        if ((esc > 3) || (esc < 1))
        {
            std::cout << "\n[Voce nao escolheu uma das opcoes oferecidas]" << std::endl;
            continue;
        }

        break;
    }
    
    return esc;
}

bool Mail::login()
{
    // Funcao para Login do usuario no sistema de email
    std::string nome;
    std::string senha;
    std::string senha_cmpr; // String para comparar as senhas
    std::fstream read_pass;
    
    while (true)
    {   // Entrada do usuario e senha
        std::cout << "\n[Iniciando processo de Login]\n[Digite --sair para cancelar]" << std::endl;
        std::cout << "\n[Insira o nome de usuario]" << std::endl;
        std::cin >> nome;
        limpar_buffer();
        std::cout << "\n[Insira a senha]" << std::endl;
        std::cin >> senha;
        limpar_buffer();
        if((nome=="--sair") || (senha=="--sair"))
        {
            std::cout << "\n[Cancelando Login]" << std::endl;
            return false;
        }
        // Caso o usuario exista, verifica-se a senha
        if(match_log(nome))
        {
            //Abertura do arquivo password.txt na pasta do usuario
            read_pass.open(("Data/"+ nome +"/password.txt").c_str(), std::ios::in);
            if(!read_pass)
            {
                std::cout << "\n[Arquivo password.txt nao encontrado]" << std::endl;
                exit(0);
            }
            else
            {
                // Comparando a senha registrada com a entrada do usuario
                read_pass >> senha_cmpr;
                if(senha_cmpr == senha)
                {   
                    nome.clear();
                    senha.clear();
                    senha_cmpr.clear();
                    read_pass.close();
                    std::cout << "\n[Login realizado com sucesso]" << std::endl;
                    return true;
                }
                else
                {   
                    nome.clear();
                    senha.clear();
                    senha_cmpr.clear();
                    read_pass.close();
                    std::cout << "\n[Nome de usuario ou senha invalidos]\n[Tente novamente]" << std::endl;
                    continue;
                }
            }
        }
        //Retornando ao inicio do processo caso o usuario não exista
        else
        {  
            nome.clear();
            senha.clear();
            senha_cmpr.clear();
            std::cout << "\n[Nome de usuario ou senha invalidos]\n[Tente novamente]" << std::endl;
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
        std::cout << "\n[Iniciando processo de criacao de conta...     ]" << std::endl;
        std::cout <<   "[Para cancelar, digite --sair em qualquer passo]" << std::endl;

        while (true)
        {
            std::cout << "\n[Criando conta (1/3)]" << std::endl;
            std::cout << "Defina o nome do seu usuario: ";
            std::cin  >> nome;

            limpar_buffer();

            if (!scan_nome(nome))
            {
                nome.clear();
                continue;
            }

            if (nome == "--sair")
            {
                std::cout << "\n[Cancelando processo de registro...]" << std::endl;
                return;
            }

            read_log.open("Data/log.txt", std::ios::in);

            if (read_log)
            {
                if(match_log(nome))
                {
                    std::cout << "\n[Sinto muito, esse nome de usuario ja existe :(]" << std::endl;
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

        std::cout << "\n[Criando conta (2/3)]" << std::endl;
        std::cout << "Agora defina sua senha: ";
        std::cin  >> senha;

        limpar_buffer();

        if (senha == "--sair")
        {
            std::cout << "\n[Cancelando processo de registro... ]" << std::endl;
            return;
        }

        std::cout << "\n(Criando conta [3/3])" << std::endl;

        std::cout << "Nome : " << nome  << std::endl;
        std::cout << "Senha: " << senha << std::endl;

        char *esc = new char;

        std::cout << "\nTem certeza que quer criar uma conta com esses dados?" << std::endl;
        std::cout << "Escolha (([S]im/[N]ao) Default: N): ";
        std::cin  >> *esc;

        limpar_buffer();

        if ((*esc == 'S') || (*esc == 's'))
        {
            delete esc;
            break;
        }
        else
        {
            //Limpando as strings de nome e senha
            nome.clear();
            senha.clear();

            delete esc;
            continue;
        }        
    }
    
    criar_user(nome, senha);

    std::cout << "\n[Usuario criado]" << std::endl;
}
