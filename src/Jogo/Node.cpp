#include "Node.hpp"

namespace Jogo{
	Node::Node(Posicao posicao){
		this.posicao = &posicao;
		this.prox = nullptr;
	}

	Posicao* Node::getPosicao(){
		return this.posicao;
	}

	Node* Node::getProx(){
		return this.prox;
	}

	void Node::setProx(Node* node){
		this.prox = node;
	}
}