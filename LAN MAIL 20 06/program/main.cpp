//Esse main serviu de teste para as funcoes do mail.h/cpp
//Deve ser substituido posteriormente

#include "gerais.h"

#include "mail.h"
#include "sessao.h"
#include "mensagem.h"

#include "mensagem_gnr.h"
#include "mensagem_lst.h"
#include "mensagem_cvt.h"
#include "mensagem_img.h"

#include <iostream>

#include <cmath>

int main()
{
    system("clear");

    Mail mail;

    while (true)
    {
        short esco = mail.init();

        if (esco == 1)
        {
            std::string nome = mail.login();

            if (nome != "false")
            {
                Sessao sessao(nome);

                while (true)
                {
                    system("clear");

                    sessao.set_box();

                    sessao.set_paginamax(ceil(float(sessao.get_time_size()) / float(sessao.get_endbox())));
                    if (sessao.get_time_size() == 0)
                        sessao.set_paginamax(1);

                    sessao.user_status();

                    std::cout << " Pagina " << sessao.get_pagina() << " / " << sessao.get_paginamax() << std::endl;

                    sessao.listar_box();

                    //Menu de opcoes
                    std::cout << " [1]Abrir email       [2]Listar outbox   [3]Listar nao lidas   [4]Listar lidas"     << std::endl;
                    std::cout << " [5]Listar antigas    [6]Escrever        [7]Deletar mensagem   [8]Sair"             << std::endl;
                    std::cout << " [9]Configurar conta [10]Refresh        [11]Proxima pagina    [12]Pag. anterior"    << std::endl;

                    short esc;

                    std::cout << "\n $: ";
                    std::cin  >> esc;
					
		    limpar_buffer();

                    if (esc ==  1)
                    {
                        limpar_buffer();

                        std::cout << " $: Qual?: ";
                        short esc2;
						
			limpar_buffer();

                        std::cin >> esc2;

                        if ((esc2 < sessao.get_time_size()) && (esc2 >= 0))
                        {
                            system("clear");

                            sessao.agir_box(sessao.get_time(esc2));

			    std::cout << " Pressione Enter para voltar ao HUB " << std::endl;
							
                            botao_enter();
                        }
                    }
                    else if (esc ==  2)
                    {
                        sessao.set_boxflag(0);
                        sessao.set_readbox("outbox");
                        sessao.set_readlog("log_out.txt");
                    }
                    else if (esc ==  3)
                    {
                        sessao.set_boxflag(1);
                        sessao.set_readbox("inbox");
                        sessao.set_readlog("log_in.txt");
                    }
                    else if (esc ==  4)
                    {
                        sessao.set_boxflag(2);
                        sessao.set_readbox("inbox");
                        sessao.set_readlog("log_in.txt");
                    }
                    else if (esc ==  5)
                    {
                        sessao.set_boxflag(3);
                        sessao.set_readbox("inbox");
                        sessao.set_readlog("log_in.txt");
                    }
                    else if (esc ==  6)
                    {
                        sessao.limpar_box_all();

                        sessao.criar_msg();
                    }
                    else if (esc ==  7)
                    {
						sessao.delete_msg();
                    }
                    else if (esc ==  8)
                        break;
                    else if (esc ==  9)
                    {
                        sessao.config_conta();
                    }
                    else if (esc == 10)
                    {
                        sessao.set_boxflag(0);
                        sessao.set_readbox("inbox");
                        sessao.set_readlog("log_in.txt");
                    }
                    else if (esc == 11)
                    {
                        if (sessao.get_pagina() < sessao.get_paginamax())
                        {
                            sessao.set_pagina(sessao.get_pagina() + 1);

                            sessao.set_beginbox(sessao.get_beginbox() + sessao.get_endbox());

                            sessao.set_endbox(sessao.get_endbox() + sessao.get_endbox());
                        }
                    }
                    else if (esc == 12)
                    {
                        if (sessao.get_pagina() > 1)
                        {
                            sessao.set_pagina(sessao.get_pagina() - 1);

                            sessao.set_endbox(sessao.get_endbox() - sessao.get_beginbox());

                            sessao.set_beginbox(sessao.get_beginbox() - sessao.get_beginbox());
                        }
                    }
                    
                    sessao.limpar_box_all();
                }
            }
        }
        else if (esco == 2)
            mail.registro();

        else if (esco == 3)
        {
            system("clear");
            break;
        }

    }

    //Encerrando o progrmama
    return 0;
}
