#ifndef PROGRAM_MAIL_H
#define PROGRAM_MAIL_H

#include <string>
#include <fstream>

class Mail {

private:

    //SubMetodos
    void criar_log();

    bool scan_nome(std::string nome);

    bool match_log(std::string nome);

    void criar_user(std::string nome, std::string senha);

public:

    //Metodos
    short init();

    std::string login();

    void registro();
};

#endif
