#ifndef SUB_CLASS_MENSAGEM_TAB_H
#define SUB_CLASS_MENSAGEM_TAB_H

#include "mensagem.h"

#include <string>
#include <vector>

class Mensagem_tab : public Mensagem {

private:

	//Numero de elementos por fileira na tabela
	short _unipl;

	//Os elementos da tabela
	std::vector <std::string> _tab;

public:

	//Construtor
	Mensagem_tab(std::string file , short lido       , long data,
				 std::string remet, std::string desti,
				 std::string assun, short unipl,
				 std::vector <std::string> tab);

	//Getters
	short get_unipl();
	std::vector <std::string> get_tab();

	//Metodos
	void exibir_msg()   override;
	void escrever_msg() override;
};

#endif
