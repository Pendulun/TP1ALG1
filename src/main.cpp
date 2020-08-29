
#include <fstream> 
#include <string>
#include <exception>
#include <stdexcept>
#include <iostream>

int main(int argc, char *argv[]){
	if(argc>1){
		std::string arq_entrada = argv[1];
		std::fstream fs;
		fs.open(arq_entrada, std::fstream::in);
		if(fs.is_open()){
    		std::cout<< "Arquivo aberto com sucesso"<<std::endl;
    		std::cout<< "Nome do Arquivo: "<<arq_entrada<<std::endl;
 		 }else{
    		std::cout<< "Erro ao abrir o arquivo - confira o local e nome do arquivo"<<std::endl;
    		fs.close();
    		system("PAUSE");
    		return -1;
  		}
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
		std::cout<< "Nao foi detectado nenhum arquivo de entrada"<<std::endl;
	}
	return 0;
}