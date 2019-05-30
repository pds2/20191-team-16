#include "mensagem_gnr.h"

#include <string>
#include <vector>
#include <fstream>
#include <iostream>

//Construtor
Mensagem_gnr::Mensagem_gnr(std::string user, std::string box, std::string target) : 
Mensagem(user, box, target)
{
	std::string linha;

	while (!_mail.eof())
	{
		std::getline(_mail, linha);

		_texto.push_back(linha);

		linha.clear();
	}

	_mail.close();
}

//Destrutor
Mensagem_gnr::~Mensagem_gnr()
{
	//Place Holder
}

//Metodos
void Mensagem_gnr::exibir_msg()
{
	for (int i = 0; i < _texto.size(); i++)
		std::cout << _texto[i] << std::endl;
}

void Mensagem_gnr::escrever_msg()
{
	//Place Holder
}

