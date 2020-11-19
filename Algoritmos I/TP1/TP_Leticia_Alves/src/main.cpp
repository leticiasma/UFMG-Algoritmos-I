#include "../includes/jogo.hpp"
#include <fstream>

using namespace std;

int main(int argc, const char** argv){

  int M, N, K = 0;
  ifstream entrada = ifstream();

  if(argc > 1){
    entrada.open(argv[1]);
  }
  else{
    exit(1);
  }
    //M, N e K são, respectivamente, o número de linhas e colunas do tabuleiro e o número de jogadores
  entrada>>M;
  entrada>>N;
  entrada>>K;

	Jogo* jogo = new Jogo(M, N, K, entrada);
  jogo->resultadoJogo(entrada);

  delete(jogo);
  
  entrada.close();
	
	return 0;
}