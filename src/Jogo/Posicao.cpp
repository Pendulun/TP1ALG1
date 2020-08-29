#include "Posicao.hpp"

namespace Jogo{

	Posicao::Posicao(int x, int y , int peso){
		this.x = x;
		this.y= y;
		this.peso = peso;
	}

	int Posicao::getX(){
		return this.x;
	}

	int Posicao::getY(){
		return this.y;
	}

	int Posicao::getPeso(){
		return this.peso;
	}
}