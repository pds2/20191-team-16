#ifndef SUB_CLASS_MENSAGEM_LST_H
#define SUB_CLASS_MENSAGEM_LST_H

#include "mensagem.h"

#include <string>
#include <vector>
#include <fstream>

class Mensagem_lst : public Mensagem {

private:

    //Tarefa do qual se trata a lista
    std::string _tarefa;

    //Lista de elementos da tarefa em questao
	std::vector <std::string> _lista;

    //Submetodos
    virtual short salvar_msg_extra(std::fstream &msg);

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
    virtual void exibir_msg();
	virtual bool escrever_msg();
};

#endif
