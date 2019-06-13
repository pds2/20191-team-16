#include "gerais.h"
#include "mensagem_gnr.h"

#include <string>
#include <vector>
#include <fstream>
#include <iostream>

#define GAPSIZE 74

//Construtor
Mensagem_gnr::Mensagem_gnr
(std::string file ,short lido        , long data,
 std::string remet, std::string desti,
 std::string assun, std::vector <std::string> texto) :

Mensagem(file, lido, data, remet, desti, assun),

_texto(texto) {}

//Getters
std::vector <std::string> Mensagem_gnr::get_texto()
{
    return _texto;
}

//Metodos
void Mensagem_gnr::exibir_msg()
{
    exibir_cabe();

	for (unsigned int i = 0; i < _texto.size(); i++)
        std::cout << " = " << _texto[i] << ajust_string(_texto[i], GAPSIZE) << " = " << std::endl;

    std::cout << " ==============================================================================" << std::endl;
}

/*void Mensagem_gnr::escrever_msg(std::string nome)
{
	//Funcao para escrever uma mensagem generica
	//Pede-se para o usuario escrever a mensagem
	//Desejada na entrada(loop).
	//Para parar o loop da entrada, digita-se --ok
	std::string linhas;
	std::fstream arq;
	int numberoflines = 0;

	std::cout << "[Digite a mensagem a ser enviada:]" << std::endl;
	std::cout <<"[Digite --ok para parar]" << std::endl;

	while(getline(std::cin,linhas)){
	    if(linhas == "--ok"){
	        break;
	    }
	    else{
	        _texto.push_back(linhas);
	        numberoflines++;
	        continue;
	    }
	}

	if(numberoflines < 20){
		for(int i = 1; i <= 20 - numberoflines; i++){
			_texto.push_back("\n");
		}
	}

	std::string _file = std::to_string(_data);
	arq.open(("Data/"+ nome +"/outbox/log_out.txt").c_str(), std::ios::app | std::ios::out);
	arq << _file << " 0\n";
	arq.close(); 

	system(("touch Data/" + nome + "/outbox/" + _file + ".txt").c_str());
	arq.open(("Data/" + nome + "/outbox/" + _file + ".txt").c_str(), std::ios::out);
	arq << _lido << "\n";
	arq << _file << "\n";
	arq << _data << "\n";
	arq << _remetente << "\n";
	arq << _destinatario << "\n";
	arq << _assunto << "\n";
	arq << _texto << "\n";
	arq.close();

	return;
}*/
