#include "sessao.h"

#include "mensagem.h"
#include "mensagem_gnr.h"
#include "mensagem_lst.h"
#include "mensagem_cvt.h"
#include "mensagem_tab.h"
#include "mensagem_img.h"

#include <string>
#include <vector>
#include <fstream>
#include <iostream>

//Construtor
Sessao::Sessao(std::string nome)
{
    _nome = nome;

    _boxflag = 0;
}

//Submetodos

//Funcao que carrega os dados especificos de uma mensagem generica
void Sessao::add_msg_gnr(std::string file , short lido, long data, std::string remet,
                         std::string desti, std::string assun, std::fstream &read_target)
{
    //Lendo o conteudo do texto da mensagem generica
    std::vector <std::string> texto;
    std::string linha;

    //Lendo o conteudo do texto em si
    while (!read_target.eof())
    {
        std::getline(read_target, linha);

        texto.push_back(linha);

        linha.clear();
    }

    read_target.close();

    //Criando um objeto mensagem generica com os dados coletados
    Mensagem_gnr x(file, lido, data, remet, desti, assun, texto);

    //Decidindo se joga ou nao o objeto recemcriado nos vetores box0 e time
    if (filtro_msg(x))
    {
        _box0.push_back(x);
        add_msg_time(x.get_data());
    }
}

//Funcao que carrega os dados especificos de uma mensagem em lista
void Sessao::add_msg_lst(std::string file , short lido, long data, std::string remet,
                         std::string desti, std::string assun, std::fstream &read_target)
{
    //Lendo o conteudo do texto da mensagem em lista
    std::string tarefa;
    std::getline(read_target, tarefa);

    std::string linha;
    std::vector <std::string> lista;

    //Lendo a lista de a fazeres do arquivo
    while (!read_target.eof())
    {
        std::getline(read_target, linha);

        if (linha.size() == 0)
        {
            linha.clear();
            continue;
        }

        lista.push_back(linha);

        linha.clear();
    }

    read_target.close();

    //Criando um objeto lista com os dados coletados
    Mensagem_lst x(file, lido, data, remet, desti, assun, tarefa, lista);

    //Decidindo se joga ou nao o objeto recemcriado nos vetores box1 e time
    if (filtro_msg(x))
    {
        _box1.push_back(x);
        add_msg_time(x.get_data());
    }
}

//Funcao que carrega os dados especificos de uma mensagem em convite
void Sessao::add_msg_cvt(std::string file , short lido, long data, std::string remet,
                         std::string desti, std::string assun, std::fstream &read_target)
{
    //Lendo o conetudo do texto da mensagem em convite
    std::string anfit;
    std::string convi;
    std::string lugar;
    std::string event;
    std::string dataevt;

    std::getline(read_target, anfit);
    std::getline(read_target, convi);
    std::getline(read_target, lugar);
    std::getline(read_target, event);
    std::getline(read_target, dataevt);

    read_target.close();

    //Criando um objeto convite com os dados coletados
    Mensagem_cvt x(file , lido , data , remet, desti, assun,
                   anfit, convi, lugar, event, dataevt);

    //Decidindo se joga ou nao o objeto recemcriado nos vetores box2 e time
    if (filtro_msg(x))
    {
        _box2.push_back(x);
        add_msg_time(x.get_data());
    }
}

//Funcao que carrega os dados especificos de uma mensagem em tabela
void Sessao::add_msg_tab(std::string file , short lido, long data, std::string remet,
                         std::string desti, std::string assun, std::fstream &read_target)
{
    //Lendo o conteudo do texto da mensagem em tabela
    short unipl;
    std::vector <std::string> tab;

    std::string elemen;

    read_target >> unipl;

    //lendo os elementos da tabela
    while (!read_target.eof())
    {
        read_target >> elemen;

        tab.push_back(elemen);

        elemen.clear();
    }

    read_target.close();

    //Criando um objeto tabela com os dados coletados
    Mensagem_tab x(file, lido, data , remet, desti, assun, unipl, tab);

    //Decidindo se joga ou nao o objeto recemcriado nos vetores box3 e time
    if (filtro_msg(x))
    {
        _box3.push_back(x);
        add_msg_time(x.get_data());
    }
}

