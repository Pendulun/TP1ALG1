#include "Jogo.hpp"

namespace Jogo{

	Jogo::Jogo(){
		this.listaJogadores = null;
		this.listaAdjacencia = nullptr;
	}

	void Jogo::configuraJogo(std::string arq_entrada){
		std::fstream fs;
		std::cout<<"Nome do Arquivo: "<<"'"<<arq_entrada<<"'"<<std::endl;
		fs.open(arq_entrada, std::fstream::in);
		if(fs.is_open()){
    		std::cout<< "Arquivo aberto com sucesso"<<std::endl;
    		int N=0;
	  		int M=0;
	  		int K=0;
	  		fs>>N;
	  		fs>>M;
	  		std::cout<<N<<" "<<M<<std::endl;
	  		fs>>K;
	  		std::cout<<K<<std::endl;
	  		std::string linha;
	  		for(int linha=0;linha<N;linha++){
	  			for(int coluna=0;coluna<M;coluna++){
	  				fs>>linha;
	  				std::cout<<linha<<" ";
	  			}
	  			std::cout<<std::endl;
	  		}
	  		std::string x,y;
	  		for(int jogador=0;jogador<K;jogador++){
	  			fs>>x;
	  			fs>>y;
	  			std::cout<<x<<" "<<y<<std::endl;
	  		}
	  		fs.close();
 		 }else{
    		std::cout<< "Erro ao abrir o arquivo - confira o local e nome do arquivo"<<std::endl;
    		fs.close();
    		system("PAUSE");
  		}
	}
}