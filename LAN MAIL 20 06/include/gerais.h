#ifndef FUNCOES_GENERICAS_H
#define FUNCOES_GENERICAS_H

#include <string>
#include <fstream>

//Funcao que limpa a memoria armazenada no buffer do teclado
void limpar_buffer();

//Funcao que verifica se existe um nome dentro do arquivo de texto log.txt
bool match_log(std::string nome);

/*Funcao que printa na tela do terminal um bloco de texto, em uma determinada cor.
  Usado em conjunto com o diretorio Assets/*/
void display_caixa(std::string path, std::string cor);

//Funcao que simula um "press enter to continue"
void botao_enter();

//Funcao que pega uma valor data do formato "AAAAMMDDHHMMSS" e retorna HH:MM:SS
std::string get_string_hora(std::string data);

//Funcao que pega uma valor data do formato "AAAAMMDDHHMMSS" e retorna DD/MM/AAAA
std::string get_string_dia(std::string data);

//Funcao que ajusta uma linha de texto para encaixar numa "moldura"
std::string ajust_string(unsigned int size, unsigned int limite);

//Funcao que pega do sistema o horario atual no formato "AAAAMMDDHHMMSS"
long fetch_data();

#endif
