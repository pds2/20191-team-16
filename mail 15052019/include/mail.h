#ifndef PROGRAM_MAIL_H
#define PROGRAM_MAIL_H

#include <string>

class Mail {

private:

    bool _run;

    //SubMetodos
    void limpar_buffer();
    void criar_log();
    bool scan_nome(std::string nome);
    bool match_log(std::string nome);
    void criar_user(std::string nome, std::string senha);

public:

    //Construtor
    Mail(bool _run);

    //Destrutor
    ~Mail();

    //Getters
    bool get_run();

    //Setters
    void set_run(bool run);

    //Metodos
    short init();
    void login();
    void registro();
};

#endif
