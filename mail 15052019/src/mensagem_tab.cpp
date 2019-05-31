#include "mensagem_tab.h"

#include <string>
#include <vector>
#include <fstream>
#include <iostream>

//Construtor
Mensagem_tab::Mensagem_tab(std::string user, std::string box, std::string target) : 
Mensagem(user, box, target)
{
	_unipl = new short;

	_mail >> *_unipl;

	//Jogando todas os elementos da tabela do arquivo no vector de tabela

	std::string elemen;

	while (!_mail.eof())
	{
		_mail >> elemen;

		_tab.push_back(elemen);

		elemen.clear();
	}

	_mail.close();
}

//Destrutor
Mensagem_tab::~Mensagem_tab()
{
	delete _unipl;
}

//Metodos
void Mensagem_tab::exibir_msg()
{
	short count = 0;

	for (int i = 0; i < _tab.size(); i++)
	{
		if (count == *_unipl)
		{
			if (i == _tab.size() - 1) break;

			std::cout << "\n";
			count = 0;
		}

		std::cout << _tab[i] << " ";
		count++;
	}

	std::cout << "\n";
}

void Mensagem_tab::escrever_msg()
{
	//Place Holder
}
