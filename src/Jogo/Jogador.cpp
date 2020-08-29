#include "Jogador.hpp"

namespace Jogo{
	Jogador::Jogador(std::string nome,int ordem,int x, int y, int peso){
		this->nome = nome;
		this->ordemPrimeiraJogada = ordem;
		this->posicaoInicial = new Posicao(x,y,peso);
	}

	Jogador::~Jogador(){
		delete this->posicaoInicial;
	}

	int Jogador::getTamCaminho(){
		return this->tamCaminho;
	}

	int Jogador::getPesoPenultimaJogada(){
		return this->pesoPenultimaJogada;
	}

	int Jogador::getOrdemPrimeiraJogada(){
		return this->ordemPrimeiraJogada;
	}

	Posicao* Jogador::getPosicaoInicial(){
		return this->posicaoInicial;
	}

	void Jogador::setTamCaminho(int tamanho){
		this->tamCaminho = tamanho;
	}

	void Jogador::setPesoPenultimaJogada(int peso){
		this->pesoPenultimaJogada = peso;
	}
}