//Funcao que carrega os dados especificos de uma mensagem em imagem
void Sessao::add_msg_img(std::string file , short lido, long data, std::string remet,
                         std::string desti, std::string assun, std::fstream &read_target)
{
    //Lendo o conteudo do texto da mensagem em imagem
    std::vector <std::string> imagem;
    std::string linha;

    //lendo a imagem
    while (!read_target.eof())
    {
        std::getline(read_target, linha);

        imagem.push_back(linha);

        file.clear();
    }

    read_target.close();

    //Criando um objeto imagem com os dados coletados
    Mensagem_img x(file, lido, data , remet, desti, assun, imagem);

    //Decidindo se joga ou nao o objeto recemcriado nos vetores box4 e time
    if (filtro_msg(x))
    {
        _box4.push_back(x);
        add_msg_time(x.get_data());
    }
}

/*Funcao que acha a posicao do vetor de uma das boxes que condiz com
uma data do vetor _time, para fazer a listagem em ordem cronológica*/

void Sessao::add_msg_time(long data)
{
    if (_time.size() == 0) _time.push_back(data);
    else
    {
        /*Se o vetor time tiver elementos e preciso saber qual posicao jogar
          o novo elemento de tempo. Isso e feito com uma comparacao entre da
          tas do novo elemento com todos os ja existentes.*/

        unsigned int count = 0;

        for (unsigned int i = 0; i < _time.size(); i++)
            if (data >= _time[i]) count++;

        _time.insert(_time.end() - count, data);
    }
}

/*Funcao que retona um valor transformado long de data(AAAAMMDDHHMMSS)
  para string(HH:MM:SS DD/MM/AAAA)*/
std::string Sessao::string_data(long data)
{
    //Place Holder
}

//Funcao que imprime o display das inbox/outbox
void Sessao::achar_msg(bool &okflag, long timepos, Mensagem &boxpos)
{

    if (timepos == boxpos.get_data())
    {
        std::cout << "  ============================================================================  " << std::endl;

        std::cout << "  " << boxpos.get_data())  << " " << boxpos.get_remet() << " "
                  << boxpos.get_assun() << std::endl;

        okflag = true;
    }
}


/*Funcao que define se um objeto de mensagem deve ser inserido em sua respectiva box,
  tendo como referencia a variavel _boxflag*/
bool Sessao::filtro_msg(Mensagem &msg)
{
    bool filtroflag = false;

    if ((_boxflag == 0)                           ||
       ((_boxflag == 1) && (msg.get_lido() == 0)) ||
       ((_boxflag == 2) && (msg.get_lido() == 1))) filtroflag = true;

    return filtroflag;
}

void Sessao::limpa_buffer()
{
    //Limpa o buffer de entrada do teclado
    std::cin.clear();
    std::cin.ignore(10000,'\n');
}

bool Sessao::match_log_(std::string nome2)
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

//Getters
std::string Sessao::get_nome()
{
    return _nome;
}

std::string Sessao::get_senha()
{
    return _senha;
}

short Sessao::get_boxflag()
{
    return _boxflag;
}

//Setters
void Sessao::set_nome(std::string nome)
{
    _nome = nome;
}

void Sessao::set_senha(std::string senha)
{
    _senha = senha;
}

void Sessao::set_boxflag(short boxflag)
{
    _boxflag = boxflag;
}

//Metodos

//Descarrega os eleemntos da box da memoria
void Sessao::limpar_box()
{
    //Eliminando todos os elementos dessas boxes
    _box0.clear();
    _box1.clear();
    _box2.clear();
    _box3.clear();
    _box4.clear();
    _time.clear();
}

/*Funcao que escaneia todas as boxes de mensagem em busca de um match com
  todas as posicoes do vetor _time, para que seja possivel listar uma caixa
  (entrada/saida)*/

