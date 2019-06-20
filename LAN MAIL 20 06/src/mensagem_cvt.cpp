#include "gerais.h"
#include "mensagem_cvt.h"

#include <string>
#include <iostream>

//Valor do espacao disponivel para escrita no progrma (80 - 6(espaco das bordas))
#define GAPSIZE 74

//Espaco fixo ocupado pelas primeiras 3 linhas da funcao de exibir
#define LINHA1SIZE  6
#define LINHA2SIZE 19
#define LINHA3SIZE 23
#define LINHA4SIZE 12
#define LINHA5SIZE  8
#define LINHA6SIZE 26

//Construtor--------------------------------------------------------------------
Mensagem_cvt::Mensagem_cvt
(std::string file , short lido       , long data          , std::string remet,
 std::string desti, std::string assun, std::string anfit  , std::string convi,
 std::string lugar, std::string event, std::string dataevt) :

Mensagem(file, lido, data, remet, desti, assun),

_anfit  (anfit), _convi(convi),
_lugar  (lugar), _event(event),
_dataevt(dataevt) {}

//Submetodos--------------------------------------------------------------------
short Mensagem_cvt::salvar_msg_extra(std::fstream &msg)
{
    msg << _anfit   << std::endl;
    msg << _convi   << std::endl;
    msg << _lugar   << std::endl;
    msg << _event   << std::endl;
    msg << _dataevt << std::endl;

    msg.close();

    return 2;
}

//Getters-----------------------------------------------------------------------
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

//Metodos-----------------------------------------------------------------------
void Mensagem_cvt::exibir_msg()
{
    exibir_cabe();

	std::cout << " = Caro " <<get_desti() << ","
              << ajust_string(LINHA1SIZE + get_desti().size(), GAPSIZE)<< " =" << std::endl;

    std::cout << " = " << ajust_string(0, GAPSIZE) << " =" << std::endl;

	std::cout << " = O(A) anfitriao(a), " << _anfit
              << ajust_string(LINHA2SIZE + _anfit.size(), GAPSIZE) << " =" << std::endl;

    std::cout << " = convida " << _convi << " para o evento,"
              << ajust_string(LINHA3SIZE + _convi.size(), GAPSIZE) << " =" << std::endl;

	std::cout << " = " <<_event << " no local " << _lugar << ","
              << ajust_string(LINHA4SIZE + _event.size() + _lugar.size(), GAPSIZE) << " =" << std::endl;

	std::cout << " = na data " << _dataevt
              << ajust_string(LINHA5SIZE + _dataevt.size(), GAPSIZE) << " =" << std::endl;

    std::cout << " = " << ajust_string(0, GAPSIZE) << " =" << std::endl;

	std::cout << " = Espera-se por sua presenca"
              << ajust_string(LINHA6SIZE, GAPSIZE)<<" =" << std::endl;;

    std::cout << " ==============================================================================" << std::endl;
}

bool Mensagem_cvt::escrever_msg()
{
	//Place Holder
}
