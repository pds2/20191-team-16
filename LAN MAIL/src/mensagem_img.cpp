#include "gerais.h"
#include "mensagem_img.h"
#include <fstream>
#include <vector>
#include <string>
#include <iostream>

//Construtor
Mensagem_img::Mensagem_img
(std::string file , short lido       , long data,
 std::string remet, std::string desti,
 std::string assun, std::vector <std::string> imagem) :

Mensagem(file, lido, data, remet, desti, assun),

_imagem(imagem) {}

//Getters
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

/*void Mensagem_img::escrever_msg(std::string nome)
{
	//Funcao para escolher a mensagem a ser enviada
	//Pede-se ao usuario para entrar com um numeral
	//Que corresponde ao indice das imagens e armazena-o
	//Na string escolha
	//Caso a entrada esteja incorreta, limpa-se a string
	//E pede-se uma nova entrada
	std::string escolha;
	std::fstream arq;

	std::cout << "\n[Escolha a imagem desejada digitando o indice correspondente:]" << std::endl;
	std::cout << "[0].Mario " << std::endl;
	std::cout << "[1].Boo " << std::endl;
	std::cout << "[2].Careta " << std::endl;
	while(true){
		std::cout << "[Qual a sua escolha?]" << std::endl;
		std::cin >> escolha;
		if(escolha == "0"){
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
		else if(escolha == "1"){
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
		else if(escolha == "2"){
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
		else{
			escolha.clear();
			std::cout << "[Indice Invalido: escolha entre 0, 1 ou 2]" << std::endl;
			std::cout << "[0].Mario " << std::endl;
			std::cout << "[1].Boo " << std::endl;
			std::cout << "[2].Careta " << std::endl;
			continue;
		}

	}

	std::string _file = std::to_string(_data);
	arq.open(("Data/"+ nome +"/outbox/log_out.txt").c_str(), std::ios::app | std::ios::out);
	arq << _file << " 4\n";
	arq.close(); 

	system(("touch Data/" + nome + "/outbox/" + _file + ".txt").c_str());
	arq.open(("Data/" + nome + "/outbox/" + _file + ".txt").c_str(), std::ios::out);
	arq << _lido << "\n";
	arq << _file << "\n";
	arq << _data << "\n";
	arq << _remetente << "\n";
	arq << _destinatario << "\n";
	arq << _assunto << "\n";
	arq << _imagem << "\n";
	arq.close();

	return;
}*/
