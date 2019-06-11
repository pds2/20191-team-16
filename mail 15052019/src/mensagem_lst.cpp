#include "mensagem_lst.h"

#include <string>
#include <vector>
#include <iostream>

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
    std::cout << "\nPor favor, " << get_desti() << ", cumpra os seguintes itens da lista:\n" <<std::endl;
	for (unsigned int i = 0; i < _lista.size(); i++)
		std::cout << i + 1 << ") " << _lista[i] << std::endl;
}

void Mensagem_lst::escrever_msg()
{
	//Funcao para escrever os itens da lista
	//Pede-se ao usuario que entre com os itens desejados
	//Para parar o loop da entrada, deve-se digitar --ok
    std::string items;
    
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
	return;
}
