#include "PosicaoJogador.hpp"

namespace Jogo{
	PosicaoJogador::PosicaoJogador(int x, int y){
		this->x = x;
		this->y = y;
	}

	PosicaoJogador::getX(){
		return this->x;
	}

	PosicaoJogador::getY(){
		return this->y;
	}
}