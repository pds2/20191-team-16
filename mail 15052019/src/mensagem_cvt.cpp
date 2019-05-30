#include "mensagem_cvt.h"

#include <string>
#include <fstream>
#include <iostream>

//Construtor
Mensagem_cvt::Mensagem_cvt(std::string user, std::string box, std::string target) :
Mensagem(user, box, target)
{
	std::getline(_mail, _anfit);
	std::getline(_mail, _convi);
	std::getline(_mail, _local);
	std::getline(_mail, _event);
	std::getline(_mail, _dataevt);

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
	std::cout << "Caro" << get_desti() << "," << std::endl;

	std::cout << "\nO(A) anfitriao(a), "   << _anfit << ", convida " << _convi << " para o evento" << std::endl;
	std::cout << _event << " no local "   << _local << "," << std::endl;
	std::cout << "na data " << _dataevt << std::endl;

	std::cout << "\nEspera-se por sua presenca" << std::endl;
}

void Mensagem_cvt::escrever_msg()
{
	//Place Holder
}
