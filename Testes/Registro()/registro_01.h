#include <string>
#include <fstream>
#include <iostream>

void limpar_buffer()
{
    std::cin.clear();
    std::cin.ignore(10000,'\n');
}

void criar_log()
{
    system("mkdir Data");
    system("touch Data/log.txt");
}

void criar_user(std::string nome, std::string senha)
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

    //Criando email de boas vindas -W.I.P-

    std::cout << "\nUsuario criado com sucesso. Aproveite o LAN MAIL :)" << std::endl;
}

bool match_log(std::string nome)
{
    std::ifstream logtxt;
    logtxt.open("Data/log.txt", std::ios::in);

    std::string compr;

    while (true)
    {
        logtxt >> compr;

        if (logtxt.eof()) break;

        if (nome == compr) return true;
        else compr.clear();
    }

    return false;
}

void registro()
{
    std::cout << "\nIniciando processo de criacao de conta"           <<std::endl;

    std::cout << "\nPara cancelar, digite --sair em qualquer passo" <<std::endl;

    std::string nome;

    bool loop1 = true;

    std::ifstream logtxt;

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

          logtxt.open("Data/log.txt", std::ios::in);

        if (logtxt)
        {
            if(match_log(nome))
            {
                std::cout << "\nSinto muito, esse nome de usuario ja existe" << std::endl;
                logtxt.close();
                continue;
            }
        }
        else criar_log();

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