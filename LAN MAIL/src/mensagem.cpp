#include "gerais.h"
#include "mensagem.h"

#include <string>
#include <fstream>
#include <iostream>

#include <time.h>

//Posicao de corte para a string data
#define SPLIT   8
//Numero de digitos para representar o ano AAAA
#define ANODGT  4
//Numero de digitos para representar medidas de tempo exceto o ano
#define ANYDGT  2

#define GAPSIZE 58

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

void Mensagem::exibir_cabe()
{
    /*Caso a mensagem antes tenha sido categorizada como nao lida, el deve ser
      recategorizada como lida*/
    if (_lido == 0)
    {
        _lido = 1;
    }

    std::cout << " ==============================================================================" << std::endl;

    std::cout << " = Remetente      : " << _remet << ajust_string(_remet, GAPSIZE) << "=" << std::endl;

    std::cout << " = Destinatario   : " << _desti << ajust_string(_desti, GAPSIZE) << "=" << std::endl;

    std::cout << " = Data de emissao: " << get_string_hora(std::to_string(_data)) << " "
                                        << get_string_dia (std::to_string(_data))

                                        << ajust_string(get_string_hora(std::to_string(_data) + " "
                                         +              get_string_dia (std::to_string(_data))), GAPSIZE)
                                        << "=" << std::endl;

    std::cout << " = Assunto        : " << _assun << ajust_string(_assun, GAPSIZE) << "=" << std::endl;

    std::cout << " ==============================================================================" << std::endl;
}

void Mensagem::delete_msg()
{
    //Place Holder
}

void Mensagem::enviar_msg()
{
    //Place Holder
}
