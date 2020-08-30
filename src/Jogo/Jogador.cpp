#include "Jogador.hpp"

namespace Jogo{
	Jogador::Jogador(std::string nome,int ordem,int x, int y){
		this->nome = nome;
		this->ordemPrimeiraJogada = ordem;
		this->posicaoInicial = new PosicaoJogador(x,y);
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

	PosicaoJogador* Jogador::getPosicaoInicial(){
		return this->posicaoInicial;
	}

	void Jogador::setTamCaminho(int tamanho){
		this->tamCaminho = tamanho;
	}

	void Jogador::setPesoPenultimaJogada(int peso){
		this->pesoPenultimaJogada = peso;
	}
}