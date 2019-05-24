#include "mensagem_lst.h"

#include <string>
#include <vector>
#include <fstream>

//Construtor
Mensagem_lst::Mensagem_lst(std::string target, std::string user, std::string box) : 
Mensagem(target, user, box)
{
	std::string linha;

	while (!_mail.eof())
	{
		_mail >> linha;

		_texto.push_back(linha);

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
	//Place Holder
}

void Mensagem_lst::escrever_msg()
{
	//Place Holder
}
