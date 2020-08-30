#ifndef POSICAOJOGADOR_H
#define POSICAOJOGADOR_H
namespace Jogo{
	class PosicaoJogador{
	public:
		PosicaoJogador(int,int);
		int getX();
		int getY();
	private:
		int x;
		int y;
	};
}
#endif