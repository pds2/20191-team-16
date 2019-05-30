#include "mensagem_lst.h"

#include <string>
#include <vector>
#include <fstream>
#include <iostream>

//Construtor
Mensagem_lst::Mensagem_lst(std::string user, std::string box, std::string target) : 
Mensagem(user, box, target)
{
	std::string linha;

	while (!_mail.eof())
	{
		std::getline(_mail, linha);

		if (linha.size() == 0) continue;

		_lista.push_back(linha);

		linha.clear();
	}

	_mail.close();
}

//Destrutor
Mensagem_lst::~Mensagem_lst()
{
	//Place Holder
}

//Metodos
void Mensagem_lst::exibir_msg()
{
	std::cout << "\nPor favor, " << get_desti() << ", cumpra os seguintes itens da lista:\n" <<std::endl;
	for (int i = 0; i < _lista.size(); i++)
		std::cout << i + 1 << ") " << _lista[i] << std::endl;
}

void Mensagem_lst::escrever_msg()
{
	//Place Holder
}
