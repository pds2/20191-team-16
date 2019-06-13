#ifndef FUNCOES_GENERICAS_H
#define FUNCOES_GENERICAS_H

#include <string>
#include <fstream>

void limpar_buffer();

void display_caixa(std::fstream &caixa, std::string cor);

void botao_enter();

std::string get_string_hora(std::string data);

std::string get_string_dia(std::string data);

std::string ajust_string(std::string string, unsigned int size);

long fetch_data();

#endif
