#include <string>
#include <fstream>
#include <iostream>
#include <vector>

void limpa_buffer()
{
    std::cin.clear();
    std::cin.ignore(10000,'\n');
}

bool match_log_(std::string nome2)
{
    std::fstream read_log;
    read_log.open("Data/log.txt", std::ios::in);
    std::string compr;
    while (true) {
        read_log >> compr;
        
        if (read_log.eof()) 
            break;
        if (nome2 == compr) {
            read_log.close();
            return true;
        }
        else 
            compr.clear();
    }
    read_log.close();
    return false;
}

void set_user(std::string nome, std::string nome2) 
{
    //modificar o nome do user no log.txt
    std::fstream rewrite_log;
    rewrite_log.open("Data/log.txt", std::ios::in );
    std::vector<std::string> vetor;
    std::string compr;
    while (true) {
        rewrite_log >> compr;            
        if (rewrite_log.eof()) 
            break;
        if (nome == compr) 
            vetor.push_back(nome2);
        if (nome != compr) 
            vetor.push_back(compr);
        else compr.clear();
    }
    rewrite_log.close();
    rewrite_log.open("Data/log.txt", std::ios::out | std::ios::trunc);
    for (int i=0;i<vetor.size();i++)
    rewrite_log << vetor[i] << std::endl;
    rewrite_log.close();
    
    //modificar o nome do diretório do usuário
    system(("mv Data/" + nome + "/ Data/" + nome2 + "/").c_str());
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
    remove_log.open("Data/log.txt", std::ios::in );
    std::vector<std::string> vet;
    std::string compr;
    while (true) { 
        remove_log >> compr;
        if (remove_log.eof()) 
            break;
        if (nome != compr)
            vet.push_back(compr);
        else 
            compr.clear();
    }
    remove_log.close();
    remove_log.open("Data/log.txt", std::ios::out | std::ios::trunc);
    for (int i=0;i<vet.size();i++)
        remove_log << vet[i] << std::endl;
    remove_log.close();
    exit(0);
}

void configurar(std::string nome)
{
    std::cout << "\nConfiguracao de conta"<<std::endl;
    int opcao;
    while (true)
    {
        std::cout << "\nDigite o numero de uma das opcoes abaixo:" <<std::endl;
        std::cout <<"\n1#Alterar nome de usuário\n2#Alterar senha\n3#Deletar conta\n4#voltar ao hub" <<std::endl;       
        std::cin >> opcao;
        switch (opcao)
        {
            case 1: { //alterar nome de usuario
                std::string nome2;
                std::fstream read_log;

                while (true) {
                    std::cout << "\nDefina o seu novo nome de usuario: ";
                    std::cin >> nome2;
                    limpa_buffer();
                    if(match_log_(nome2)) {
                        std::cout << "\nSinto muito, esse nome de usuario ja existe :(." << std::endl;
                        continue;
                    }
                    else {
                        char resp;
                        std::cout <<"\nDeseja realmente mudar seu nome de usuario?" << std::endl;
                        std::cout <<"\nDigite [S] se sim ou [N] caso contrario" << std::endl;
                        std::cin >> resp;
                        limpa_buffer();
                        if(resp == 's' || resp == 'S') {
                            set_user(nome, nome2);
                            std::cout <<"\nNome de usuario alterado com sucesso!" <<std::endl;
                            std::cout <<"\nO que deseja fazer agora?" <<std::endl;
                        }
                        else if(resp == 'n' || resp == 'N') {
                            std::cout <<"\nO que deseja fazer?" <<std::endl;
                        }
                        else {
                            std::cout << "\nopcao invalida" << std::endl;
                            continue;
                        }
                    }
                    break;
                }
            break;
            }
            case 2: { //alterar senha
                std::string senha;
                while (true) {
                    std::cout << "Digite o nome da nova senha: ";
                    std::cin >> senha;
                    limpa_buffer();
                    char resp;
                    std::cout <<"\nDeseja realmente mudar sua senha?" << std::endl;
                    std::cout <<"\nDigite [S] se sim ou [N] caso contrario" << std::endl;
                    std::cin >> resp;
                    limpa_buffer();
                    if(resp == 's' || resp == 'S') {
                        set_password(nome, senha);
                        std::cout <<"\nSenha alterada com sucesso!" <<std::endl;
                        std::cout <<"\nO que deseja fazer agora?" <<std::endl;
                    }
                    else if(resp == 'n' || resp == 'N') {
                        std::cout <<"\nO que deseja fazer?" <<std::endl;
                    }
                    else {
                        std::cout << "\nopcao invalida" << std::endl;
                        continue;
                    }
                break;
                }
            break;
            }
            case 3: //deletar conta
            {
                char resp1;
                while (true) {
                    std::cout <<"\nDeseja realmente deletar sua conta?" << std::endl;
                    std::cout <<"\nDigite [S] se sim ou [N] caso contrario" << std::endl;
                    std::cin >> resp1;
                    if(resp1 == 's' || resp1 == 'S') {
                        del_conta(nome);
                        std::cout <<"\nConta deletada com sucesso!" <<std::endl;
                    }
                    else if(resp1 == 'n' || resp1 =='N') {
                        std::cout <<"\nO que deseja fazer?" <<std::endl;
                    }
                    else {
                        std::cout << "\nopcao invalida" << std::endl;
                        continue;
                    }
                    break;
                }
            break;
            }
            case 4: // voltar ao hub
            {
                exit(0);
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
