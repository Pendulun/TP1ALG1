#ifndef JOGADOR_H
#define JOGADOR_H
#include <string>
namespace Jogo{
	class Jogador{
	private:
		std::string nome;
		int tamCaminho;
		int pesoPenultimaJogada;
		int ordemPrimeiraJogada;
		unsigned int xPosInicial;
		unsigned int yPosInicial;
	public:
		Jogador(std::string nome,unsigned int ordem,unsigned int x, unsigned int y);
		int getTamCaminho();
		int getPesoPenultimaJogada();
		int getOrdemPrimeiraJogada();
		std::string getNome();
		unsigned int getX();
		unsigned int getY();
		void setTamCaminho(int);
		void setPesoPenultimaJogada(int);
		~Jogador();
	};
}
#endif