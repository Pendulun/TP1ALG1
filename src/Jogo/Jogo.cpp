#include "Jogo.hpp"

namespace Jogo{

	Jogo::Jogo(){
		this->listaJogadores = new std::list<Jogador*>;
		this->listaAdjacencia = nullptr;
		this->N=0;
		this->M=0;
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
	  		unsigned int K=0;
	  		fs>>this->N;
	  		fs>>this->M;
	  		this->listaAdjacencia = geraListaAdjacencia();
	  		std::cout<<this->N<<" "<<this->M<<std::endl;
	  		fs>>K;
	  		std::cout<<K<<std::endl;
	  		std::string peso;
	  		for(unsigned int linha=0;linha<this->N;linha++){
	  			for(unsigned int coluna=0;coluna<this->M;coluna++){
	  				fs>>peso;
	  				std::cout<<"Linha: "<<linha<<" Coluna: "<<coluna<<" Peso: "<<std::stoi(peso)<<" ";
	  				addArestas(linha,coluna,std::stoi(peso),this->N,this->M);
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

	std::list<Node*>* Jogo::geraListaAdjacencia(){
		return new std::list<Node*>[this->N*this->M];
	}

	void Jogo::addArestas(int x, int y, int peso){
		std::cout<<"Se liga com:"<<std::endl;
		//std::list<Node*>* listaAdjacencia;
		if((x+peso)<=(this->N-1)){
			int posicao = (x+peso)*this->N + (y);
			std::cout<<"X: "<<x+peso<<" Y: "<<y<<" Posicao: "<<posicao<<std::endl;
			(this->listaAdjacencia[posicao]).push_back(new Node(x,y,peso));
		}if((x-peso)>=0){
			int posicao = (x-peso)*this->N + (y);
			std::cout<<"X: "<<x-peso<<" Y: "<<y<<" Posicao: "<<posicao<<std::endl;
			(this->listaAdjacencia[posicao]).push_back(new Node(x,y,peso));
			
		}if((y+peso)<=(this->M-1)){
			int posicao = (x*this->N) + (y+peso);
			std::cout<<"X: "<<x<<" Y: "<<(y+peso)<<" Posicao: "<<posicao<<std::endl;
			(this->listaAdjacencia[posicao]).push_back(new Node(x,y,peso));
			
		}if((y-peso)>=0){
			int posicao = (x*this->N) + (y-peso);
			std::cout<<"X: "<<x<<" Y: "<<(y-peso)<<" Posicao: "<<posicao<<std::endl;
			(this->listaAdjacencia[posicao]).push_back(new Node(x,y,peso));
		}
	}


	void Jogo::ganhador(){
		BFS();
	}

	void Jogo::BFS(){
		bool Descobertos[this->N*this->M];
		Descobertos[((this->N)*(this->M))-1]=true;
		for(int i=0;i<(this->N*this->M)-2;i++){
			Descobertos[i]=false;
		} 
		////////////////////////CONTINUAR DAQUI
		std::list<std::list<Node>> listaDeListas;
		std::list<Node> primeiraLista;
		// Node(this->N-1,this->M-1)
		primeiraLista.push_back()
	}
}