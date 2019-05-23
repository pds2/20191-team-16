#ifndef SUB_CLASS_MENSAGEM_CVT_H
#define SUB_CLASS_MENSAGEM_CVT_H

#include "mensagem.h"

#include <string>
#include <fstream>

class Mensagem_cvt : public Mensagem {

private:

	std::string anfit;
	std::string convi;
	std::string local;
	std::string data;

public:

	//Construtor
	Mensagem_cvt(std::fstream email);

	//Destrutor
	~Mensagem_cvt();

	//Metodos
	void exibir_msg() override;
	void escrever_msg() override;

};

#endif
