#include "gerais.h"
#include "mensagem_gnr.h"

#include <string>
#include <vector>
#include <fstream>
#include <iostream>

//Valor do espacao disponivel para escrita no progrma (80 - 6(espaco das bordas))
#define GAPSIZE 74

#define NUMLINHAS 20

/*Valor que determina quantos termos anteriores de um inserimento devem ser mostrados
  durante um processo de ecrita de mensagem*/
#define ANTERIOR 5

//Valor da cor dos textos para a funcao display_caixa
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define DEFAULT "\033[m"

//Construtor--------------------------------------------------------------------
Mensagem_gnr::Mensagem_gnr
(std::string file , short lido       , long data,
 std::string remet, std::string desti,
 std::string assun, std::vector <std::string> texto) :

Mensagem(file, lido, data, remet, desti, assun),

_texto(texto) {}

//Getters-----------------------------------------------------------------------
std::vector <std::string> Mensagem_gnr::get_texto()
{
    return _texto;
}

//Submetodos--------------------------------------------------------------------
short Mensagem_gnr::salvar_msg_extra(std::fstream &msg)
{
    for (unsigned int i = 0; i < _texto.size(); i++)
        msg << _texto[i] << std::endl;

    msg.close();

    return 0;
}

//Metodos-----------------------------------------------------------------------
void Mensagem_gnr::exibir_msg()
{
    exibir_cabe();

	for (unsigned int i = 0; i < _texto.size(); i++)
        std::cout << " = " << _texto[i] << ajust_string(_texto[i].size(), GAPSIZE) << " = " << std::endl;

    std::cout << " ==============================================================================" << std::endl;
}

bool Mensagem_gnr::escrever_msg()
{
    short count = 0;
    std::string linha;

    while (count < NUMLINHAS)
    {
        display_caixa("Assets/Write/Gnr/gnr1.txt", DEFAULT);

        print_anteriores(count, ANTERIOR, _texto);

        std::cout << "\n Linha[" << count + 1 << "]" << std::endl;
        std::cout << "\n $: ";
        std::getline(std::cin, linha);

        if (linha == "--sair")
        {
            display_caixa("Assets/Write/writecancel.txt", DEFAULT);
            botao_enter();

            return false;
        }

        else if (linha == "--ok")
            break;

        else if (linha == "--redo")
        {
            count = 0;
            _texto.clear();

            linha.clear();

            continue;
        }

        if (linha.size() >= GAPSIZE)
        {
            display_caixa("Assets/Write/Gnr/gnrerror.txt", RED);
            botao_enter();
        }
        else
        {
            _texto.push_back(linha);
            count++;
        }

        linha.clear();
    }

    display_caixa("Assets/Write/write3.txt", DEFAULT);
    char esc;

    std::cout << "                                $: ";
    std::cin  >> esc;

    limpar_buffer();

    if ((esc == 'S') || (esc == 's'))
    {
        //Funcao de enviar //Ainda nao implementada
        return true;
    }
    else
        return false;
}
