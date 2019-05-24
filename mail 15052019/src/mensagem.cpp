#include "mensagem.h"

#include <string>
#include <fstream>

//Construtor
Mensagem::Mensagem(std::string target, std::string user, std::string box)
{
    _mail.open(("Data/" + user + "/" + box + "/" + target).c_str(), std::ios::in);

    _data = new int;

    _mail >> *_data;
    _mail >> _remet;
    _mail >> _desti;
    _mail >> _assun;
}

//Destrutor
Mensagem::~Mensagem()
{
    delete _data;
}

//Getters
int Mensagem::get_data()
{
    return *_data;
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
