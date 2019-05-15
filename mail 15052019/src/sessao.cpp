#include "sessao.h"

#include <string>

//Construtor
Sessao::Sessao(std::string nome)
{
    //Place Holder
}

//Destrutor
Sessao::~Sessao()
{
    //Place Holder
}

//Getters
std::string Sessao::get_nome()
{
    return _nome;
}

std::string Sessao::get_senha()
{
    return _senha;
}

short Sessao::get_boxflag()
{
    return _boxflag;
}

//Setters
void Sessao::set_nome(std::string nome)
{
    _nome = nome;
}

void Sessao::set_senha(std::string senha)
{
    _senha = senha;
}

void Sessao::set_boxflag(short boxflag)
{
    _boxflag = boxflag;
}

//Metodos
void Sessao::clear_box()
{
    //Place Holder
}

void Sessao::listar_box()
{
    //Place Holder
}

void Sessao::config_conta()
{
    //Place Holder
}

