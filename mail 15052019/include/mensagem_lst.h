#ifndef SUB_CLASS_MENSAGEM_LST_H
#define SUB_CLASS_MENSAGEM_LST_H

#include "mensagem.h"

#include <string>
#include <vector>
#include <fstream>

class Mensagem_lst : public Mensagem {

private:

	std::vector <std::string> _lista;

public:

	//Construtor
	Mensagem_lst(std::string user, std::string box, std::string target);

	//Destrutor
	~Mensagem_lst();

	//Metodos
	void exibir_msg() override;
	void escrever_msg() override;
};

#endif
