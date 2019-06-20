#include "gerais.h"
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
#include <cstdio>

//Posicao de corte para a string data
#define SPLIT   8
//Numero de digitos para representar o ano AAAA
#define ANODGT  4
//Numero de digitos para representar medidas de tempo exceto o ano
#define ANYDGT  2

//valor do espaco do "vao" ocupado entre nome e remet na funcao achar_msg()
#define GAPSIZE 23

//Valor do espacao disponivel para escrita no programa (80 - 6(espaco das bordas))
#define GAPSIZE2 74

//Valor da cor dos textos para a funcao display_caixa
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define DEFAULT "\033[m"

//Valor fixo ocupado pela linha de texto da funcao user_status()
#define LINHASTATUSSIZE 54
//Construtor--------------------------------------------------------------------
Sessao::Sessao(std::string nome)
{
    _nome = nome;

    _readbox = "inbox";

    _readlog = "log_in.txt";

    _boxflag = 0;

    _beginbox = 0;

    _endbox = 6;

    _pagina = 1;
}

//Submetodos--------------------------------------------------------------------

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

        if (elemen.size() == 0) continue;

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

        linha.clear();
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

bool Sessao::filtro_msg(Mensagem &msg)
{
    bool filtroflag = false;

    if ((_boxflag == 0)                           ||
       ((_boxflag == 1) && (msg.get_lido() == 0)) ||
       ((_boxflag == 2) && (msg.get_lido() == 1)) ||
       ((_boxflag == 3) && (fetch_data() - msg.get_data() >= 100000000))) filtroflag = true;

    return filtroflag;
}

/*Funcao que acha a posicao do vetor de uma das boxes que condiz com
uma data do vetor _time, para fazer a lisatgem em ordem cronológica*/
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

//Funcao que imprime o display das inbox/outbox
void Sessao::achar_msg(unsigned int i, bool &okflag, long timepos, Mensagem &boxpos)
{
    if (timepos == boxpos.get_data())
    {
        //Linha separadora da caixa exibida
        std::cout << " ============================================================================== " << std::endl;

        std::cout << " = "  << "[" << i << "]" << " "
                  << get_string_hora(std::to_string(boxpos.get_data())) << " "
                  << get_string_dia (std::to_string(boxpos.get_data())) << "   "

                  << boxpos.get_remet() << ajust_string(boxpos.get_remet().size(), GAPSIZE);

                  std::cout << "   ";

        std::cout << boxpos.get_assun() << ajust_string(boxpos.get_assun().size(), GAPSIZE);
        std::cout << "= " << std::endl;

        okflag = true;
    }
}

void Sessao::delete_msg(Mensagem &msg)
{
    //Primeiro deletar o arquivo de texto que contem os dados da mensagem_gnr
    remove(("Data/" + _nome + "/" + _readbox+ "/" + msg.get_file()).c_str());

    //Remover a referencia do arquivo de texto no seu respectivo log_[][].txt

    //Vetor que armazena as linhas do arquivo log_[][].texto
    std::string linha;
    std::vector <std::string> bloco;

    std::fstream read_log_msg;
    read_log_msg.open(("Data/" + _nome + "/" + _readbox+ "/" + _readlog).c_str(), std::ios::in);

    while (!read_log_msg.eof())
    {
        std::getline(read_log_msg, linha);

        if ((linha.size() == 0) ||
           (linha == msg.get_file() + " 0") ||
           (linha == msg.get_file() + " 1") ||
           (linha == msg.get_file() + " 2") ||
           (linha == msg.get_file() + " 3") ||
           (linha == msg.get_file() + " 4"))
           continue;

        bloco.push_back(linha);

        linha.clear();
    }

    read_log_msg.close();

    std::fstream write_log_msg;
    write_log_msg.open(("Data/" + _nome + "/" + _readbox+ "/" + _readlog).c_str(), std::ios::out);

    for (unsigned int i = 0; i < bloco.size(); i++)
        write_log_msg << bloco[i] << std::endl;

    write_log_msg.close();
}

void Sessao::print_msg(Mensagem &msg)
{
    msg.exibir_msg();
}

bool Sessao::escrever_msg(Mensagem &msg)
{
    return msg.escrever_msg();
}

