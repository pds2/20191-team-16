#include "doctest.h"
#include "gerais.h"
#include "mail.h"
#include "sessao.h"

//Realizando testes sobre as funções gerais
TEST_CASE("1 - 1: Testando get_string_hora()")
{
    CHECK(get_string_hora("20190618203030") == "20:30:30");
}

TEST_CASE("1 - 2: Testando get_string_dia()")
{
    CHECK(get_string_dia("20190618203030") == "18/06/2019");
}

TEST_CASE("1 - 3: Testando ajust_string()")
{
    CHECK(ajust_string(0, 10) == "          ");
}

//Realizando testes sobre os submetodos de sessao.cpp
TEST_CASE("2 - 1: Testando o carregamento da caixa de entrada com o _boxflag = 0")
{
    Sessao sessao("person");
	
	sessao.set_box();
	
	CHECK(sessao.get_time_size() == 5);
}

TEST_CASE("2 - 3: Testando o carregamento da caixa de entrada com o _boxflag = 1")
{
	Sessao sessao("person");
	
	sessao.set_boxflag(1);
	
	sessao.set_box();
	
	CHECK(sessao.get_time_size() == 2);
}

TEST_CASE("2 - 4: Testando o carregamento da caixa de entrada com o _boxflag = 2")
{
	Sessao sessao("person");
	
	sessao.set_boxflag(2);
	
	sessao.set_box();
	
	CHECK(sessao.get_time_size() == 3);
}

TEST_CASE("2 - 5: Testando o carregamento da caixa de entrada com o _boxflag = 3")
{
	Sessao sessao("person");
	
	sessao.set_boxflag(3);
	
	sessao.set_box();

	CHECK(sessao.get_time_size() == 1);
}

TEST_CASE("2 - 6: Testando o carregamento da caixa de saida")
{
	Sessao sessao("person");
	
	sessao.set_readbox("outbox");
	sessao.set_readlog("log_out.txt");
	
	sessao.set_box();
	
	CHECK(sessao.get_time_size() == 1);
}

TEST_CASE("2 - 7: Testando o esvaziamento da caixa de entrada")
{
	Sessao sessao("person");
	
	sessao.set_box();
	
	sessao.limpar_box_all();
	
	CHECK(sessao.get_time_size() == 0);
}
