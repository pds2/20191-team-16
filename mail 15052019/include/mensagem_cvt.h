#ifndef SUB_CLASS_MENSAGEM_CVT_H
#define SUB_CLASS_MENSAGEM_CVT_H

#include "mensagem.h"

#include <string>

class Mensagem_cvt : public Mensagem {

private:

	std::string _anfit;
	std::string _convi;
	std::string _local;
	std::string _event;
	std::string _dataevt;

public:

	//Construtor
	Mensagem_cvt(std::string user, std::string box, std::string target);

	//Destrutor
	~Mensagem_cvt();

	//Metodos
	void exibir_msg() override;
	void escrever_msg() override;

};

#endif
