#include "../includes/jogo.hpp"

Jogo::Jogo(int M, int N, int K, ifstream& entrada){
	this->tabuleiro = new Grafo(M, N, entrada);
  	this->jogadores = new vector<Jogador>(K);
}

Jogo::~Jogo(){
	delete(this->tabuleiro);
	delete(this->jogadores);
}

void Jogo::resultadoJogo(ifstream& entrada){
		//Guarda os valores de haCaminho, tamCaminho e penultimaCasa que serão atribuídos a cada jogador
	vector<int> parametrosJogador = vector<int>(3);

  	int idVencedor = -1;
  	int numVertices = this->tabuleiro->getNumVertices();
  	int N = this->tabuleiro->getN();
  	int K = this->jogadores->size();

  	int fimTabuleiro = (numVertices)-1;
  	int x, y, posicaoInicialJogador = -1;

  	for (int i=0; i < K; i++){
    	entrada>>x;
    	entrada>>y;
    	posicaoInicialJogador = (x*N)+y;

    	(*jogadores)[i].setPosicaoInicial(posicaoInicialJogador); 
    		//O BFS será realizado para cada jogador sendo os parâmentros a casa inicial do jogador e a última casa do tabuleiro
    	parametrosJogador = tabuleiro->BFS((*jogadores)[i].getPosicaoInicial(), fimTabuleiro);
    	(*jogadores)[i].setHaCaminho(parametrosJogador[0]);
    	(*jogadores)[i].setTamCaminho(parametrosJogador[1]);
    	(*jogadores)[i].setPenultimaCasa(parametrosJogador[2]);
  	}
  		//É realizada a comparação das situações finais dos jogadores para determinar o vencedor
  	for(int i=0; i < K; i++){
  			//Se há um caminho da posição inicial do jogador para a posição final do tabuleiro
    	if((*this->jogadores)[i].getHaCaminho() == 1){
    			//Se o tamanho do caminho (quantidade de arestas/jogadas) do jogador da iteração é menor do que o do atual vencedor
    			/*Ou idVencedor = i se idVencedor == -1, isto é, define como primeiro vencedor atual o primeiro jogador com 
    			haCaminho == 1 encontrado*/
      		if(idVencedor == -1 || (*this->jogadores)[i].getTamCaminho() < (*this->jogadores)[idVencedor].getTamCaminho()){
       			idVencedor = i;
      		}
      		else{
      				//Se houve empate entre os tamanhos de caminho
        		if((*this->jogadores)[i].getTamCaminho() == (*this->jogadores)[idVencedor].getTamCaminho()){
        				/*Se a penultima casa na qual o jogador da iteração esteve antes da última 
        				(isto é, duas antes da última) possuia um valor de pulo menor do que o do vencedor atual*/
          			if((*this->tabuleiro->getValoresPulo())[(*this->jogadores)[i].getPenultimaCasa()] < (*this->tabuleiro->getValoresPulo())[(*this->jogadores)[idVencedor].getPenultimaCasa()]){
            			idVencedor = i;
          			}
          			else{
          					//Se houve empate entre os valores de pulo das penultimas casas
            			if((*this->tabuleiro->getValoresPulo())[(*this->jogadores)[i].getPenultimaCasa()] == (*this->tabuleiro->getValoresPulo())[(*this->jogadores)[idVencedor].getPenultimaCasa()]){
              					//Se o jogador da iteração jogou antes do atual vencedor na primeira rodada do jogo
              				if(i<idVencedor){
                				idVencedor = i;
              				}
            			}
          			}
      			}
    		}	
   		}
   	}

  	//Se houve algum vencedor
  if(idVencedor != -1){
    cout<<(char)('A'+idVencedor)<<endl<<(*jogadores)[idVencedor].getTamCaminho()<<endl;
  }
  else{
    cout<<"SEM VENCEDORES"<<endl;
  }
 
}