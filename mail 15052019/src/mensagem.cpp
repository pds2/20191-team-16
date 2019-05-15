#include "mensagem.h"

#include <string>

//Construtor
Mensagem::Mensagem()
{
    //Place Holder
}

//Destrutor
Mensagem::~Mensagem()
{
    //Place Holder
}

//Getters
int Mensagem::get_data()
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
void Mensagem::set_data(/* Place Holder */)
{
    /*Essa funcao vai pegar o horario do relogio do OS e passar para um
      inteiro no formato [AAAAMMDDHHMM], diferentemente dos outros setters */

    //Place Holder
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

void Mensagem::delete_msg()
{
    //Place Holder
}

void Mensagem::enviar_msg()
{
    //Place Holder
}