#ifndef JOGO_H
#define JOGO_H
#include "Jogador.hpp"
#include "Node.hpp"
#include <iterator>
#include <fstream>
#include <string>
#include <iostream>
#include <list>
namespace Jogo{
	class Jogo{
	public:
		void configuraJogo(std::string);
		void ganhador();
		Jogo();
		~Jogo();
	private:
		std::list<Jogador*>* listaJogadores;
		std::list<Node*>* listaAdjacencia;
		std::pair<int,int>* arvore;
		unsigned int N,M;
		void addArestas(int,int,int);
		std::list<Node*>* geraListaAdjacencia();
		Jogador* pegarMenor();
		unsigned int calculaDistancia(Jogador*);
		void BFS();
	};
}
#endif