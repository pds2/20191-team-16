#ifndef SUB_CLASS_MENSAGEM_LST_H
#define SUB_CLASS_MENSAGEM_LST_H

#include "mensagem.h"

#include <string>
#include <vector>
#include <fstream>

class Mensagem_lista : public Mensagem {

private:

	std::vector <std::string> lista;

public:

	//Construtor
	Mensagem_lst(std::string target, std::string user, std::string box);

	//Destrutor
	~Mensagem_lst();

	//Metodos
	void exibir_msg() override;
	void escrever_msg() override;
};

#endif
