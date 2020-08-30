#include "Node.hpp"

namespace Jogo{
	Node::Node(int x, int y, int peso){
		this->x = x;
		this->y = y;
		this->peso = peso;
	}

	int Node::getX(){
		return this->x;
	}
	
	int Node::getY(){
		return this->y;
	}

	int Node::getPeso(){
		return this->peso;
	}
}