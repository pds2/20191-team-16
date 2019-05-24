#include "mensagem_cvt.h"

#include <string>
#include <fstream>

//Construtor
Mensagem_cvt::Mensagem_cvt(std::string target, std::string user, std::string box) :
Mensagem(target, user, box)
{
	_mail >> _anfit;
	_mail >> _convi;
	_mail >> _local;
	_mail >> _dataevt;

	_mail.close();
}

//Destrutor
Mensagem_cvt::~Mensagem_cvt()
{
	//Place Holder
}

//Metodos
void Mensagem_cvt::exibir_msg()
{
	//Place Holder
}

void Mensagem_cvt::escrever_msg()
{
	//Place Holder
}
