#include "Jogo.hpp"

namespace Jogo{

	Jogo::Jogo(){
		this->listaJogadores = nullptr;
		this->listaAdjacencia = nullptr;
	}

	Jogo::~Jogo(){
		delete this->listaAdjacencia;
	}

	void Jogo::configuraJogo(std::string arq_entrada){
		std::fstream fs;
		std::cout<<"Nome do Arquivo: "<<"'"<<arq_entrada<<"'"<<std::endl;
		fs.open(arq_entrada, std::fstream::in);
		if(fs.is_open()){
    		std::cout<< "Arquivo aberto com sucesso"<<std::endl;
    		unsigned int N=0;
	  		unsigned int M=0;
	  		unsigned int K=0;
	  		fs>>N;
	  		fs>>M;
	  		const unsigned int N2=N,M2=M;
	  		this->listaAdjacencia = geraListaAdjacencia(N2,M2);
	  		std::cout<<N<<" "<<M<<std::endl;
	  		fs>>K;
	  		std::cout<<K<<std::endl;
	  		unsigned int peso;
	  		for(unsigned int linha=0;linha<N;linha++){
	  			for(unsigned int coluna=0;coluna<M;coluna++){
	  				fs>>peso;
	  				std::cout<<"Linha: "<<linha<<" Coluna: "<<coluna<<" Peso: "<<peso<<" ";
	  				addArestas(linha,coluna,peso,N,M);
	  			}
	  			std::cout<<std::endl;
	  		}
	  		
	  		std::string x,y;
	  		std::string nomes="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	  		Jogador* jogador = nullptr;
	  		for(unsigned int numJogador=0;numJogador<K;numJogador++){
	  			fs>>x;
	  			fs>>y;
	  			jogador = new Jogador(nomes.at(numJogador),numJogador,x,y,);
	  			(*this->listaJogadores).push_back(jogador);
	  			std::cout<<x<<" "<<y<<std::endl;
	  		}
	  		fs.close();
 		 }else{
    		std::cout<< "Erro ao abrir o arquivo - confira o local e nome do arquivo"<<std::endl;
    		fs.close();
    		system("PAUSE");
  		}
	}

	std::list<Node*>* Jogo::geraListaAdjacencia(const unsigned int N, const unsigned int M){
		return new std::list<Node*>[N][M];
	}

	void Jogo::addArestas(int x, int y, int peso, int N, int M){
		std::cout<<"Se liga com:"<<std::endl;
		if((x+peso)<=(N-1)){
			*(this->listaAdjacencia[x+peso][y]).push_back(new Node(new Posicao(x,y,peso)));
			std::cout<<"X: "<<x+peso<<" Y: "<<y<<std::endl;
		}if((x-peso)>=0){
			*((this->listaAdjacencia)[x-peso][y]).push_back(new Node(new Posicao(x,y,peso)));
			std::cout<<"X: "<<x-peso<<" Y: "<<y<<std::endl;
		}if((y+peso)<=(M-1)){
			*(this->listaAdjacencia[x][y+peso]).push_back(new Node(new Posicao(x,y,peso)));
			std::cout<<"X: "<<x<<" Y: "<<y+peso<<std::endl;
		}if((y-peso)>=0){
			*(this->listaAdjacencia[x][y-peso]).push_back(new Node(new Posicao(x,y,peso)));
			std::cout<<"X: "<<x<<" Y: "<<y-peso<<std::endl;
		}
	}

	
}