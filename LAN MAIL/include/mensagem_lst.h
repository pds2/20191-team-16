#ifndef SUB_CLASS_MENSAGEM_LST_H
#define SUB_CLASS_MENSAGEM_LST_H

#include "mensagem.h"

#include <string>
#include <vector>

class Mensagem_lst : public Mensagem {

private:

    //Tarefa do qual se trata a lista
    std::string _tarefa;

    //Lista de elementos da tarefa em questao
	std::vector <std::string> _lista;

public:

	//Construtor
	Mensagem_lst(std::string file , short lido        , long data,
				 std::string remet, std::string desti ,
				 std::string assun, std::string tarefa,
				 std::vector <std::string> lista);

    //Getters
    std::string get_tarefa();
    std::vector <std::string> get_lista();

	//Metodos
	void exibir_msg()   override;
	void escrever_msg(std::string) override;
};

#endif
