//Esse main serviu de teste para o registro_01.h.
//Deve ser substituido posteriormente 

#include <iostream>
#include "registro_01.h"
#include "config_01.h"

int main()
{
    system("clear");

    std::cout << "-Teste com funcao de registro-" << std::endl;

    registro();
    
    std::cout << "-Teste com funcao de configurar-" << std::endl;
    
    configurar();

    return 0;
}
