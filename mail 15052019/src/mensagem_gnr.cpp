#include "mensagem_gnr.h"

#include <string>
#include <vector>
#include <fstream>

//Construtor
Mensagem_gnr::Mensagem_gnr(std::string target, std::string user, std::string box) : 
Mensagem(target, user, box)
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
void Mensagem_cvt::exibir_msg()
{
	//Place Holder
}

void Mensagem_cvt::escrever_msg()
{
	//Place Holder
}

