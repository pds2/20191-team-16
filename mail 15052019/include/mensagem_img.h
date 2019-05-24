#ifndef SUB_CLASS_MENSAGEM_IMG_H
#define SUB_CLASS_MENSAGEM_IMG_H

#include "mensagem.h"

#include <fstream>

class Mensagem_img : public Mensagem {

private:

	int esc;

public:

	//Construtor
	Mensagem_img(std::string target, std::string user, std::string box);

	//Destrutor
	~Mensagem_img();

	//Metodos
	void exibir_msg() override;
	void escrever_msg() override;
};

#endif
