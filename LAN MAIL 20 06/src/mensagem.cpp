#include "gerais.h"
#include "mensagem.h"

#include <string>
#include <vector>
#include <fstream>
#include <iostream>

#include <time.h>

//Posicao de corte para a string data
#define SPLIT   8
//Numero de digitos para representar o ano AAAA
#define ANODGT  4
//Numero de digitos para representar medidas de tempo exceto o ano
#define ANYDGT  2

/*Valor do espacao disponivel para escrita no cabecario (80 - espaco anterior aos ":"
  na funcao de exibir cabecario*/
#define GAPSIZE 58

//Soma dos valores de ocupcao de espaco do retorno das funcoes get_string_dia e get_string_hora
#define DATASIZE 19

/*Valor que determina quantos termos anteriores de um inserimento devem ser mostrados
  durante um processo de ecrita de mensagem*/
#define ANTERIOR 5

//Valor da cor dos textos para a funcao display_caixa
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define DEFAULT "\033[m"

//Construtor--------------------------------------------------------------------
Mensagem::Mensagem
(std::string file  , short lido, long data,
 std::string remet , std::string desti,
 std::string assun) :

_file(file)  , _lido(lido)  , _data(data),
_remet(remet), _desti(desti),
_assun(assun) {}

//Getters-----------------------------------------------------------------------
short Mensagem::get_lido()
{
    return _lido;
}

long Mensagem::get_data()
{
    return _data;
}

std::string Mensagem::get_remet()
{
    return _remet;
}

std::string Mensagem::get_desti()
{
    return _desti;
}

std::string Mensagem::get_assun()
{
    return _assun;
}

std::string Mensagem::get_file()
{
    return _file;
}

//Setters
void Mensagem::set_lido(short lido)
{
    _lido = lido;
}
void Mensagem::set_data()
{
    _data = fetch_data();
}
void Mensagem::set_remet(std::string remet)
{
    _remet = remet;
}

void Mensagem::set_desti(std::string desti)
{
    _desti = desti;
}

void Mensagem::set_assun(std::string assun)
{
    _assun = assun;
}

//Submetodos--------------------------------------------------------------------
void Mensagem::exibir_cabe()
{
    /*Caso a mensagem antes tenha sido categorizada como nao lida, el deve ser
      recategorizada como lida*/
    if (_lido == 0)
    {
        _lido = 1;
		
		    salvar_msg(_desti, "inbox", "log_in.txt");
		
		    std::fstream read_log_msg;
	    	read_log_msg.open(("Data/" + _desti + "/" + "inbox" + "/" + "log_in.txt").c_str(), std::ios::in);

	    	bool flag = false;
		
	    	std::string linha;
	    	std::vector <std::string> bloco;
		
		    while (!read_log_msg.eof())
	    	{
	      		std::getline(read_log_msg, linha);
			
	  		if (flag == false)
		  	{
	     			if ((linha == _file + " 0") ||
	      				(linha == _file + " 1") ||
		       			(linha == _file + " 2") ||
			      		(linha == _file + " 3"))
					
				      	flag = true;
		  	}
		  	else 
		    		if ((linha.size() == 0) ||
		      			(linha == _file + " 0") ||
		      			(linha == _file + " 1") ||
		      			(linha == _file + " 2") ||
		      			(linha == _file + " 3"))
			        			continue;

			  bloco.push_back(linha);

			  linha.clear();
		}

		read_log_msg.close();

		std::fstream write_log_msg;
		write_log_msg.open(("Data/" + _desti + "/" + "inbox" + "/" + "log_in.txt").c_str(), std::ios::out);

		for (unsigned int i = 0; i < bloco.size(); i++)
        write_log_msg << bloco[i] << std::endl;

		write_log_msg.close();
    }

    std::cout << " ==============================================================================" << std::endl;

    std::cout << " = Remetente      : " << _remet << ajust_string(_remet.size(), GAPSIZE) << "=" << std::endl;

    std::cout << " = Destinatario   : " << _desti << ajust_string(_desti.size(), GAPSIZE) << "=" << std::endl;

    std::cout << " = Data de emissao: " << get_string_hora(std::to_string(_data)) << " "
                                        << get_string_dia (std::to_string(_data))
                                        << ajust_string(DATASIZE, GAPSIZE) << "=" << std::endl;

    std::cout << " = Assunto        : " << _assun << ajust_string(_assun.size(), GAPSIZE) << "=" << std::endl;

    std::cout << " ==============================================================================" << std::endl;
}

void Mensagem::print_anteriores(unsigned int count ,unsigned int anteriores, std::vector <std::string> bloco)
{
    if (count < anteriores)
        for (unsigned int i = 0; i < bloco.size(); i++)
            std::cout << " " << i + 1 << "): " << bloco[i] << std::endl;
    else
        for (unsigned int i = (bloco.size() - anteriores); i < bloco.size(); i++)
            std::cout << " " << i + 1 << "): " << bloco[i] << std::endl;
}

void Mensagem::salvar_msg(std::string nome, std::string box, std::string log)
{
    std::fstream msg;
    msg.open(("Data/" + nome + "/" + box + "/" + _file).c_str(), std::ios::out);

    msg << _lido  << std::endl;
    msg << _data  << std::endl;
    msg << _remet << std::endl;
    msg << _desti << std::endl;
    msg << _assun << std::endl;

    short flag = salvar_msg_extra(msg);

    std::fstream msg_log;
    msg_log.open(("Data/" + nome + "/" + box + "/" + log).c_str(), std::ios::ate | std::ios::in | std::ios::out);
    msg_log << _file << " " << flag << std::endl;

    msg_log.close();
}

void Mensagem::delete_msg()
{
    //Place Holder
}

void Mensagem::enviar_msg()
{
    unsigned int count = 0;
    std::vector <std::string> destis;

    std::string user;

    while (true)
    {
        display_caixa("Assets/Write/write4.txt", DEFAULT);

        print_anteriores(count, ANTERIOR, destis);

        std::cout << "\n Destinatario[" << count + 1 << "]" << std::endl;
        std::cout << "\n $: ";
        std::getline(std::cin, user);

        if (user == "--sair")
        {
            display_caixa("Assets/Write/writecancel.txt", DEFAULT);
            botao_enter();

            return;
        }

        else if (user == "--ok")
            break;

        else if (user == "--redo")
        {
            count = 0;
            destis.clear();

            user.clear();

            continue;
        }

        if (!match_log(user))
        {
            display_caixa("Assets/Write/writeerror2.txt", RED);
            botao_enter();
        }
        else
        {
            destis.push_back(user);
            count++;
        }

        user.clear();
    }
    //Definindo os dados da mensagem para serem escritos no disco
    _data = fetch_data();

    if (destis.size() == 1)
        _desti = destis[0];
    else
        _desti = destis[0] + "_+_" + std::to_string(destis.size() - 1) + "_pessoas";

    _file = _remet + std::to_string(_data) + ".txt";

    //Salvando a mensagem na outbox do usuario
    salvar_msg(_remet, "outbox", "log_out.txt");
    std::fstream msg_out;

    //Salvando a mensagem na inbox dos destinatarios
    for (unsigned int i = 0; i < destis.size(); i++)
    {
        _desti = destis[i];

        salvar_msg(_desti, "inbox", "log_in.txt");
    }

    display_caixa("Assets/Write/writesuccess.txt", GREEN);
    botao_enter();
}
