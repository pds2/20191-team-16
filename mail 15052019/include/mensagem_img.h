#ifndef SUB_CLASS_MENSAGEM_IMG_H
#define SUB_CLASS_MENSAGEM_IMG_H

#include "mensagem.h"

#include <string>
#include <vector>

class Mensagem_img : public Mensagem {

private:

	//Os "pixels" da imagem
	std::vector <std::string> _imagem;

public:

	//Construtor
	Mensagem_img(std::string file , short lido       , long data,
				 std::string remet, std::string desti,
				 std::string assun, std::vector <std::string> imagem);

	//Getters
	std::vector <std::string> get_imagem();

	//Metodos
	void exibir_msg()   override;
	void escrever_msg() override;
};

#endif
