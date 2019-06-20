#ifndef SUPER_CLASS_MENSAGEM_H
#define SUPER_CLASS_MENSAGEM_H

#include <string>
#include <vector>
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

    //Submetodos

    /*Submetodo de enviar_msg. Esse metodo pega os dados gerais de uma mensagem
      e os salva no disco*/
    void salvar_msg(std::string nome, std::string box, std::string log);

    /*Submetodo de salvar_msg. Esse metodo pega os dados especificos de um subtipo
      de mensagem e salva junto com os dados de salvar_msg. Essa funcao retorna um
      short que representa a flag de seu subtipo de mensagem (usado para o listar_box)*/
    virtual short salvar_msg_extra(std::fstream &msg) = 0;

protected:

    /*Submetodo das funcoes de exibir mensagem. Exibe na tela um cabecario contendo os dados gerais da
      da mensagem*/
    void exibir_cabe();

    /*Submetodo das funcoes de escrever mensagem. Exibe na tela as digitacoes anteriores, como forma #
     referencia ao usuario*/
    void print_anteriores(unsigned int count ,unsigned int anteriores, std::vector <std::string> bloco);

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
    std::string get_file();

    //Setters
    void set_lido(short lido);

    void set_data();

    void set_remet(std::string remet);
    void set_desti(std::string desti);
    void set_assun(std::string assun);

    //Metodos

    //Funcao que exibe a mensagem na tela. O comportamento varia com o subtipo
    virtual void exibir_msg()   = 0;
    //Funcao que escreve a mensagem. O comportamento varia com o subtipo
    virtual bool escrever_msg() = 0;

    void delete_msg();

    /*Funcao que cria uma copia de um objeto mensagem na outbox do usuario e nas
      inboxes dos destinatarios*/
    void enviar_msg();
};

#endif
