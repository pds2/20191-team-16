#include "gerais.h"
#include "mensagem_lst.h"
#include <fstream>
#include <string>
#include <vector>
#include <iostream>

#define GAPSIZE 74

//Construtor
Mensagem_lst::Mensagem_lst(std::string file  , short lido       , long data,
                           std::string remet , std::string desti, std::string assun,
                           std::string tarefa, std::vector <std::string> lista) :

Mensagem(file, lido,  data, remet, desti, assun), _tarefa(tarefa), _lista(lista) {}

//Getters
std::string Mensagem_lst::get_tarefa()
{
    return _tarefa;
}

std::vector <std::string> Mensagem_lst::get_lista()
{
    return _lista;
}

//Metodos
void Mensagem_lst::exibir_msg()
{
    exibir_cabe();

    std::cout << " = Por favor, " << get_desti() << ", cumpra os seguintes itens da lista referentes"
              << ajust_string(get_desti() + "Por favor, " + ", cumpra os seguintes itens da lista referentes", GAPSIZE)
              << " =" << std::endl;

    std::cout << " = a tarefa " << _tarefa << ":"
              << ajust_string(_tarefa + "a tarefa " + ":", GAPSIZE)
              << " =" << std::endl;

    std::cout << " = "
              << ajust_string("", GAPSIZE) << " ="
              << std::endl;

	for (unsigned int i = 0; i < _lista.size(); i++)
        std::cout << " = " << i + 1 << ") " << _lista[i] << ajust_string(_lista[i] + ") ", GAPSIZE) << "=" << std::endl;

    std::cout << " ==============================================================================" << std::endl;
}

void Mensagem_lst::escrever_msg(std::string nome)
{
	//Funcao para escrever os itens da lista
	//Pede-se ao usuario que entre com os itens desejados
	//Para parar o loop da entrada, deve-se digitar --ok
    std::string items;
    std::fstream arq;
    
	std::cout <<"[\nEscreva os itens da lista:]" << std::endl;
	std::cout <<"[Digite --ok para parar]" << std::endl;

	while(true){
	    items.clear();
	    std::cin >> items;
	    if(items == "--ok"){
	        break;
	    }
	    else{
	        _lista.push_back(items);
	        continue;
	    }
	}

	std::string _file = std::to_string(_data);
	arq.open(("Data/"+ nome +"/outbox/log_out.txt").c_str(), std::ios::app | std::ios::out);
	arq << _file << " 1\n";
	arq.close(); 

	system(("touch Data/" + nome + "/outbox/" + _file + ".txt").c_str());
	arq.open(("Data/" + nome + "/outbox/" + _file + ".txt").c_str(), std::ios::out);
	arq << _lido << "\n";
	arq << _file << "\n";
	arq << _data << "\n";
	arq << _remetente << "\n";
	arq << _destinatario << "\n";
	arq << _assunto << "\n";
	arq << _lista << "\n";
	arq.close();



	return;
}
