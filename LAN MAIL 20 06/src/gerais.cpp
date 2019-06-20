#include "gerais.h"

#include <fstream>
#include <iostream>

//Posicao de corte para a string data
#define SPLIT   8
//Numero de digitos para representar o ano AAAA
#define ANODGT  4
//Numero de digitos para representar medidas de tempo exceto o ano
#define ANYDGT  2

//Numero de espacos de char array que time precisa
#define TIMESIZE 16

//Valor de reset para o cor do terminal
#define DEFAULT "\033[m"

void limpar_buffer()
{
    //Limpa o buffer de entrada do teclado
    std::cin.clear();
    std::cin.ignore(10000,'\n');
}

bool match_log(std::string nome)
{
    std::fstream read_log;
    read_log.open("Data/log.txt", std::ios::in);

    std::string compr;

    while (true)
    {
        read_log >> compr;

        if (read_log.eof()) break;

        if (nome == compr)
        {
            read_log.close();
            return true;
        }
        else compr.clear();
    }

    read_log.close();
    return false;
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

void display_caixa(std::string path, std::string cor)
{
    std::fstream display;
    display.open(path.c_str(), std::ios::in);

    std::string texto;

    std::cout << cor;

    system("clear");

    while (!display.eof())
    {
        std::getline(display, texto);

        std::cout << texto << std::endl;

        texto.clear();
    }

    //Voltando a cor do terminal
    std::cout << DEFAULT;

    display.close();
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

std::string ajust_string(unsigned int size, unsigned int limite)
{
    std::string vacuo;

    if (size < limite)
        for (unsigned int i = 0; i < (limite - size); i++)
            vacuo.insert(vacuo.end(), ' ');

    return vacuo;
}

/*Essa funcao vai pegar o horario do relogio do OS e passar para um
  inteiro no formato [AAAAMMDDHHMMSS], diferentemente dos outros setters */
long fetch_data()
{
    time_t now;
    struct tm *timeinfo;
    char dataTime[TIMESIZE];
    long data;

    now = time(nullptr);
    timeinfo = localtime(&now);
    strftime (dataTime, TIMESIZE, "%Y%m%d%H%M%S",timeinfo);
    data = atol(dataTime);

    return data;
}
