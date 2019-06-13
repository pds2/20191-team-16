#include "gerais.h"
#include "mensagem_cvt.h"
#include <fstream>
#include <string>
#include <iostream>

#define GAPSIZE 74

//Construtor
Mensagem_cvt::Mensagem_cvt
(std::string file , short lido       , long data          , std::string remet,
 std::string desti, std::string assun, std::string anfit  , std::string convi,
 std::string lugar, std::string event, std::string dataevt) :

Mensagem(file, lido, data, remet, desti, assun),

_anfit  (anfit), _convi(convi),
_lugar  (lugar), _event(event),
_dataevt(dataevt) {}

//Getters
std::string Mensagem_cvt::get_anfit()
{
    return _anfit;
}

std::string Mensagem_cvt::get_convi()
{
    return _convi;
}

std::string Mensagem_cvt::get_lugar()
{
    return _lugar;
}

std::string Mensagem_cvt::get_event()
{
    return _event;
}

std::string Mensagem_cvt::get_dataevt()
{
    return _dataevt;
}

//Metodos
void Mensagem_cvt::exibir_msg()
{
    exibir_cabe();

	std::cout << " = Caro " <<get_desti() << ","
              << ajust_string("Caro " + get_desti() + ",", GAPSIZE)<< " =" << std::endl;

    std::cout << " = " << ajust_string("", GAPSIZE) << " =" << std::endl;

	std::cout << " = O(A) anfitriao(a), " << _anfit
              << ajust_string("O(A) anfitriao(a), " + _anfit, GAPSIZE) << " =" << std::endl;

    std::cout << " = convida " << _convi << " para o evento"
              << ajust_string("convida " + _convi + " para o evento", GAPSIZE) << " =" << std::endl;

	std::cout << " = " <<_event << " no local " << _lugar << ","
              << ajust_string(_event + " no local " + _lugar + ",", GAPSIZE) << " =" << std::endl;

	std::cout << " = na data " << _dataevt
              << ajust_string("na data " + _dataevt, GAPSIZE) << " =" << std::endl;

    std::cout << " = " << ajust_string("", GAPSIZE) << " =" << std::endl;

	std::cout << " = Espera-se por sua presenca"
              << ajust_string("Espera-se por sua presenca", GAPSIZE)<<" =" << std::endl;;

    std::cout << " ==============================================================================" << std::endl;
}

/*void Mensagem_cvt::escrever_msg(std::string nome)
{	
	//Funcao para escrever a mensagem do tipo convite
	//Pede-se ao usuario que entre com informacoes
	//Que serao utilizadas num modelo pre-feito de convite
	std::fstream arq;

	
	std::cout << "\n[Digite as informações pedidas para criar um convite]" << std::endl;
	std::cout << "[Insira o nome do anfitriao:]" << std::endl;
	std::cin >> _anfit;
	std::cout << "[Insira o nome do convidado:]" << std::endl;
	std::cin >> _convi;
	std::cout << "[Insira o nome do lugar:]" << std::endl;
	std::cin >> _lugar;
	std::cout << "[Insira tipo de evento:]" << std::endl;
	std::cin >> _event;
	std::cout << "[Insira a data do evento:]" << std::endl;
	std::cin >> _dataevt;

	std::string _file = std::to_string(_data);
	arq.open(("Data/"+ nome +"/outbox/log_out.txt").c_str(), std::ios::app | std::ios::out);
	arq << _file << " 2\n";
	arq.close(); 

	system(("touch Data/" + nome + "/outbox/" + _file + ".txt").c_str());
	arq.open(("Data/" + nome + "/outbox/" + _file + ".txt").c_str(), std::ios::out);
	arq << _lido << "\n";
	arq << _file << "\n";
	arq << _data << "\n";
	arq << _remetente << "\n";
	arq << _destinatario << "\n";
	arq << _assunto << "\n";
	arq << _anfit << "\n";
	arq << _convi  << "\n";
	arq << _lugar << "\n";
	arq << _event << "\n";
	arq << _dataevt << "\n";
	arq.close();



	return;
}*/
