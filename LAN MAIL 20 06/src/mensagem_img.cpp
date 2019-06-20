#include "gerais.h"
#include "mensagem_img.h"

#include <vector>
#include <string>
#include <iostream>

//Valores de cor em formato ANSI code dos Pixels
#define P_BLACK  "\033[0;30;40m"
#define P_RED    "\033[0;31;41m"
#define P_GREEN  "\033[0;32;42m"
#define P_YELLOW "\033[0;33;43m"
#define P_BLUE   "\033[0;34;44m"
#define P_PURPLE "\033[0;35;45m"
#define P_CYAN   "\033[0;36;46m"
#define P_WHITE  "\033[0;37;47m"

//Valor de reset para o cor do terminal
#define DEFAULT "\033[m"

//Construtor--------------------------------------------------------------------
Mensagem_img::Mensagem_img
(std::string file , short lido       , long data,
 std::string remet, std::string desti,
 std::string assun, std::vector <std::string> imagem) :

Mensagem(file, lido, data, remet, desti, assun),

_imagem(imagem) {}

//Submetodos--------------------------------------------------------------------
short Mensagem_img::salvar_msg_extra(std::fstream &msg)
{
    for (unsigned int i = 0; i < _imagem.size(); i++)
        msg << _imagem[i] << std::endl;

    msg.close();

    return 4;
}

//Getters-----------------------------------------------------------------------
std::vector <std::string> Mensagem_img::get_imagem()
{
    return _imagem;
}

//Metodos
void Mensagem_img::exibir_msg()
{
    exibir_cabe();

	for (unsigned int i = 0; i < _imagem.size(); i++)
	{
		for (unsigned int j = 0; j < _imagem[i].size(); j++)
		{
            //Esquema de cor para pixel Preto
			if      (_imagem[i][j] == '0') std::cout << P_BLACK;

			//Esquema de cor para pixel Vermelho
			else if (_imagem[i][j] == '1') std::cout << P_RED;

			//Esquema de cor para pixel Verde
			else if (_imagem[i][j] == '2') std::cout << P_GREEN;

			//Esquema de cor para pixel Amarelo
			else if (_imagem[i][j] == '3') std::cout << P_YELLOW;

			//Esquema de cor para pixel Azul
			else if (_imagem[i][j] == '4') std::cout << P_BLUE;

			//Esquema de cor para pixel Roxo
			else if (_imagem[i][j] == '5') std::cout << P_PURPLE;

			//Esquema de cor para pixel Ciano
			else if (_imagem[i][j] == '6') std::cout << P_CYAN;

			//Esquema de cor para pixel Branco
			else if (_imagem[i][j] == '7') std::cout << P_WHITE;

			//Preencher com o fundo do terminal espacos vazios
			else if (_imagem[i][j] == ' ') std::cout << DEFAULT;

			//Imprimindo o "pixel"
			std::cout << _imagem[i][j] << DEFAULT;
		}

		//Pular para a proxima linha
		std::cout << "\n";
	}
}

bool Mensagem_img::escrever_msg()
{
	//Place Holder
}
