#include "mensagem_tab.h"

#include <string>
#include <vector>
#include <fstream>

//Construtor
Mensagem_tab::Mensagem_tab(std::string target, std::string user, std::string box) : 
Mensagem(target, user, box)
{
	std::string linha;

	while (!_mail.eof())
	{
		getline(_mail, linha);
    	std::string auxi1(linha);
    	std::istringstream iss(auxi1);
    	do
    	{
       		std::string auxi2;
       		iss >> auxi2;
       		std::cout << auxi2 << std::endl;
    	} while (iss);
	}

	_mail.close();
}

//Destrutor
Mensagem_tab::~Mensagem_tab()
{
	//Place Holder
}

//Metodos
void Mensagem_tab::exibir_msg()
{
	//Place Holder
}

void Mensagem_tab::escrever_msg()
{
	//Place Holder
}
