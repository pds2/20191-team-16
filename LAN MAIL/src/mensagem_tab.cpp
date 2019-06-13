#include "gerais.h"
#include "mensagem_tab.h"
#include <fstream>
#include <string>
#include <vector>
#include <iostream>

//Construtor
Mensagem_tab::Mensagem_tab
(std::string file , short lido       , long data,
 std::string remet, std::string desti,
 std::string assun, short unipl,
 std::vector <std::string> tab) :

Mensagem(file, lido, data, remet, desti, assun),

_unipl(unipl), _tab(tab) {}

//Getters
short Mensagem_tab::get_unipl()
{
    return _unipl;
}

std::vector <std::string> Mensagem_tab::get_tab()
{
    return _tab;
}


//Metodos
void Mensagem_tab::exibir_msg()
{
    exibir_cabe();

    unsigned int maxsize;

    for (unsigned int i = 0; i < _tab.size(); i++)
    {
        if (i == 0) maxsize = _tab[i].size();
        else
        {
            if (maxsize < _tab[i].size())
                maxsize = _tab[i].size();
        }
    }

    while ((_tab.size() % _unipl) != 0)
            _tab.insert(_tab.end(), "-");

    short count = 0;

	for (unsigned int i = 0; i < _tab.size(); i++)
	{
		if (count == _unipl)
		{
			std::cout << " = \n =";

            for (unsigned int i = 0; i < ((maxsize * _unipl + (_unipl * 3))); i++)
                std::cout << "=";

            std::cout << "\n";

			count = 0;
		}

		std::cout << " = " <<_tab[i] << ajust_string(_tab[i], maxsize);
		count++;

        if (i == _tab.size() - 1)
        {
            if (count != _unipl)
            {
                std::cout << " = " << ajust_string("", maxsize);
            }

            std::cout << " = \n =";
            break;
        }
	}

    for (unsigned int i = 0; i < ((maxsize * _unipl + (_unipl * 3))); i++)
        std::cout << "=";

    std::cout << "\n";
}

/*void Mensagem_tab::escrever_msg(std::string nome)
{
	//Funcao pra escrever em tabela
	//Pede-se para o usuario para inserir 
	//Os elementos da tabela
	//Para encerrar a funcao, digita-se --ok
	std::string palavra;
	std::fstream arq;

	std::cout << "\n[Escrevendo Tabela:]" << std::endl;
	std::cout << "[Insira o numero de elementos por linha:]" << std::endl;
	std::cin >> _unipl;
	std::cout << "[Insira os elementos: ]" << std::endl;
	std::cout << "[Digite --ok para parar]" << std::endl;	
			
	while(true){
		palavra.clear();
		std::cin >> palavra;
		if(palavra == "--ok"){
			break;
		}			
		else{
			_tab.push_back(palavra);
		}
	}
	
	std::string _file = std::to_string(_data);
	arq.open(("Data/"+ nome +"/outbox/log_out.txt").c_str(), std::ios::app | std::ios::out);
	arq << _file << " 3\n";
	arq.close(); 

	system(("touch Data/" + nome + "/outbox/" + _file + ".txt").c_str());
	arq.open(("Data/" + nome + "/outbox/" + _file + ".txt").c_str(), std::ios::out);
	arq << _lido << "\n";
	arq << _file << "\n";
	arq << _data << "\n";
	arq << _remetente << "\n";
	arq << _destinatario << "\n";
	arq << _assunto << "\n";
	arq << _tab << "\n";
	arq.close();

	return;	
}*/
