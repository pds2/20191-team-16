#include "mensagem_cvt.h"

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
	//Place Holder
}
