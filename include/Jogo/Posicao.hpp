#ifndef POSICAO_H
#define POSICAO_H
namespace Jogo{
	class Posicao::PosicaoJogador{
	private:
		int x;
		int y;
		int peso;
	public:
		int getX();
		int getY();
		int getPeso();
		Posicao(int,int,int);
	};
}
#endif