#include "gerais.h"

#include <iostream>

#define SPLIT  8

#define ANYDGT 2

#define ANODGT 4

void limpar_buffer()
{
    //Limpa o buffer de entrada do teclado
    std::cin.clear();
    std::cin.ignore(10000,'\n');
}

void display_caixa(std::fstream &caixa, std::string cor)
{
    std::string texto;

    std::cout << cor;

    system("clear");

    while (!caixa.eof())
    {
        std::getline(caixa, texto);

        std::cout << texto << std::endl;

        texto.clear();
    }

    //Voltando a cor do terminal
    std::cout << "\033[m";

    caixa.close();
}

void botao_enter()
{
    std::string enter;
    std::getline(std::cin, enter);

    enter.clear();
}

std::string get_string_hora(std::string data)
{
    //String que contera apenas HH:MM:SS respectivamente
    std::string hora, min, seg;

    /*Pegando o resto de data(HHMMSS), a partir do ponto de corte da
      string*/
    for (unsigned int j = SPLIT; j < data.size(); j++)
    {
        if (hora.size() != ANYDGT)
            hora.insert(hora.end(), data[j]);

        else if (min.size() != ANYDGT)
            min.insert(min.end(), data[j]);

        else seg.insert(seg.end(), data[j]);
    }

    return (hora + ":" + min + ":" + seg);
}

std::string get_string_dia(std::string data)
{
    //Strings que conteram apenas DD/MM/AAAA respectivamente
    std::string dia, mes, ano;

    /*Pegando os dados AAAAMMDD da string_tempo e passando para as strings
      dia, mes e ano*/
    for (unsigned int i = 0; i < SPLIT; i++)
    {
            if (ano.size() != ANODGT)
                ano.insert(ano.end(), data[i]);

            else if (mes.size() != ANYDGT)
                mes.insert(mes.end(), data[i]);

            else dia.insert(dia.end(), data[i]);
    }

    return (dia + "/" + mes + "/" + ano);
}

std::string ajust_string(std::string string, unsigned int size)
{
    std::string vacuo;

    if (string.size() < size)
        for (unsigned int i = 0; i < size - string.size(); i++)
            vacuo.insert(vacuo.end(), ' ');

    return vacuo;
}

/*Essa funcao vai pegar o horario do relogio do OS e passar para um
  inteiro no formato [AAAAMMDDHHMMSS], diferentemente dos outros setters */
long fetch_data()
{
    time_t now;
    struct tm *timeinfo;
    char dataTime[16];
    long data;

    now = time(NULL);
    timeinfo = localtime(&now);
    strftime (dataTime, 16, "%Y%m%d%H%M%S",timeinfo);
    data = atol(dataTime);

    return data;
}
