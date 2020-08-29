#ifndef NODE_H
#define NODE_H
#include "Posicao.hpp"
namespace Jogo{
	class Node{
	private:
		Posicao* posicao;
		Node* prox;
	public:
		Node(Posicao);
		Posicao* getPosicao();
		Node* getProx();
		void setProx(Node*);
	};
}
#endif