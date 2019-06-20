#ifndef PROGRAM_MAIL_H
#define PROGRAM_MAIL_H

#include <string>
#include <fstream>

class Mail {

private:

    //SubMetodos

    /*Submetodo de registro. Cria o arquivo "log.txt" caso ele esteja ausente
      no processo de criacao de conta. Normalmente e chamado no primeiro uso do programa*/
    void criar_log();

    /*Submetodo de registro. Cria os diretorios e arquivos de referencia de recebimento
      e envio de mensagens do usuario*/
    void criar_user(std::string nome, std::string senha);

    /*Submetodo de registro. Verifica se o nome inserido na definicao do usuario e valido
      para a criacao de pastas em sistemas Linux/Unix*/;
    bool scan_nome(std::string nome);

public:

    //Metodos

    /*Funcao que representa a porta de entrada ao programa. Exibe as 3 primeiras opcoes
      disponiveis: login, registro e sair*/
    short init();

    //Funcao que pede ao usuario inserir os dados de sua conta para poder iniciar sua sessao
    std::string login();

    //Funcao que cria uma conta para o usuario, tornando possivel ele usufruir do sistema de email
    void registro();
};

#endif
