#ifndef SUB_CLASS_MENSAGEM_TAB_H
#define SUB_CLASS_MENSAGEM_TAB_H

#include "mensagem.h"

#include <string>
#include <vector>
#include <fstream>

class Mensagem_tab : public Mensagem {

private:

	std::vector <std::vector <std::string> > tab;

public:

	//Construtor
	Mensagem_tab(std::fstream email);

	//Destrutor
	~Mensagem_tab();

	//Metodos
	void exibir_msg() override;
	void escrever_msg() override;
};

#endif
