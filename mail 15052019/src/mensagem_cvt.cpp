#include "mensagem_cvt.h"
#include <fstream>
#include <string>
#include <iostream>

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
	std::cout << "Caro " << get_desti() << "," << std::endl;

	std::cout << "\nO(A) anfitriao(a), " << _anfit << ", convida " << _convi << " para o evento" << std::endl;
	std::cout << _event << " no local " << _lugar << "," << std::endl;
	std::cout << "na data " << _dataevt << std::endl;

	std::cout << "\nEspera-se por sua presenca" << std::endl;
}

void Mensagem_cvt::escrever_msg()
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
}
