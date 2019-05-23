#ifndef SUB_CLASS_MENSAGEM_GNR_H
#define SUB_CLASS_MENSAGEM_GNR_H

#include "mensagem.h"

#include <string>
#include <vector>
#include <fstream>

class Mensagem_gnr : public Mensagem {

private:

	std::vector <std::string> texto;  

public:

	//Construtor
	Mensagem_gnr(std::fstream email);

	//Destrutor
	~Mensagem_gnr();

	//Metodos
	void exibir_msg() override;
	void escrever_msg() override;
};

#endif

