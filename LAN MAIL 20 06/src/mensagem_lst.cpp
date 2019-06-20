#include "gerais.h"
#include "mensagem_lst.h"

#include <string>
#include <vector>
#include <iostream>

//Valor do espacao disponivel para escrita no progrma (80 - 6(espaco das bordas))
#define GAPSIZE 74

#define NUMLINHAS 20

/*Valor que determina quantos termos anteriores de um inserimento devem ser mostrados
  durante um processo de ecrita de mensagem*/
#define ANTERIOR 5

//Espaco fixo ocupado pelas primeiras 3 linhas da funcao de exibir
#define LINHA1SIZE 58
#define LINHA2SIZE 10
#define LINHA3SIZE  2

//Valor da cor dos textos para a funcao display_caixa
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define DEFAULT "\033[m"

//Construtor--------------------------------------------------------------------
Mensagem_lst::Mensagem_lst(std::string file  , short lido       , long data,
                           std::string remet , std::string desti, std::string assun,
                           std::string tarefa, std::vector <std::string> lista) :

Mensagem(file, lido,  data, remet, desti, assun), _tarefa(tarefa), _lista(lista) {}

//Submetodos--------------------------------------------------------------------
short Mensagem_lst::salvar_msg_extra(std::fstream &msg)
{
    msg << _tarefa << std::endl;

    for (unsigned int i = 0; i < _lista.size(); i++)
        msg << _lista[i] << std::endl;

    msg.close();

    return 1;
}

//Getters-----------------------------------------------------------------------
std::string Mensagem_lst::get_tarefa()
{
    return _tarefa;
}

std::vector <std::string> Mensagem_lst::get_lista()
{
    return _lista;
}

//Metodos-----------------------------------------------------------------------
void Mensagem_lst::exibir_msg()
{
    exibir_cabe();

    std::cout << " = Por favor, " << get_desti() << ", cumpra os seguintes itens da lista referentes"
              << ajust_string(get_desti().size() + LINHA1SIZE, GAPSIZE) << " =" << std::endl;

    std::cout << " = a tarefa " << _tarefa << ":"
              << ajust_string(_tarefa.size() + LINHA2SIZE, GAPSIZE) << " =" << std::endl;

    std::cout << " = " << ajust_string(0, GAPSIZE) << " =" << std::endl;

	for (unsigned int i = 0; i < _lista.size(); i++)
        std::cout << " = " << i + 1 << ") " << _lista[i] << ajust_string(_lista[i].size() + 2, GAPSIZE) << "=" << std::endl;

    std::cout << " ==============================================================================" << std::endl;
}

bool Mensagem_lst::escrever_msg()
{
	//Funcao para escrever os itens da lista
	//Pede-se ao usuario que entre com os itens desejados
	//Para parar o loop da entrada, deve-se digitar --ok
    std::string items;
    
	display_caixa("Assets/Write/Lst/lst2.txt", DEFAULT);

	while(true){
	    std::getline(std::cin, items);
	    if(items == "--ok"){
	        break;
	    }
	    else{
	        _lista.push_back(items);
		items.clear();
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
