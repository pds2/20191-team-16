#ifndef SUB_CLASS_MENSAGEM_GNR_H
#define SUB_CLASS_MENSAGEM_GNR_H

#include "mensagem.h"

#include <string>
#include <vector>
#include <fstream>

class Mensagem_gnr : public Mensagem {

private:

	//As linhas escritas da mensagem
	std::vector <std::string> _texto;

	//Submetodos
	virtual short salvar_msg_extra(std::fstream &msg);

public:

	//Construtor
	Mensagem_gnr(std::string file , short lido       , long data,
				 std::string remet, std::string desti,
				 std::string assun, std::vector <std::string> texto);

	//Getters
	std::vector <std::string> get_texto();

	//Metodos
	virtual void exibir_msg();
	virtual bool escrever_msg();
};

#endif
