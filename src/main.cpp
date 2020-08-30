#include <string>
#include <exception>
#include <stdexcept>
#include "Jogo.hpp"

int main(int argc, char *argv[]){
	if(argc>1){
		std::string arq_entrada = argv[1];
		Jogo::Jogo* jogo = new Jogo::Jogo();
		jogo->configuraJogo(arq_entrada);
		jogo->ganhador();
		delete jogo;
	}else{
		std::cout<< "Nao foi detectado nenhum arquivo de entrada"<<std::endl;
	}
	return 0;
}