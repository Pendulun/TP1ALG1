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
	  				addArestas(linha,coluna,std::stoi(peso));
	  			}
	  			std::cout<<std::endl;
	  		}

	  		//std::list<Node*>* listaAdjacencia
	  		std::list<Node*>::iterator iterador;
	  		for(int count = 0; count<(N*M);count++){
	  			std::cout<<"Elementos da lista: "<<count<<std::endl;
	  			for(iterador = ((this->listaAdjacencia)[count]).begin();
	  				iterador!=((this->listaAdjacencia)[count]).end();
	  				iterador++){
	  				std::cout<<"X: "<<(*iterador)->getX();
	  				std::cout<<" Y: "<<(*iterador)->getY();
	  				std::cout<<" Peso: "<<(*iterador)->getPeso()<<std::endl;

	  			}
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
		std::cout<<"Ganhador"<<std::endl;
		BFS();
	}

	void Jogo::BFS(){
		std::cout<<"BFS"<<std::endl;
		bool Descobertos[this->N*this->M];
		//Descobertos
		Descobertos[((this->N)*(this->M))-1]=true;
		for(int i=0;i<(this->N*this->M)-2;i++){
			Descobertos[i]=false;
		} 
		std::cout<<"A"<<std::endl;
		//Quem achou quem
		std::pair< int,int> achadoPor[this->N*this->M];
		for(int i=0;i<(this->N*this->M);i++){
			std::pair< int, int> zera = std::make_pair (-1,-1);
			achadoPor[i]= zera;
		}
		std::cout<<"B"<<std::endl;
		std::list<std::list<Node>> listaDeListas;
		std::list<std::list<Node>>::iterator iteradorListaListas;
		std::list<Node> primeiraLista;
		Node final = Node(this->N,this->M,0);
		primeiraLista.push_back(final);
		listaDeListas.push_back(primeiraLista);
		std::cout<<"C"<<std::endl;
		unsigned int camadas=0;
		iteradorListaListas = listaDeListas.begin();
		std::cout<<"D"<<std::endl;
		while(!(*iteradorListaListas).empty()){
			std::cout<<"E"<<std::endl;
			std::list<Node> novaCamada;
			std::list<Node>::iterator iteradorLista;
			for(iteradorLista=(*iteradorListaListas).begin();iteradorLista!=(*iteradorListaListas).end();iteradorLista++){
				std::cout<<"F"<<std::endl;
				std::list<Node*>::iterator iteradorAdjacencia;
				unsigned int posicaoListaAdjacencia = ((*iteradorLista).getX()*this->N) + ((*iteradorLista).getY());
				for(iteradorAdjacencia = ((this->listaAdjacencia)[posicaoListaAdjacencia]).begin();
	  				iteradorAdjacencia!=((this->listaAdjacencia)[posicaoListaAdjacencia]).end();
	  				iteradorAdjacencia++){
					std::cout<<"G"<<std::endl;
					unsigned int posicaoDescoberto = ((*iteradorAdjacencia)->getX()*this->N) + ((*iteradorAdjacencia)->getY());
					std::cout<<"Analisando posicao: "<<posicaoDescoberto<<std::endl;
	  				if(!Descobertos[posicaoDescoberto]){
	  					std::cout<<"H"<<std::endl;
	  					Descobertos[posicaoDescoberto]=true;
	  					achadoPor[posicaoDescoberto]= std::make_pair((*iteradorAdjacencia)->getX(),(*iteradorAdjacencia)->getY());
	  					novaCamada.push_back(*(*iteradorAdjacencia));
	  				}
	  				std::cout<<"I"<<std::endl;
	  			}
			}
			listaDeListas.push_back(novaCamada);
			camadas++;
			std::cout<<"J"<<std::endl;
		}
		std::cout<<"Quem achou quem: "<<std::endl;
		//std::pair< int,int> achadoPor
		for(int it = 0;it<this->N*this->M;it++){
			std::cout<<"Posicao: "<<it<<std::endl;
			std::cout<<"Achado por: X:"<<achadoPor[it].first;
			std::cout<<" Y: "<<achadoPor[it].second<<std::endl;
		}
	}
}