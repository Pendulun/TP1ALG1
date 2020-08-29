#ifndef JOGO_H
#define JOGO_H
#include <fstream>
#include <string>
#include <iostream>
#include <list>
namespace Jogo{
	class Jogo{
	public:
		void configuraJogo(std::string);
	private:
		std::list<Jogadores> listaJogadores;
	};
}
#endif