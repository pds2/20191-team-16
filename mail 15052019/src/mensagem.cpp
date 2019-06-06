#include "mensagem.h"

#include <string>
#include <fstream>
#include <iostream>

//Construtor
Mensagem::Mensagem
(std::string file  , short lido, long data,
 std::string remet , std::string desti,
 std::string assun) :

_file(file)  , _lido(lido)  , _data(data),
_remet(remet), _desti(desti),
_assun(assun) {}

//Getters
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

//Setters

void Mensagem::set_lido(short lido)
{
    _lido = lido;
}
void Mensagem::set_data(/* Place Holder */)
{
    /*Essa funcao vai pegar o horario do relogio do OS e passar para um
      inteiro no formato [AAAAMMDDHHMMSS], diferentemente dos outros setters */

    time_t now;
    struct tm *timeinfo;
    char dataTime[14];
    long data;
    
    now = time(NULL);
    timeinfo = localtime(&now);
    strftime (dataTime, 14, "%Y%m%d%H%M%S",timeinfo);
    data = atol(dataTime);
    
    *_data = data;
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

//Metodos

void Mensagem::exibir_msg()
{
    std::cout << "Ok!" << std::endl;
}

void Mensagem::delete_msg()
{
    //Place Holder
}

void Mensagem::enviar_msg()
{
    //Place Holder
}
