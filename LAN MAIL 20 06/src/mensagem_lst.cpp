#include "gerais.h"
#include "mensagem_lst.h"

#include <string>
#include <vector>
#include <iostream>

//Valor do espacao disponivel para escrita no progrma (80 - 6(espaco das bordas))
#define GAPSIZE 74

//Espaco fixo ocupado pelas primeiras 3 linhas da funcao de exibir
#define LINHA1SIZE 58
#define LINHA2SIZE 10
#define LINHA3SIZE  2

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

}
