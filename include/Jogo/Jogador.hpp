#ifndef JOGADOR_H
#define JOGADOR_H
#include <string>
namespace Jogo{
	class Jogador{
	private:
		std::string nome;
		unsigned int tamCaminho;
		unsigned int pesoPenultimaJogada;
		unsigned int ordemPrimeiraJogada;
		unsigned int xPosInicial;
		unsigned int yPosInicial;
	public:
		Jogador(std::string nome,unsigned int ordem,unsigned int x, unsigned int y);
		unsigned int getTamCaminho();
		unsigned int getPesoPenultimaJogada();
		unsigned int getOrdemPrimeiraJogada();
		std::string getNome();
		unsigned int getX();
		unsigned int getY();
		void setTamCaminho(unsigned int);
		void setPesoPenultimaJogada(unsigned int);
		~Jogador();
	};
}
#endif