void Sessao::listar_box()
{
    for (unsigned int i = 0; i < _time.size(); i++)
    {
        /*Se a flag se tornar verdadeira em um ponto, nao a necessidade
        de escanear as outras boxes para uma mesma posicao de _time*/
        bool okflag = false;

        if (okflag == true) continue;
        else for (unsigned int j = 0; j < _box0.size(); j++)
                achar_msg(okflag, _time[i], _box0[j]);

        if (okflag == true) continue;
        else for (unsigned int j = 0; j < _box1.size(); j++)
                achar_msg(okflag, _time[i], _box1[j]);

        if (okflag == true) continue;
        else for (unsigned int j = 0; j < _box2.size(); j++)
                achar_msg(okflag, _time[i], _box2[j]);

        if (okflag == true) continue;
        else for (unsigned int j = 0; j < _box3.size(); j++)
                achar_msg(okflag, _time[i], _box3[j]);

        if (okflag == true) continue;
        else for (unsigned int j = 0; j < _box4.size(); j++)
                achar_msg(okflag, _time[i], _box4[j]);
    }
}

/*Funcao com o proposito geral de carregar todos os arquivos de uma box na memoria
  para permitir acaoes do usuario sobre ela*/
void Sessao::set_box(std::string box, std::string read_log)
{
    std::fstream read_log_msg;
    read_log_msg.open(("Data/" + _nome + "/" + box + "/" + read_log).c_str(), std::ios::in);

    //Arquivo referenciado pelo read_log
    std::string target;
    //Variavel que define o construtor do objeto da mensagem
    short flag;

    std::fstream read_target;

    while (!read_log_msg.eof())
    {
        read_log_msg >> target >> flag;

        //Abrindo um dos arquivos de texto lido pór read_log_msg
        read_target.open(("Data/" + _nome + "/" + box + "/" + target).c_str(), std::ios::in);

        //Lendo o cabecalho da mensagem
        std::string file;

        short lido;
        long  data;
        std::string remet;
        std::string desti;
        std::string assun;

        file = target;

        read_target >> lido;
        read_target >> data;
        read_target >> remet;
        read_target >> desti;

        /*Movendo o cursor uma unidade para direita para o getline
        nao pegar o vazio*/
        read_target.seekg(1 ,std::ios::cur);

        std::getline(read_target, assun);

        /*Definindo como a construção do novo objeto mensagem deve prosseguir,
          de acordo com a variavel flag, lida do arquivo*/
        if (flag == 0)
            add_msg_gnr(file, lido, data, remet, desti, assun, read_target);
        else if (flag == 1)
            add_msg_lst(file, lido, data, remet, desti, assun, read_target);
        else if (flag == 2)
            add_msg_cvt(file, lido, data, remet, desti, assun, read_target);
        else if (flag == 3)
            add_msg_tab(file, lido, data, remet, desti, assun, read_target);
        else if (flag == 4)
            add_msg_img(file, lido, data, remet, desti, assun, read_target);

        //"Anulando" essas variaveis
        flag   = -1;
        target = "null";
    }

    read_log_msg.close();
}

