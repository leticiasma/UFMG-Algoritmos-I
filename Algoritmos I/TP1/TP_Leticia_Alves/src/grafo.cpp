#include "../includes/grafo.hpp"

using namespace std;

int Grafo::getM(){
	return this->M;
}
    
int Grafo::getN(){
  	return this->N;
}
    
int Grafo::getNumVertices(){
  	return this->numVertices;
}

vector<int>* Grafo::getValoresPulo(){
	return this->valoresPulo;
}

Grafo::Grafo(int M, int N, ifstream& entrada){
  	this-> M = M;
  	this-> N = N;
  	this-> numVertices = M*N;
  
  	this->listaAdj = new vector<list<int>>(numVertices, list<int>());
  	this->valoresPulo = new vector<int>(numVertices);
  
  	this->criaListaAdj(entrada);
}

Grafo::~Grafo(){
	delete(this->listaAdj);
	delete(this->valoresPulo);
}

void Grafo::criaListaAdj(ifstream& entrada){

	list<int>::iterator it;

	int valorPulo = -1;
	int i, j = -1;

		//Indice representa a posição no vetor (da lista de adjacência) na qual será represetado um vértice do tabuleiro 
	for(int indice=0; indice < numVertices; indice++){

		entrada>>valorPulo;
    	(*this->valoresPulo)[indice] = valorPulo;
    
    		/*Com base nos valores de pulo lidos para cada casa, define em quais outras posições é possível chegar 
    		(dentro dos limites do tabuleiro)*/
		if(valorPulo > 0){
				//Conversão do vértice representado na Lista de Adjacência para a representação de par (i,j) do tabuleiro
			j=indice%N;
			i=(indice-j)/N;

				//Movimentos na horizontal
			if(j-valorPulo >= 0){
				(*listaAdj)[indice].push_back((i*N)+(j-valorPulo));
			}
			if(j+valorPulo < N){
				(*listaAdj)[indice].push_back((i*N)+(j+valorPulo));
			}

				//Movimentos na vertical
			if(i-valorPulo >= 0){
				(*listaAdj)[indice].push_back(((i-valorPulo)*N)+j);
			}
			if(i+valorPulo < M){
				(*listaAdj)[indice].push_back(((i+valorPulo)*N)+j);
			}
		}
	}
}

vector<int> Grafo::BFS(int casaInicial, int casaFinal){
  	int noAtual = -1;
  	int penultimaCasa = -1;

  		//Valores que serão retornados para, posteriormente, serem atribuídos a um jogador
  	vector<int> parametrosJogador = vector<int>(3);

  	list<int>::iterator it;

  		//O nível da camada na BFS onde está cada nó
  	vector<int> camada = vector<int>(this->numVertices);
		//Se um nó já foi descoberto durante a BFS
	vector<bool> descobertos = vector<bool>(this->numVertices);
		//O nó que foi responsável pela descoberta de cada nó
	vector<int> pais = vector<int>(this->numVertices); 
		//Lista que funcionará como uma fila na descoberta e exploração de nós da BFS
	list<int> fila;
  
	for(int i=0; i < numVertices; i++){
    	camada[i] = -1;
    	pais[i] = -1;
	  	descobertos[i] = false;
	}   
	 
	descobertos[casaInicial] = true; 
	fila.push_back(casaInicial); 
	camada[casaInicial] = 0; 
	
  	while(!fila.empty()){ 
	   
	  	noAtual = fila.front(); 
	  	fila.pop_front(); 
	  	
	  		/*Percorre as listas de nós adjacentes de cada nó do grafo, adiciona nós que ainda não haviam sido descoberto na fila, 
	  		marca-os como descobertos e determina os níveis das camadas*/
	  	for (it = (*listaAdj)[noAtual].begin(); it != (*listaAdj)[noAtual].end(); it++){ 
	    	if (!descobertos[*it]){

        		pais[*it] = noAtual;

        		if(*it == casaFinal){
          			penultimaCasa = noAtual;
        		}

        		fila.push_back(*it);
        		descobertos[*it] = true;
	      		camada[*it] = camada[noAtual]+1;
	    	} 
	  	} 
	}
		
		//Se foi encontrado um caminho do nó da casaInicial para a casaFinal
	if(descobertos[casaFinal] == true){
    	parametrosJogador[0] = 1;
      	parametrosJogador[1] = camada[casaFinal] - camada[casaInicial];
      	parametrosJogador[2] = pais[penultimaCasa];

      	return parametrosJogador;
	} 
	else{
    	parametrosJogador[0] = 0;
      	parametrosJogador[1] = -1;
      	parametrosJogador[2] = -1;

      	return parametrosJogador;
	}
};