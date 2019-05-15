#ifndef CLASS_SESSAO_H 
#define CLASS_SESSAO_H

#include <string>
#include <vector>

#include "mensagem.h"

class Sessao {

private:

    std::string _nome;
    std::string _senha;

    //Interruptor que define como a caixa de emails deve ser organizada
    short _boxflag;

    std::vector <Mensagem> _box;

public:

    //Construtor
    Sessao(std::string nome);

    //Destrutor
    ~Sessao();

    //Getters
    std::string get_nome();
    std::string get_senha();

    short get_boxflag();

    //Setters
    void set_nome(std::string nome);
    void set_senha(std::string senha);

    void set_boxflag(short boxflag);

    //Metodos
    void clear_box();
    void listar_box();

    void config_conta();
};

#endif