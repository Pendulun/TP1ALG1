#include "Jogador.hpp"

namespace Jogo{
	Jogador::Jogador(std::string nome,unsigned int ordem,unsigned int x, unsigned int y){
		this->nome = nome;
		this->ordemPrimeiraJogada = ordem;
		this->xPosInicial = x;
		this->yPosInicial = y;
	}

	int Jogador::getTamCaminho(){
		return this->tamCaminho;
	}

	std::string Jogador::getNome(){
		return this->nome;
	}

	int Jogador::getPesoPenultimaJogada(){
		return this->pesoPenultimaJogada;
	}

	int Jogador::getOrdemPrimeiraJogada(){
		return this->ordemPrimeiraJogada;
	}

	unsigned int Jogador::getX(){
		return this->xPosInicial;
	}

	unsigned int Jogador::getY(){
		return this->yPosInicial;
	}

	void Jogador::setTamCaminho(int tamanho){
		this->tamCaminho = tamanho;
	}

	void Jogador::setPesoPenultimaJogada(int peso){
		this->pesoPenultimaJogada = peso;
	}
}