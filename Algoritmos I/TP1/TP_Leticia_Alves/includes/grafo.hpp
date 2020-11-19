#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <iterator>

using namespace std;

class Grafo{
    private:
            /*Respectivamente o número de linhas e colunas do tabuleiro e a quantidade de vértices do grafo 
            (que, no contexto, é um tabuleiro)*/
        int M, N, numVertices = 0;
            //Grafo representado como uma Lista de Adjacência
        vector<list<int>>* listaAdj = nullptr;
            //Guarda os valores de pulo de cada posição (vértice) no tabuleiro
        vector<int>* valoresPulo = nullptr;

        void criaListaAdj(ifstream& entrada);

    public:
        int getM();
        int getN();
        int getNumVertices();
        vector<int>* getValoresPulo();

            //Realiza a Busca em Largura (BFS) partindo de uma raiz (casaInicial) e tentando encontrar um caminho para casaFinal 
        vector<int> BFS(int casaInicial, int casaFinal);

        Grafo(int M, int N, ifstream& entrada);
	   ~Grafo();
};