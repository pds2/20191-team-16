#include "mensagem_gnr.h"

#include <string>
#include <vector>
#include <fstream>
#include <iostream>

//Construtor
Mensagem_gnr::Mensagem_gnr
(std::string file ,short lido        , long data,
 std::string remet, std::string desti,
 std::string assun, std::vector <std::string> texto) :

Mensagem(file, lido, data, remet, desti, assun),

_texto(texto) {}

//Getters
std::vector <std::string> Mensagem_gnr::get_texto()
{
    return _texto;
}

//Metodos
void Mensagem_gnr::exibir_msg()
{
	for (unsigned int i = 0; i < _texto.size(); i++)
		std::cout << _texto[i] << std::endl;
}

void Mensagem_gnr::escrever_msg()
{
	//Place Holder
}
