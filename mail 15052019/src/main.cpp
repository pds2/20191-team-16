//Esse main serviu de teste para as funcoes do mail.h/cpp
//Deve ser substituido posteriormente

#include <iostream>
#include "mail.h"

int main()
{
    Mail mail(true);
    system ("resize -s 24 80");
    system ("clear");

    while (true)
    {
        switch(mail.init())
        {
            case 1:
            
                std::cout << "\n[Login]" << std::endl;

                break;
            case 2:

                mail.registro();
                break;
            case 3:

                std::cout << "\n[Fechando programa]" << std::endl;
                return 0;
        }
    }

    return 0;
}
