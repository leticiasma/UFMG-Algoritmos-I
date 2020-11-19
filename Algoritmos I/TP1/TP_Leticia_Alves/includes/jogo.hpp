#include "./jogador.hpp"
#include "./grafo.hpp"

class Jogo{
  	private:
	  	vector<Jogador>* jogadores = nullptr;
    	Grafo* tabuleiro = nullptr;

  	public:
    	Jogo(int M, int N, int K, ifstream& entrada);
		~Jogo();

    	void resultadoJogo(ifstream& entrada);
};