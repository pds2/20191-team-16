#include "gerais.h"
#include "mensagem_cvt.h"

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

void Mensagem_cvt::escrever_msg()
{
	//Place Holder
}
