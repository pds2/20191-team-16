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
#define RED     "\033[31m"
#define GREEN   "\033[32m"
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
	//Funcao para escolher a mensagem a ser enviada
	//Pede-se ao usuario para entrar com um numeral
	//Que corresponde ao indice das imagens e armazena-o
	//Na string escolha
	//Caso a entrada esteja incorreta, limpa-se a string
	//E pede-se uma nova entrada
	std::string escolha;
	std::fstream arq;


	while(true){
		display_caixa("Assets/Write/Img/img1.txt", DEFAULT);
		std::cout << "                                $: ";
		std::cin >> escolha;
		limpar_buffer();
		if(escolha == "1"){
			_imagem.push_back("          1111111111            ");
			_imagem.push_back("        111111111111111111      ");
			_imagem.push_back("        00000033330033          ");
			_imagem.push_back("      00330033333300333333      ");
			_imagem.push_back("      0033000033333300333333    ");
			_imagem.push_back("      00003333333300000000      ");
			_imagem.push_back("          33333333333333        ");
			_imagem.push_back("        11114411111111          ");
			_imagem.push_back("      11111144111144111111      ");
			_imagem.push_back("    111111114444444411111111    ");
			_imagem.push_back("    777711443344443344117777    ");
			_imagem.push_back("    777777444444444444777777    ");
			_imagem.push_back("    777744444444444444447777    ");
			_imagem.push_back("        444444    444444        ");
			_imagem.push_back("      000000        000000      ");
			_imagem.push_back("    00000000        00000000    ");
			break;
		}
		else if(escolha == "2"){
			_imagem.push_back("                                ");	                                
			_imagem.push_back("          0000000000            ");
			_imagem.push_back("      000077777777770000        ");
			_imagem.push_back("    0077777777777777777700      ");
			_imagem.push_back("  00777777777777777777777700    ");
			_imagem.push_back("  00770077007777777777777700    ");
			_imagem.push_back("007777007700777777770000777700  ");
			_imagem.push_back("007777777777777777007777007700  ");
			_imagem.push_back("007711771177117777777777007700  ");
			_imagem.push_back("00771111111111777777770077777700");
			_imagem.push_back("00771111111111777777777777777700");
			_imagem.push_back("  007711111111117777777777777700");
			_imagem.push_back("    007777777777777777770000    ");
			_imagem.push_back("      000000777777770000        ");
			_imagem.push_back("            00000000            ");
			_imagem.push_back("                                ");	     
			break;
		}
		else if(escolha == "3"){
			_imagem.push_back("777777777733333333337777777777  ");
			_imagem.push_back("777777333333333333333333777777  ");
			_imagem.push_back("777733333333333333333333337777  ");
			_imagem.push_back("773333333333333333777777333377  ");
			_imagem.push_back("773333333333333377770077773377  ");
			_imagem.push_back("333333333333333377000000773333  ");
			_imagem.push_back("333333000000333377770077773333  ");
			_imagem.push_back("333300333333003333777777333333  ");
			_imagem.push_back("333333333333333333333333333333  ");
			_imagem.push_back("333300000000000000000000003333  ");
			_imagem.push_back("773333000011110011110000333377  ");
			_imagem.push_back("777733333311111111113333337777  ");
			_imagem.push_back("777777333311111111113333777777  ");
			_imagem.push_back("777777777711111111117777777777  ");
			_imagem.push_back("777777777777111111777777777777  ");
			_imagem.push_back("777777777777777777777777777777  ");
			break;
		}
		else if (escolha == "--sair"){
			return false;
		}
		else{
			display_caixa("Assets/Write/Img/imgerror.txt", RED);
			botao_enter();
			escolha.clear();
		}

	}

    display_caixa("Assets/Write/write3.txt", DEFAULT);
    char esc;

    std::cout << "                                $: ";
    std::cin  >> esc;

    limpar_buffer();

    if ((esc == 'S') || (esc == 's'))
    {
        //Funcao de enviar //Ainda nao implementada
        return true;
    }
    else
        return false;
}
