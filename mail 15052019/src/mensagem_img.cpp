#include "mensagem_img.h"

#include <fstream>

//Construtor
Mensagem_img::Mensagem_img(std::string target, std::string user, std::string box) :
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
Mensagem_img::~Mensagem_img()
{
	//Place Holder
}

//Metodos
void Mensagem_img::exibir_msg()
{
	//Place Holder
}

void Mensagem_img::escrever_msg()
{
	//Place Holder
}
