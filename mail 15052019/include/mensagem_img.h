#ifndef SUB_CLASS_MENSAGEM_IMG_H
#define SUB_CLASS_MENSAGEM_IMG_H

#include "mensagem.h"

#include <string>
#include <vector>
#include <fstream>

class Mensagem_img : public Mensagem {

private:

	std::vector <std::string> _imagem;

public:

	//Construtor
	Mensagem_img(std::string user, std::string box, std::string target);

	//Destrutor
	~Mensagem_img();

	//Metodos
	void exibir_msg() override;
	void escrever_msg() override;
};

#endif