void Sessao::set_user(std::string nome2)
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
        else if (_nome == compr)
            vetor.push_back(nome2);
        else if (_nome != compr)
            vetor.push_back(compr);
        else
            compr.clear();
    }
    rewrite_log.close();
    rewrite_log.open("Data/log.txt", std::ios::out | std::ios::trunc);
    for (unsigned int i = 0; i < vetor.size();i++)
        rewrite_log << vetor[i] << std::endl;
    rewrite_log.close();

    //modificar o nome do diretorio do usuario
    rename (("Data/" + _nome + "/").c_str(), ("Data/" + nome2 + "/").c_str());
    _nome = nome2;
}

void Sessao::set_password(std::string senha)
{
    //modifica a senha no password.txt
    std::fstream rewrite_pass;
    rewrite_pass.open(("Data/" + _nome + "/password.txt").c_str(), std::ios::out | std::ios::trunc);
    rewrite_pass << senha << std::endl;
    rewrite_pass.close();
}

void Sessao::del_conta()
{
    //Excluindo o diretório do user
    remove(("Data/" + _nome).c_str());

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
        else if (_nome != compr)
            vet.push_back(compr);
        else
            compr.clear();
    }
    remove_log.close();
    remove_log.open("Data/log.txt", std::ios::out | std::ios::trunc);
    for (unsigned int i = 0; i < vet.size(); i++)
        remove_log << vet[i] << std::endl;
    remove_log.close();

    exit(0);
}

void Sessao::op1_alt_nome(std::string nome3)
{
    char resp;

    while(true)
    {
        display_caixa("Assets/Config/nome1.txt", DEFAULT);

        std::cout << "                                $: ";
        std::cin >> nome3;

        limpar_buffer();

        if(match_log(nome3))
        {
            display_caixa("Assets/Config/nomeerror.txt", DEFAULT);
            botao_enter();

            continue;
        }
        else
        {
            display_caixa("Assets/Config/nome2.txt", DEFAULT);

            std::cout << "                                $: ";
            std::cin >> resp;

            limpar_buffer();

            if(resp == 's' || resp == 'S')
            {
                set_user(nome3);

                display_caixa("Assets/Config/nomesuccess.txt", DEFAULT);
                botao_enter();
            }
        }
        break;
    }
}

void Sessao::op2_alt_senha(std::string senha)
{
    char resp;

    while (true)
    {
        display_caixa("Assets/Config/senha1.txt", DEFAULT);

        std::cout << "                                $: ";
        std::cin >> senha;
        limpar_buffer();

        display_caixa("Assets/Config/senha2.txt", DEFAULT);

        std::cout << "                                $: ";
        std::cin >> resp;

        limpar_buffer();

        if(resp == 's' || resp == 'S')
        {
            set_password(senha);

            display_caixa("Assets/Config/senhasuccess.txt", DEFAULT);
            botao_enter();
        }
        break;
    }
}

void Sessao::op3_del_conta()
{
    char resp;

    while(true)
    {
        display_caixa("Assets/Config/delete1.txt", DEFAULT);

        std::cout << "                                $: ";
        std::cin >> resp;

        limpar_buffer();

        if(resp == 's' || resp == 'S')
        {
            del_conta();

            display_caixa("Assets/Config/deletesuccess.txt", "\033[m");
            botao_enter();
        }
        break;
    }
}

//Getters-----------------------------------------------------------------------
std::string Sessao::get_nome()
{
    return _nome;
}

std::string Sessao::get_senha()
{
    return _senha;
}

std::string Sessao::get_readbox()
{
    return _readbox;
}

std::string Sessao::get_readlog()
{
    return _readlog;
}

short Sessao::get_boxflag()
{
    return _boxflag;
}

int Sessao::get_time_size()
{
    return _time.size();
}

long Sessao::get_time(unsigned int pos)
{
    return _time[pos];
}

unsigned int Sessao::get_beginbox()
{
    return _beginbox;
}
unsigned int Sessao::get_endbox()
{
    return _endbox;
}

unsigned int Sessao::get_pagina()
{
    return _pagina;
}
unsigned int Sessao::get_paginamax()
{
    return _paginamax;
}