void Sessao::set_user(std::string nome, std::string nome2)
{
    //modifica o nome do user no log.txt
    std::fstream rewrite_log;
    rewrite_log.open("Data/log.txt", std::ios::in );
    std::vector<std::string> vetor;
    std::string compr;
    while (true) 
    {
        rewrite_log >> compr;
        if (rewrite_log.eof())
            break;
        else if (nome == compr)
            vetor.push_back(nome2);
        else if (nome != compr)
            vetor.push_back(compr);
        else
            compr.clear();
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

void Sessao::set_password(std::string nome, std::string senha)
{
    //modifica a senha no password.txt
    std::fstream rewrite_pass;
    rewrite_pass.open(("Data/" + nome + "/password.txt").c_str(), std::ios::out | std::ios::trunc);
    rewrite_pass << senha << std::endl;
    rewrite_pass.close();
}

void Sessao::del_conta(std::string nome)
{
    //Excluindo o diretório do user
    system(("rm -r Data/" + nome).c_str());
    
    //Removendo o nome do user do log.txt
    std::fstream remove_log;
    remove_log.open("Data/log.txt", std::ios::in );
    std::vector<std::string> vet;
    std::string compr;
    while (true) 
    {
        remove_log >> compr;
        if (remove_log.eof()) 
            break;
        else if (nome != compr)
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

//Metodos
void Sessao::clear_box()
{
    //Place Holder
}

void Sessao::listar_box()
{
    //Place Holder
}

void Sessao::config_conta()
{
    int opcao;
    std::string nome2;
    std::string senha;
    std::fstream read_log;
    char resp;
    
    std::cout << "\nConfiguracao de conta"<<std::endl;
    
    while (true)
    {
        std::cout << "\nDigite o numero de uma das opcoes abaixo:" <<std::endl;
        std::cout <<"\n1 Alterar nome de usuário\n2 Alterar senha\n3 Deletar conta\n4 Voltar ao hub" <<std::endl;
        
        std::cin >> opcao;
        
        switch (opcao)
        {
            case 1: //alterar nome de usuario
            {
                while (true)
                {
                    std::cout << "\nDefina o seu novo nome de usuario: ";
                    std::cin >> nome2;
                    limpa_buffer();
                    if(match_log_(nome2))
                    {
                        std::cout << "\nSinto muito, esse nome de usuario ja existe :(." << std::endl;
                        continue;
                    }
                    else
                    {
                        std::cout <<"\nDeseja realmente mudar seu nome de usuario?" << std::endl;
                        std::cout <<"\nDigite [S] se sim ou [N] caso contrario" << std::endl;
                        std::cin >> resp;
                        limpa_buffer();
                        if(resp == 's' || resp == 'S')
                        {
                            set_user(nome, nome2);
                            std::cout <<"\nNome de usuario alterado com sucesso!" <<std::endl;
                            std::cout <<"\nO que deseja fazer agora?" <<std::endl;
                        }
                        else if(resp == 'n' || resp == 'N')
                        {
                            std::cout <<"\nO que deseja fazer?" <<std::endl;
                        }
                        else
                        {
                            std::cout << "\nopcao invalida" << std::endl;
                            continue;
                        }
                    }
                    break;
                }
                break;
            }
            case 2: //alterar senha
            {
                while (true)
                {
                    std::cout << "Digite o nome da nova senha: ";
                    std::cin >> senha;
                    limpa_buffer();

                    std::cout <<"\nDeseja realmente mudar sua senha?" << std::endl;
                    std::cout <<"\nDigite [S] se sim ou [N] caso contrario" << std::endl;
                    std::cin >> resp;
                    
                    limpa_buffer();
                    
                    if(resp == 's' || resp == 'S')
                    {
                        set_password(nome, senha);
                        std::cout <<"\nSenha alterada com sucesso!" <<std::endl;
                        std::cout <<"\nO que deseja fazer agora?" <<std::endl;
                    }
                    else if(resp == 'n' || resp == 'N')
                    {
                        std::cout <<"\nO que deseja fazer?" <<std::endl;
                    }
                    else
                    {
                        std::cout << "\nopcao invalida" << std::endl;
                        continue;
                    }
                    break;
                }
                break;
            }
            case 3: //deletar conta
            {
                while (true)
                {
                    std::cout <<"\nDeseja realmente deletar sua conta?" << std::endl;
                    std::cout <<"\nDigite [S] se sim ou [N] caso contrario" << std::endl;
                    std::cin >> resp;
                    if(resp == 's' || resp == 'S')
                    {
                        del_conta(nome);
                        std::cout <<"\nConta deletada com sucesso!" <<std::endl;
                    }
                    else if(resp == 'n' || resp =='N')
                    {
                        std::cout <<"\nO que deseja fazer?" <<std::endl;
                    }
                    else
                    {
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

