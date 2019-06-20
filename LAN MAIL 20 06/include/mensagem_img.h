#ifndef SUB_CLASS_MENSAGEM_IMG_H
#define SUB_CLASS_MENSAGEM_IMG_H

#include "mensagem.h"

#include <string>
#include <vector>
#include <fstream>

class Mensagem_img : public Mensagem {

private:

	//Os "pixels" da imagem
	std::vector <std::string> _imagem;

	//Submetodos
	virtual short salvar_msg_extra(std::fstream &msg);

public:

	//Construtor
	Mensagem_img(std::string file , short lido       , long data,
				 std::string remet, std::string desti,
				 std::string assun, std::vector <std::string> imagem);

	//Getters
	std::vector <std::string> get_imagem();

	//Metodos
	virtual void exibir_msg();
	virtual bool escrever_msg();
};

#endif
