#ifndef JOGADOR_H
#define JOGADOR_H
#include <string>
#include "Posicao.hpp"
namespace Jogo{
	class Jogador{
	private:
		std::string nome;
		int tamCaminho;
		int pesoPenultimaJogada;
		int ordemPrimeiraJogada;
		Posicao* posicaoInicial;
	public:
		Jogador(std::string nome,int ordem,int x, int y, int peso);
		int getTamCaminho();
		int getPesoPenultimaJogada();
		int getOrdemPrimeiraJogada();
		Posicao* getPosicaoInicial();
		void setTamCaminho(int);
		void setPesoPenultimaJogada(int);
		~Jogador();
	};
}
#endif