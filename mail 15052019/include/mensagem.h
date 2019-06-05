#ifndef SUPER_CLASS_MENSAGEM_H
#define SUPER_CLASS_MENSAGEM_H

#include <string>
#include <fstream>

class Mensagem {

private:

    //Nome do arquivo de texto salvo nas caixas de entrada e saida
    std::string _file;

    //Variavel que define se uma mensagem ja foi ou nao lida
    short _lido;

    //Data de emissao da mensagem, no formato [AAAAMMDDHHMMSS]
    long  _data;

    //Remetente, destinatario e assunto da mensagem
    std::string _remet;
    std::string _desti;
    std::string _assun;

public:

    //Construtor
    Mensagem(std::string file , short lido       , long data,
             std::string remet, std::string desti, std::string assun);

    //Getters
    short get_lido();

    long  get_data();

    std::string get_remet();
    std::string get_desti();
    std::string get_assun();

    //Setters
    void set_lido(short lido);

    void set_data();

    void set_remet(std::string remet);
    void set_desti(std::string desti);
    void set_assun(std::string assun);

    //Metodos
    virtual void exibir_msg()   = 0;
    virtual void escrever_msg() = 0;

    void delete_msg();
    void enviar_msg();
};

#endif
