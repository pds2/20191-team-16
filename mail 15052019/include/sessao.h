#ifndef CLASS_SESSAO_H 
#define CLASS_SESSAO_H

#include <string>
#include <vector>

#include "mensagem.h"

class Sessao {

private:

    /*Variavel com o nome do usuario. Usado como referencia para
    carregar os arquivos de sua pasta na memoria*/
    std::string _nome;

    //Variavel que armazena a senha do usuario, usada para configuracao da conta
    std::string _senha;

    //Interruptor que define como a caixa de emails deve ser organizada
    short _boxflag;

    /*Vetores que armazenam todas as mensagens carregadas na memoria,
    por sub classe*/
    std::vector <Mensagem_gnr> _box0;
    std::vector <Mensagem_lst> _box1;
    std::vector <Mensagem_cvt> _box2;
    std::vector <Mensagem_tab> _box3;
    std::vector <Mensagem_img> _box4;
    
    //Submetodos
    void limpa_buffer();
    bool match_log_(std::string nome2);
    void set_user(std::string nome, std::string nome2);
    void set_password(std::string nome, std::string senha);
    void del_conta(std::string nome);
    
    bool filtro_msg(Mensagem &msg);
    void add_msg_time(long data);
    void achar_msg(bool &okflag, long timepos, Mensagem &box);
    
    void add_msg_gnr(std::string file , short lido, long data, std::string remet,
                     std::string desti, std::string assun, std::fstream &read_target);
    void add_msg_lst(std::string file , short lido, long data, std::string remet,
                     std::string desti, std::string assun, std::fstream &read_target);
    void add_msg_cvt(std::string file , short lido, long data, std::string remet,
                     std::string desti, std::string assun, std::fstream &read_target);
    void add_msg_tab(std::string file , short lido, long data, std::string remet,
                     std::string desti, std::string assun, std::fstream &read_target);
    void add_msg_img(std::string file , short lido, long data, std::string remet,
                     std::string desti, std::string assun, std::fstream &read_target);
    std::string string_data(long data);
    

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
    void limpar_box();
    void listar_box();
    void config_conta();
};

#endif
