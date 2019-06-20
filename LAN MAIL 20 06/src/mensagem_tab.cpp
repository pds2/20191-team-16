#include "gerais.h"
#include "mensagem_tab.h"

#include <string>
#include <vector>
#include <iostream>

//Construtor--------------------------------------------------------------------
Mensagem_tab::Mensagem_tab
(std::string file , short lido       , long data,
 std::string remet, std::string desti,
 std::string assun, short unipl,
 std::vector <std::string> tab) :

Mensagem(file, lido, data, remet, desti, assun),

_unipl(unipl), _tab(tab) {}

//Submetodos--------------------------------------------------------------------
short Mensagem_tab::salvar_msg_extra(std::fstream &msg)
{
    msg << _unipl << std::endl;

    for (unsigned int i = 0; i < _tab.size(); i++)
        msg << _tab[i] << std::endl;

    msg.close();

    return 3;
}

//Getters-----------------------------------------------------------------------
short Mensagem_tab::get_unipl()
{
    return _unipl;
}

std::vector <std::string> Mensagem_tab::get_tab()
{
    return _tab;
}


//Metodos-----------------------------------------------------------------------
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

		std::cout << " = " <<_tab[i] << ajust_string(_tab[i].size(), maxsize);
		count++;

        if (i == _tab.size() - 1)
        {
            if (count != _unipl)
            {
                std::cout << " = " << ajust_string(0, maxsize);
            }

            std::cout << " = \n =";
            break;
        }
	}

    for (unsigned int i = 0; i < ((maxsize * _unipl + (_unipl * 3))); i++)
        std::cout << "=";

    std::cout << "\n";
}

bool Mensagem_tab::escrever_msg()
{
	//Place Holder
}
