#include <string>
#include <fstream>
#include <iostream>

void limpar_buffer()
{
    std::cin.clear();
    std::cin.ignore(10000,'\n');
}

bool match_log(std::string nome2)
{
    std::fstream read_log;
    read_log.open("Data/log.txt", std::ios::in);
    
    std::string compr;
    
    while (true)
    {
        read_log >> compr;
        
        if (read_log.eof()) break;
        
        if (nome2 == compr)
        {
            read_log.close();
            return true;
        }
        else compr.clear();
    }
    
    read_log.close();
    return false;
}

void set_user(std::string nome, std::string nome2) 
{
    //modificar o nome do user no log.txt
    std::fstream rewrite_log;
    rewrite_log.open("Data/log.txt", std::ios::out | std::ios::trunc);
    rewrite_log << nome2 << std::endl;
    rewrite_log.close();

    //modificar o nome do diretório do usuário
    system(("mv Data/" + nome + " Data/" + nome2 ).c_str());
    system(("mv Data/" + nome + "/inbox Data/" + nome2 + "/inbox").c_str());
    system(("mv Data/" + nome + "/outbox Data/" + nome2 + "/outbox").c_str());

    nome = nome2;
}

void set_password(std::string nome, std::string senha)
{
    std::fstream rewrite_pass;
    rewrite_pass.open(("Data/" + nome + "/password.txt").c_str(), std::ios::out | std::ios::trunc);
    rewrite_pass << senha << std::endl;
    rewrite_pass.close();
}

void del_conta(std::string nome)
{
    //Excluindo o diretório do user 
    system(("rm -r Data/" + nome).c_str());

    //Removendo o nome do user do log.txt
    std::fstream remove_log;
    remove_log.open("Data/log.txt", std::ios::out | std::ios::trunc);
    remove_log.close();

    exit(0);
}

void configurar(std::string nome)
{
    std::cout << "\nConfiguracao de conta"<<std::endl;

    int opcao;

    std::cout << "\nDigite o numero de uma das opcoes abaixo:" <<std::endl;
    std::cout <<"\n1#Alterar nome de usuário\n2#Alterar senha\n3#Deletar conta\n4#voltar ao hub" <<std::endl;
                
    std::cin >> opcao;

    while (true)
    {
        switch (opcao)
        {
            case 1: //alterar nome de usuario
            {
                std::string nome2;
                
                bool loop1 = true;

                std::fstream read_log;

                while (loop1)
                {
                    std::cout << "\nDefina o seu novo nome de usuario: ";
                    std::cin >> nome2;

                    limpar_buffer();

                    if(match_log(nome2))
                    {
                        std::cout << "\nSinto muito, esse nome de usuario ja existe :(." << std::endl;
                        continue;
                    }
                    else
                    {
                        char resp;

                        std::cout <<"\nDeseja realmente mudar seu nome de usuario?" << std::endl;
                        std::cout <<"\nDigite [S] se sim ou [N] caso contrario";
                        std::cin >> resp;

                        if(resp == 's' || 'S')
                        {
                            set_user(nome, nome2);
                        }
                        else if(resp == 'n' || 'N')
                        {
                            return;
                        }
                        else
                        {
                            std::cout << "\nopcao invalida" << std::endl;
                        }
                    }
                    loop1 = false;
                }
            break;
            }
            case 2: //alterar senha
            {
                std::string senha;

                bool loop2 = true;

                while (loop2)
                {
                    std::cout << "Digite o nome da nova senha: ";
                    std::cin >> senha;

                    limpar_buffer();

                    if (senha == "--sair")
                    {
                        std::cout << "\nCancelando alteracao de senha..." << std::endl;
                        return;
                    }
                    else
                    {
                        set_password(nome, senha);
                    }
                    loop2 = false;
                }
            break;
            }
            case 3: //deletar conta
            {
                char resp1;

                bool loop3 = true;

                while (loop3)
                {
                    std::cout <<"\nDeseja realmente deletar sua conta?" << std::endl;
                    std::cout <<"\nDigite [S] se sim ou [N] caso contrario";
                    std::cin >> resp1;

                    if(resp1 == 's' || 'S')
                    {
                    del_conta(nome);
                    }
                    else if(resp1 == 'n' || 'N')
                    {
                        break;
                    }
                    else
                    {
                        std::cout << "\nopcao invalida" << std::endl;
                        continue;
                    }
                    loop3 = false;
                }
            break;
            }
            case 4: // voltar ao hub
            {
        
            break;
            }
            default:
            {
                std::cout << "\nopcao invalida" << std::endl;
                continue;
            }
        }
    }
}
