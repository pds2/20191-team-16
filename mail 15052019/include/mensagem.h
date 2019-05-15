#ifndef SUPER_CLASS_MENSAGEM_H
#define SUPER_CLASS_MENSAGEM_H

#include <string>

class Mensagem {

private:

    int _data;
    std::string _remet;
    std::string _desti;
    std::string _assun;

public:

    //Construtor
    Mensagem();

    //Destrutor
    ~Mensagem();

    //Getters
    int get_data();
    std::string get_remet();
    std::string get_desti();
    std::string get_assun();

    //Setters
    void set_data();
    void set_remet(std::string remet);
    void set_desti(std::string desti);
    void set_assun(std::string assun);

    //Metodos
    virtual void exibir_msg();
    virtual void escrever_msg();

    void delete_msg();
    void enviar_msg();
};

#endif