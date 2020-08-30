#include "Jogo.hpp"

namespace Jogo{

	Jogo::Jogo(){
		this->listaJogadores = new std::list<Jogador*>;
		this->listaAdjacencia = nullptr;
	}

	Jogo::~Jogo(){
		delete this->listaAdjacencia;
		delete this->listaJogadores;
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
	  		this->listaAdjacencia = geraListaAdjacencia(N,M);
	  		std::cout<<N<<" "<<M<<std::endl;
	  		fs>>K;
	  		std::cout<<K<<std::endl;
	  		std::string peso;
	  		for(unsigned int linha=0;linha<N;linha++){
	  			for(unsigned int coluna=0;coluna<M;coluna++){
	  				fs>>peso;
	  				std::cout<<"Linha: "<<linha<<" Coluna: "<<coluna<<" Peso: "<<std::stoi(peso)<<" ";
	  				addArestas(linha,coluna,std::stoi(peso),N,M);
	  			}
	  			std::cout<<std::endl;
	  		}
	  		unsigned int x,y;
	  		std::string nomes="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	  		Jogador* jogador = nullptr;
	  		for(unsigned int numJogador=0;numJogador<K;numJogador++){	
	  			fs>>x;
	  			fs>>y;
	  			jogador = new Jogador(((std::string) nomes.substr(numJogador,1)),numJogador,x,y);
	  			(this->listaJogadores)->push_back(jogador);
	  			std::cout<<"Jogador: "<<jogador->getNome()<<" X: "<<jogador->getX()<<" Y: "<<jogador->getY()<<std::endl;
	  		}
	  		std::cout<<"Fim"<<std::endl;
	  		fs.close();
 		 }else{
    		std::cout<< "Erro ao abrir o arquivo - confira o local e nome do arquivo"<<std::endl;
    		fs.close();
    		system("PAUSE");
  		}
	}

	std::list<Node*>* Jogo::geraListaAdjacencia(const unsigned int N, const unsigned int M){
		return new std::list<Node*>[N*M];
	}

	void Jogo::addArestas(int x, int y, int peso, int N, int M){
		std::cout<<"Se liga com:"<<std::endl;
		//std::list<Node*>* listaAdjacencia;
		if((x+peso)<=(N-1)){
			std::cout<<"X: "<<x+peso<<" Y: "<<y<<std::endl;
			(this->listaAdjacencia[(x+peso)*N + (y)]).push_back(new Node(x,y,peso));
		}if((x-peso)>=0){
			std::cout<<"X: "<<x-peso<<" Y: "<<y<<std::endl;
			(this->listaAdjacencia[(x-peso)*N + (y)]).push_back(new Node(x,y,peso));
			
		}if((y+peso)<=(M-1)){
			std::cout<<"X: "<<x<<" Y: "<<(y+peso)<<std::endl;
			(this->listaAdjacencia[(x*N) + (y+peso)]).push_back(new Node(x,y,peso));
			
		}if((y-peso)>=0){
			std::cout<<"X: "<<x<<" Y: "<<(y-peso)<<std::endl;
			(this->listaAdjacencia[(x*N) + (y-peso)]).push_back(new Node(x,y,peso));
		}
	}
}