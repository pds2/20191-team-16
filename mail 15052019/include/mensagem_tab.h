#ifndef SUB_CLASS_MENSAGEM_TAB_H
#define SUB_CLASS_MENSAGEM_TAB_H

#include "mensagem.h"

#include <string>
#include <vector>
#include <fstream>

class Mensagem_tab : public Mensagem {

private:

	short *_unipl;

	std::vector <std::string> _tab;

public:

	//Construtor
	Mensagem_tab(std::string user, std::string box, std::string target);

	//Destrutor
	~Mensagem_tab();

	//Metodos
	void exibir_msg() override;
	void escrever_msg() override;
};

#endif
