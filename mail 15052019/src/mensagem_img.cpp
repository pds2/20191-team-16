#include "mensagem_img.h"

#include <fstream>
#include <iostream>

//Construtor
Mensagem_img::Mensagem_img(std::string user, std::string box, std::string target) :
Mensagem(user, box, target)
{
	std::string linha;

	while (!_mail.eof())
	{
		std::getline(_mail, linha);

		_imagem.push_back(linha);

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
	for (int i = 0; i < _imagem.size(); i++)
	{
		for (int j = 0; j < _imagem[i].size(); j++)
		{	//Esquema de cor para pixel Preto
			if      (_imagem[i][j] == '0') std::cout << "\033[0;30;40m";

			//Esquema de cor para pixel Vermelho
			else if (_imagem[i][j] == '1') std::cout << "\033[0;31;41m";

			//Esquema de cor para pixel Verde 
			else if (_imagem[i][j] == '2') std::cout << "\033[0;32;42m";

			//Esquema de cor para pixel Amarelo
			else if (_imagem[i][j] == '3') std::cout << "\033[0;33;43m";

			//Esquema de cor para pixel Azul
			else if (_imagem[i][j] == '4') std::cout << "\033[0;34;44m";

			//Esquema de cor para pixel Roxo
			else if (_imagem[i][j] == '5') std::cout << "\033[0;35;45m";

			//Esquema de cor para pixel Ciano
			else if (_imagem[i][j] == '6') std::cout << "\033[0;36;46m";

			//Esquema de cor para pixel Branco
			else if (_imagem[i][j] == '7') std::cout << "\033[0;37;47m";
			
			//Preencher com o fundo do terminal espacos vazios
			else if (_imagem[i][j] == ' ') std::cout << "\033[m";

			//Imprimindo o "pixel"
			std::cout << _imagem[i][j] << "\033[m";
		}

		//Pular para a proxima linha
		std::cout << "\n";
	}
}

void Mensagem_img::escrever_msg()
{
	//Place Holder
}
