#include <string>
#include <exception>
#include <stdexcept>
#include <iostream>
#include <chrono>
#include "Jogo.hpp"
#define NUM_VEZES 10

int main(int argc, char *argv[]){
	if(argc>1){
		for(unsigned int i = 0;i<NUM_VEZES;i++){
			auto start = std::chrono::high_resolution_clock::now();
			std::string arq_entrada = argv[1];
			Jogo::Jogo* jogo = new Jogo::Jogo();
			jogo->configuraJogo(arq_entrada);
			jogo->ganhador();
			delete jogo;
			auto stop = std::chrono::high_resolution_clock::now();
			auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
			std::cout<<"Duracao: "<<duration.count()<<std::endl;
		}
		
	}else{
		std::cout<< "Nao foi detectado nenhum arquivo de entrada"<<std::endl;
	}
	return 0;
}