#include "Jogo.hpp"

namespace Jogo{

	Jogo::Jogo(){
		this->listaJogadores = new std::list<Jogador*>;
		this->listaAdjacencia = nullptr;
		this->arvore=nullptr;
		this->N=0;
		this->M=0;
	}

	Jogo::~Jogo(){
		delete this->listaAdjacencia;
		delete this->listaJogadores;
		delete this->arvore;
	}

	void Jogo::configuraJogo(std::string arq_entrada){
		std::fstream fs;
		std::cout<<"Nome do Arquivo: "<<"'"<<arq_entrada<<"'"<<std::endl;
		fs.open(arq_entrada, std::fstream::in);
		if(fs.is_open()){
    		std::cout<< "Arquivo aberto com sucesso"<<std::endl;
	  		unsigned int K=0;
	  		fs>>this->M;
	  		fs>>this->N;
	  		this->listaAdjacencia = geraListaAdjacencia();
	  		std::cout<<"M: "<<this->M<<" N: "<<this->N<<std::endl;
	  		fs>>K;
	  		std::cout<<K<<std::endl;
	  		std::string peso;
	  		for(unsigned int linha=0;linha<this->M;linha++){
	  			for(unsigned int coluna=0;coluna<this->N;coluna++){
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
		if(peso>0){
			if((x+peso)<=(this->M-1)){
				int posicao = (x+peso)*this->N + (y);
				std::cout<<"X: "<<x+peso<<" Y: "<<y<<" Posicao: "<<posicao<<std::endl;
				(this->listaAdjacencia[posicao]).push_back(new Node(x,y,peso));
			}if((x-peso)>=0){
				int posicao = (x-peso)*this->N + (y);
				std::cout<<"X: "<<x-peso<<" Y: "<<y<<" Posicao: "<<posicao<<std::endl;
				(this->listaAdjacencia[posicao]).push_back(new Node(x,y,peso));
			}if((y+peso)<=(this->N-1)){
				int posicao = (x*this->N) + (y+peso);
				std::cout<<"X: "<<x<<" Y: "<<(y+peso)<<" Posicao: "<<posicao<<std::endl;
				(this->listaAdjacencia[posicao]).push_back(new Node(x,y,peso));
			}if((y-peso)>=0){
				int posicao = (x*this->N) + (y-peso);
				std::cout<<"X: "<<x<<" Y: "<<(y-peso)<<" Posicao: "<<posicao<<std::endl;
				(this->listaAdjacencia[posicao]).push_back(new Node(x,y,peso));
			}
		}
	}


	void Jogo::ganhador(){
		std::cout<<"Ganhador"<<std::endl;
		BFS();
		Jogador* vencedor = pegarMenor();
		if(vencedor!=nullptr){
			std::cout<<vencedor->getNome()<<std::endl;
			std::cout<<vencedor->getTamCaminho();
		}else{
			std::cout<<"SEM VENCEDORES"<<std::endl;
		}
	}

	void Jogo::BFS(){
		std::cout<<"BFS"<<std::endl;
		//Descobertos
		bool Descobertos[this->N*this->M];
		Descobertos[((this->N)*(this->M))-1]=true;
		for(int i=0;i<(this->N*this->M)-2;i++){
			Descobertos[i]=false;
		} 
		std::cout<<"A"<<std::endl;

		//Árvore T em formato de vetor
		this->arvore = new std::pair<int,int>[this->N*this->M];
		for(int i=0;i<(this->N*this->M);i++){
			std::pair< int, int> zera = std::make_pair (-1,-1);
			arvore[i]= zera;
		}
		std::cout<<"B"<<std::endl;

		//Lista de listas
		std::list<std::list<Node>> listaDeListas;
		std::list<std::list<Node>>::iterator iteradorListaListas;

		//L[0]
		std::list<Node> primeiraLista;
			//Nó final/raiz
		Node final = Node(this->M-1,this->N-1,0);
		primeiraLista.push_back(final);
		listaDeListas.push_back(primeiraLista);
		iteradorListaListas = listaDeListas.begin();
		std::cout<<"C"<<std::endl;
		
		std::cout<<"D"<<std::endl;
		//Enquanto L[i] não for vazio
		while(!(*iteradorListaListas).empty()){
			std::cout<<"E"<<std::endl;
			//Nova L[i+1]
			std::list<Node> novaCamada;
			std::list<Node>::iterator iteradorLista;
			//Para cada nó u pertencente a L[i]
			for(iteradorLista=(*iteradorListaListas).begin();iteradorLista!=(*iteradorListaListas).end();iteradorLista++){
				std::cout<<"F"<<std::endl;
				std::list<Node*>::iterator iteradorAdjacencia;
				std::cout<<"F.1"<<std::endl;
				std::cout<<"No atual: X: "<<(*iteradorLista).getX()<<" Y: "<<(*iteradorLista).getY()<<std::endl;
				unsigned int posicaoListaAdjacencia = (((*iteradorLista).getX())*this->N) + ((*iteradorLista).getY());
				std::cout<<"Analisando posicao Adjacencia: "<<posicaoListaAdjacencia<<std::endl;
				//Cada aresta (u,v) incidente a u
				for(iteradorAdjacencia = ((this->listaAdjacencia)[posicaoListaAdjacencia]).begin();
	  				iteradorAdjacencia!=((this->listaAdjacencia)[posicaoListaAdjacencia]).end();
	  				iteradorAdjacencia++){
					std::cout<<"G"<<std::endl;
					unsigned int posicaoDescoberto = ((*iteradorAdjacencia)->getX()*this->N) + ((*iteradorAdjacencia)->getY());
					std::cout<<"Analisando posicao: "<<posicaoDescoberto<<std::endl;
					//Se v não tiver sido descoberto
	  				if(!Descobertos[posicaoDescoberto]){
	  					std::cout<<"H"<<std::endl;
	  					//Defina Descoberto[v]=true
	  					Descobertos[posicaoDescoberto]=true;
	  					this->arvore[posicaoDescoberto].first= (*iteradorLista).getX();
	  					this->arvore[posicaoDescoberto].second= (*iteradorLista).getY();
	  					//Adicione v à L[i+1]
	  					novaCamada.push_back(*(*iteradorAdjacencia));
	  				}
	  				std::cout<<"I"<<std::endl;
	  			}
			}
			//Coloca L[i+1] em L
			listaDeListas.push_back(novaCamada);
			iteradorListaListas++;
			std::cout<<"J"<<std::endl;
		}

		std::cout<<"Quem achou quem: "<<std::endl;
		for(int it = 0;it<this->N*this->M;it++){
			std::cout<<"Posicao: "<<it<<std::endl;
			std::cout<<"Achado por: X:"<<this->arvore[it].first;
			std::cout<<" Y: "<<this->arvore[it].second<<std::endl;
		}
	}

	Jogador* Jogo::pegarMenor(){
		std::cout<<"Analisando Jogadores"<<std::endl;
		//Fila dos jogadores de acordo com o tamanho do caminho e os critérios de desempate
		std::list<Jogador*>* filaFinal = new std::list<Jogador*>;
		for(auto iterador = (*this->listaJogadores).begin();iterador!=(*this->listaJogadores).end();iterador++){
			std::cout<<"Jogador Analisado: ";
			std::cout<<"Jogador: "<<(*iterador)->getNome()<<" X: "<<(*iterador)->getX()<<" Y: "<<(*iterador)->getY()<<std::endl;
			int distancia = calculaDistancia((*iterador));
			if(distancia!=NULL){
				std::cout<<"Jogador: "<<(*iterador)->getNome();
				std::cout<<"Distancia: "<<(*iterador)->getTamCaminho();
				std::cout<<"Peso penultima jogada: "<<(*iterador)->getPesoPenultimaJogada()<<std::endl;
				if((*filaFinal).empty()){
					(*filaFinal).push_back((*iterador));
				}else{
					for(auto it=(*filaFinal).begin();it!=(*filaFinal).end();it++){
						//Se o tamanho do analisado é maior
						if((*it)->getTamCaminho()>(*iterador)->getTamCaminho()){
							(*filaFinal).insert(it,(*iterador));
							break;
						//Se o tamanho do analisado é igual
						}else if((*it)->getTamCaminho()==(*iterador)->getTamCaminho()){
							//Se o penultimo peso do analisado é maior
							if((*it)->getPesoPenultimaJogada()>(*iterador)->getPesoPenultimaJogada()){
								(*filaFinal).insert(it,(*iterador));
								break;
								//Se o penultimo peso do analisado é igual
							}else if((*it)->getPesoPenultimaJogada()==(*iterador)->getPesoPenultimaJogada()){
								if((*it)->getOrdemPrimeiraJogada()>(*iterador)->getOrdemPrimeiraJogada()){
									(*filaFinal).insert(it,(*iterador));
									break;
								}
							}
						}
					}
				}
				
			}
		}
		return nullptr;
	}

	unsigned int Jogo::calculaDistancia(Jogador* jogador){
		unsigned int x = jogador->getX();
		unsigned int y = jogador->getY();
		unsigned int posicaoJogador = x*this->N + y;
		if(this->arvore[posicaoJogador].first!=-1){
				std::cout<<"Alcança Objetivo"<<std::endl;
				bool achou = false;
				unsigned int tamCaminho=0;
				unsigned int posAtual = posicaoJogador;
				unsigned int penultimoPeso = 0;
				unsigned int xAtual = x;
				unsigned int yAtual = y;
				//Percorre o caminho até chegar no final
				while(!achou){
					if(this->arvore[posAtual].first==this->M-1 && this->arvore[posAtual].second==this->N-1){
						tamCaminho++;
						jogador->setTamCaminho(tamCaminho);
						jogador->setPesoPenultimaJogada(penultimoPeso);
						achou=true;
					}else{
						tamCaminho++;
						//Descobre o peso do nó
						if(this->arvore[posAtual].first!=xAtual){
							if(this->arvore[posAtual].first>xAtual){
								penultimoPeso=this->arvore[posAtual].first-xAtual;
							}else{
								penultimoPeso=xAtual-this->arvore[posAtual].first;
							}
						}else{
							if(this->arvore[posAtual].second>yAtual){
								penultimoPeso=this->arvore[posAtual].second-yAtual;
							}else{
								penultimoPeso=yAtual-this->arvore[posAtual].second;
							}
						}
						//Atualiza a posição atual para comparar com a próxima
						xAtual=this->arvore[posAtual].first;
						yAtual=this->arvore[posAtual].second;
						//Nó seguinte
						posAtual = xAtual*this->N + yAtual;
					}
				}
				jogador->setTamCaminho(tamCaminho);
				jogador->setPesoPenultimaJogada(penultimoPeso);
				return tamCaminho;
		}else{
			std::cout<<"Não alcança Objetivo"<<std::endl;
			return NULL;
		}
	}
}