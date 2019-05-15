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

bool Mail::match_log(std::string nome)
{
    std::fstream read_log;
    read_log.open("Data/log.txt", std::ios::in);

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
    write_log << nome << std::endl;
    write_log.close();

    std::cout << "\nUsuario criado com sucesso. Aproveite, " << nome << " :)." << std::endl;
}

//Metodos

 short Mail::init()
 {
    //Funcao que oferece as tres opcoes do inicio do programa (Login, Registro, Sair)

    //Place Holder

    return 0;
 }

void Mail::login()
{
    //Place Holder
}

 void Mail::registro()
 {
    std::cout << "\nIniciando processo de criacao de conta..." <<std::endl;
    std::cout << "\nPara cancelar, digite --sair em qualquer passo" <<std::endl;

    std::string nome;

    bool loop1 = true;
    std::fstream read_log;

    while (loop1)
    {
        std::cout << "\nDefina o nome do seu usuario: ";
        std::cin  >> nome;

        limpar_buffer();

        if (nome == "--sair")
        {
            std::cout << "\nCancelando processo de registro..." << std::endl;
            return;
        }

        read_log.open("Data/log.txt", std::ios::in);

        if (read_log)
        {
            if(match_log(nome))
            {
                std::cout << "\nSinto muito, esse nome de usuario ja existe :(." << std::endl;
                read_log.close();
                continue;
            }
        }
        else
        {
            read_log.close();
            criar_log();
        }

        loop1 = false;
    }

    std::string senha;

    bool loop2 = true;
    while (loop2)
    {
        std::cout << "\nAgora defina sua senha: ";
        std::cin  >> senha;

        limpar_buffer();

        if (senha == "--sair")
        {
            std::cout << "\nCancelando processo de registro..." << std::endl;
            return;
        }

        loop2 = false;
    }

    criar_user(nome, senha);
 }