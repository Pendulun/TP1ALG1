#ifndef JOGO_H
#define JOGO_H
#include "Jogador.hpp"
#include "Node.hpp"
#include <fstream>
#include <string>
#include <iostream>
#include <list>
namespace Jogo{
	class Jogo{
	public:
		void configuraJogo(std::string);
		Jogo();
	private:
		std::list<Jogador> listaJogadores;
		std::list<Node> listaAdjacencia[]*;
	};
}
#endif