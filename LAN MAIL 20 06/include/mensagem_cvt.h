#ifndef SUB_CLASS_MENSAGEM_CVT_H
#define SUB_CLASS_MENSAGEM_CVT_H

#include "mensagem.h"

#include <string>

class Mensagem_cvt : public Mensagem {

private:

	/*Dados do convite: Anfitriao, convidado, local do evento, o eventoto em si,
	e sua data*/
	std::string _anfit;
	std::string _convi;
	std::string _lugar;
	std::string _event;
	std::string _dataevt;

	//Submetodos
	virtual short salvar_msg_extra(std::fstream &msg);

public:

	//Construtor
	Mensagem_cvt(std::string file , short lido       , long data,
				 std::string remet, std::string desti,
				 std::string assun, std::string anfit,
				 std::string convi, std::string lugar,
				 std::string event, std::string dataevt);

	//Getters
	std::string get_anfit();
	std::string get_convi();
	std::string get_lugar();
	std::string get_event();
	std::string get_dataevt();

	//Metodos
	virtual void exibir_msg();
	virtual bool escrever_msg();

};

#endif