//Setters-----------------------------------------------------------------------
void Sessao::set_nome(std::string nome)
{
    _nome = nome;
}

void Sessao::set_senha(std::string senha)
{
    _senha = senha;
}

void Sessao::set_readbox(std::string readbox)
{
    _readbox = readbox;
}

void Sessao::set_readlog(std::string readlog)
{
    _readlog = readlog;
}

void Sessao::set_boxflag(short boxflag)
{
    _boxflag = boxflag;
}

void Sessao::set_beginbox(unsigned int beginbox)
{
    _beginbox = beginbox;
}
void Sessao::set_endbox(unsigned int endbox)
{
    _endbox = endbox;
}

void Sessao::set_pagina(unsigned int pagina)
{
    _pagina = pagina;
}
void Sessao::set_paginamax(unsigned int paginamax)
{
    _paginamax = paginamax;
}
//Metodos-----------------------------------------------------------------------
void Sessao::set_box()
{
    std::fstream read_log_msg;
    read_log_msg.open(("Data/" + _nome + "/" + _readbox + "/" + _readlog).c_str(), std::ios::in);

    //Arquivo referenciado pelo read_log
    std::string target;
    //Variavel que define o construtor do objeto da mensagem
    short flag;

    std::fstream read_target;

    while (!read_log_msg.eof())
    {
        read_log_msg >> target >> flag;

        if (target.size() == 0) continue;

        //Abrindo um dos arquivos de texto lido por read_log_msg
        read_target.open(("Data/" + _nome + "/" + _readbox + "/" + target).c_str(), std::ios::in);

        //Lendo o cabecario da mensagem
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

void Sessao::user_status()
{
    std::cout << " ============================================================================== " << std::endl;

    std::cout << " = " << "Usuario logado: " << _nome << "                     " << "N. de mensagens: " << std::to_string(get_time_size())
              << ajust_string((LINHASTATUSSIZE + _nome.size() + get_time_size())
               , GAPSIZE2) << "=" << std::endl;

    std::cout << " ============================================================================== " << std::endl;
}

void Sessao::listar_box()
{
    for (unsigned int i = _beginbox; i < _endbox; i++)
    {
        if (i >= _time.size())
        {
            std::cout << " ============================================================================== " << std::endl;
            std::cout << " = [-] --:--:-- --/--/----   -                         -                      = " << std::endl;
        }

        /*Se a flag se tornar verdadeira em um ponto, nao a necessidade
        de escanear as outras boxes para uma mesma posicao de _time*/
        bool okflag = false;

        if (okflag == true) continue;
        else for (unsigned int j = 0; j < _box0.size(); j++)
                achar_msg(i, okflag, _time[i], _box0[j]);

        if (okflag == true) continue;
        else for (unsigned int j = 0; j < _box1.size(); j++)
                achar_msg(i, okflag, _time[i], _box1[j]);

        if (okflag == true) continue;
        else for (unsigned int j = 0; j < _box2.size(); j++)
                achar_msg(i, okflag, _time[i], _box2[j]);

        if (okflag == true) continue;
        else for (unsigned int j = 0; j < _box3.size(); j++)
                achar_msg(i, okflag, _time[i], _box3[j]);

        if (okflag == true) continue;
        else for (unsigned int j = 0; j < _box4.size(); j++)
                achar_msg(i, okflag, _time[i], _box4[j]);
    }

    std::cout << " ============================================================================== " << std::endl;
}

void Sessao::limpar_box(Mensagem &msg)
{
    for (unsigned int i = 0; i < _box0.size(); i++)
        if (_box0[i].get_data() != msg.get_data()) _box0.erase(_box0.begin() + i);

    for (unsigned int i = 0; i < _box1.size(); i++)
        if (_box1[i].get_data() != msg.get_data()) _box1.erase(_box1.begin() + i);

    for (unsigned int i = 0; i < _box2.size(); i++)
        if (_box2[i].get_data() != msg.get_data()) _box2.erase(_box2.begin() + i);

    for (unsigned int i = 0; i < _box3.size(); i++)
        if (_box3[i].get_data() != msg.get_data()) _box3.erase(_box3.begin() + i);

    for (unsigned int i = 0; i < _box4.size(); i++)
        if (_box4[i].get_data() != msg.get_data()) _box4.erase(_box4.begin() + i);
}

//Descarrega os elementos da box da memoria
void Sessao::limpar_box_all()
{
    //Eliminando todos os elementos dessas boxes
    _box0.clear();
    _box1.clear();
    _box2.clear();
    _box3.clear();
    _box4.clear();
    _time.clear();
}

void Sessao::agir_box(long data, short j)
{
    unsigned int maxsize;

    maxsize = _box0.size();

    if (_box1.size() > maxsize) maxsize = _box1.size();
    if (_box2.size() > maxsize) maxsize = _box2.size();
    if (_box3.size() > maxsize) maxsize = _box3.size();
    if (_box4.size() > maxsize) maxsize = _box4.size();

    for (unsigned int i = 0; i < maxsize; i++)
    {
        if ((i < _box0.size()) && (_box0[i].get_data() == data))
        {
            if      (j == 0) delete_msg(_box0[i]);
            else if (j == 1) print_msg (_box0[i]);

            break;
        }
        if ((i < _box1.size()) && (_box1[i].get_data() == data))
        {
            if      (j == 0) delete_msg(_box1[i]);
            else if (j == 1) print_msg (_box1[i]);

            break;
        }
        if ((i < _box2.size()) && (_box2[i].get_data() == data))
        {
            if      (j == 0) delete_msg(_box2[i]);
            else if (j == 1) print_msg (_box2[i]);

            break;
        }
        if ((i < _box3.size()) && (_box3[i].get_data() == data))
        {
            if      (j == 0) delete_msg(_box3[i]);
            else if (j == 1) print_msg (_box3[i]);

            break;
        }
        if ((i < _box4.size()) && (_box4[i].get_data() == data))
        {
            if      (j == 0) delete_msg(_box4[i]);
            else if (j == 1) print_msg (_box4[i]);

            break;
        }
    }
}

void Sessao::config_conta()
{
    int opcao;
    std::string nome3;
    std::string senha;
    std::fstream read_log;

    while (true)
    {
        std::cin >> opcao;
        limpar_buffer();

        switch (opcao)
        {
            case 1:
            {
                op1_alt_nome(nome3);
                break;
            }
            case 2:
            {
                op2_alt_senha(senha);
                break;
            }
            case 3:
            {
                op3_del_conta();
                break;
            }
            case 4:
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

void Sessao::criar_msg()
{
    while (true)
    {
        display_caixa("Assets/Write/write0.txt", DEFAULT);
        botao_enter();

        std::string assun;

        display_caixa("Assets/Write/write1.txt", DEFAULT);
        std::cout << "                                $: ";
        std::getline(std::cin, assun);

        if (assun == "--sair")
        {
            display_caixa("Assets/Write/writecancel.txt", DEFAULT);
            botao_enter();

            break;
        }

        std::string esco;

        display_caixa("Assets/Write/write2.txt", DEFAULT);
        std::cout << "                                $: ";
        std::cin >> esco;
        limpar_buffer();

        if (esco == "0")
        {
            Mensagem_gnr msg("", 0, 0, _nome, "", assun, {});
            if (escrever_msg(msg))
				msg.enviar_msg();
        }
        else if (esco == "1")
        {
            Mensagem_lst msg("", 0, 0, _nome, "", assun, "", {});
            if (escrever_msg(msg))
				msg.enviar_msg();
        }
        else if (esco == "2")
        {
            Mensagem_cvt msg("", 0, 0, _nome, "", assun, "", "", "", "", "");
            if (escrever_msg(msg))
				msg.enviar_msg();
        }
        else if (esco == "3")
        {
            Mensagem_tab msg("", 0, 0, _nome, "", assun, 0, {});
            if (escrever_msg(msg))
				msg.enviar_msg();
        }
        else if (esco == "4")
        {
            Mensagem_img msg("", 0, 0, _nome, "", assun, {});
            if (escrever_msg(msg))
				msg.enviar_msg();
        }
        else if (esco == "--sair")
        {
            display_caixa("Assets/Write/writecancel.txt", DEFAULT);
            botao_enter();

            break;
        }
        else
        {
            display_caixa("Assets/Write/writeerror1.txt", RED);
            botao_enter();
        }

        break;
    }
}
