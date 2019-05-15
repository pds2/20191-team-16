//Esse main serviu de teste para as funcoes do mail.h/cpp
//Deve ser substituido posteriormente

#include <iostream>
#include "mail.h"

int main()
{
    system("clear");

    Mail x(true);

    std::cout << "-Teste com funcao de registro-" << std::endl;

    x.registro();

    return 0;
}
