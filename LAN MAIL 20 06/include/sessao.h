#ifndef CLASS_SESSAO_H
#define CLASS_SESSAO_H

#include <string>
#include <vector>
#include <fstream>

#include "gerais.h"
#include "mensagem.h"
#include "mensagem_gnr.h"
#include "mensagem_lst.h"
#include "mensagem_cvt.h"
#include "mensagem_img.h"

class Sessao {

private:

    /*Variavel com o nome do usuario. Usado como referencia para
    carregar os arquivos de sua pasta na memoria*/
    std::string _nome;

    //Variavel que armazena a senha do usuario, usada para configuracao da conta
    std::string _senha;

    //variavel que define qual box vai ser utilizada na listagem
    std::string _readbox;

    /*Variavel que define o arquivo de referencia no momneto de carregar as mensagens
      na memoria*/
    std::string _readlog;

    //Interruptor que define como a caixa de emails deve ser organizada
    short _boxflag;

    //Conjunto de variaveis que definem a extensao de exibicao da caixa de entrada
    unsigned int _beginbox;
    unsigned int _endbox;

    /*Conjunto de variaveis que indicam em que posicao de listagem de 5 blocos de
     mensagem o usuario esta*/
    unsigned int _pagina;
    unsigned int _paginamax;

    /*Vetores que armazenam todas as mensagens carregadas na memoria,
    por sub classe*/
    std::vector <Mensagem_gnr> _box0;
    std::vector <Mensagem_lst> _box1;
    std::vector <Mensagem_cvt> _box2;
    std::vector <Mensagem_img> _box3;

    /*Vetor que armazena em ordem decrescente a data de envio de cada mensagem.
    Usada como referencia para listar as mensagem em ordem*/
    std::vector <long> _time;

//Submetodos

    /*Submetodos de set_box(). Definem como devem ser carregados os dados especificos
      de uma mensagem. A chamado de um dos 5 e definido pela sua flag escaneada*/
    void add_msg_gnr(std::string file , short lido, long data, std::string remet,
                     std::string desti, std::string assun, std::fstream &read_target);

    void add_msg_lst(std::string file , short lido, long data, std::string remet,
                     std::string desti, std::string assun, std::fstream &read_target);

    void add_msg_cvt(std::string file , short lido, long data, std::string remet,
                     std::string desti, std::string assun, std::fstream &read_target);

    void add_msg_img(std::string file , short lido, long data, std::string remet,
                     std::string desti, std::string assun, std::fstream &read_target);

    /*Funcao que verifica se o objeto mensagem criado em um dos submetodos acima
      possui o criterio para ser jogado no seu repectivo vetor*/
    bool filtro_msg(Mensagem &msg);

    //Funcao que pega a data de emissao de um objeto mensagem e joga no vector _time
    void add_msg_time(long data);

    /*Submetodo de listar_box(). Funcao que printa na tela os seguintes dados
      de uma mensagem: data de emissao, */
    void achar_msg(unsigned int i, bool &okflag, long timepos, Mensagem &boxpos);

    /*Submetodo de agir_box(). Exibe na tela os dados da mensagem,
      seguindo o polimorfismo estabelecido entre elas*/
    void print_msg(Mensagem &msg);

    bool escrever_msg(Mensagem &msg);

    /*Submetodo de op1_alt_nome(). funcao que modifica o nome do usuario no log.txt
    e modifica o nome do diretorio do usuario*/
    void set_user(std::string nome2);

    //Submetodo de op2_alt_senha(). Funcao que modifica a senha no password.txt
    void set_password(std::string senha);

    /*Submetodo de op3_del_conta () .Funcao que exclui o diretorio do usuario e
    remove o nome dele do log.txt.*/
    void del_conta();

    //Submetodo de config_conta(). Funcao que da a opcao de alterar o nome
    void op1_alt_nome(std::string nome2);

    //Submetodo de config_conta(). Funcao que da a opcao de alterar a senha
    void op2_alt_senha(std::string senha);

    //Submetodo de config_conta(). Funcao que da a opcao de deletar a conta
    void op3_del_conta();

public:

    //Construtor
    Sessao(std::string nome);

    //Getters
    std::string get_nome();
    std::string get_senha();
    std::string get_readbox();
    std::string get_readlog();
    short get_boxflag();

    int get_time_size();

    unsigned int get_beginbox();
    unsigned int get_endbox();

    unsigned int get_pagina();
    unsigned int get_paginamax();

    //Retorna a data de uma posicao do vetor _time
    long get_time(unsigned int pos);

    //Setters
    void set_nome(std::string nome);
    void set_senha(std::string senha);
    void set_readbox(std::string readbox);
    void set_readlog(std::string readlog);
    void set_boxflag(short boxflag);

    void set_beginbox(unsigned int beginbox);
    void set_endbox(unsigned int endbox);

    void set_pagina(unsigned int pagina);
    void set_paginamax(unsigned int paginamax);

    //Metodos

    /*Funcao que carrega das caixas (entrada/saida) do usuario logado, todas as
      mensagens e armazena em vectors dcom seus respectivos subtipos*/
    void set_box();

    //Funcao que exibe um display com o usuario logado e o numero de mensagens carregadas
    void user_status();

    /*Percorre todos os vectors de mensagem, usando o _time, como referencia, para
    listar em ordem cronologica(do mais recente para o mais antigo) as mensagens*/
    void listar_box();

    /*Limpa todos os vetores de mensagens e o _time. Chamado toda a vez que e deixado
      o HUB durante a sessao*/
    void limpar_box_all();

    /*Funcao que busca uma posicao do vector mensagem, na lista exibida na tela e executa
      uma das seguintes acoes: exibir e deletar a mensagem*/
    void agir_box(long data);

    //Funcao que escreve uma mensagem para poder enviar a outros usuarios
    void criar_msg();

    //Funcao que envia a mensagem
    void enviar_msg();
	
    /*Funcao que deleta os dados
    armazenados no disco referente a essa mensagem*/
    void delete_msg();

    /*Função que permite ao usuário alterar suas configurações de registro, que ocorrerão
     no disco. (Alterar nome de usuário/Alterar senha/Deletar conta/voltar ao hub)*/
    void config_conta();
};

#endif
