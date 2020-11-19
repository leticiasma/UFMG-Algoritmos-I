#include "../includes/jogoDosDiamantes.hpp"
#include <bits/stdc++.h>

using namespace std;

JogoDosDiamantes::JogoDosDiamantes(ifstream& entrada){
  entrada >> this->numDiamantes;
  this->pesosDiamantes = new int[this->numDiamantes];

  int peso = 0;

  for(int i=0; i<this->numDiamantes; i++){
    entrada >> peso;
    pesosDiamantes[i] = peso;
  }
}

JogoDosDiamantes::~JogoDosDiamantes(){
  delete[] this->pesosDiamantes;
}

void JogoDosDiamantes::pesoRestante(){
  int somaPesosTotal = 0;
  int pesoRestante = INT_MAX;

  for (int i=0; i<this->numDiamantes; i++){
    somaPesosTotal += this->pesosDiamantes[i]; 
  }

  int numLinhas = this->numDiamantes+1;
  int numColunas = (somaPesosTotal/2)+1;

  bool** tabelaPD = new bool*[numLinhas];

  for(int i=0; i<numLinhas; i++){
    tabelaPD[i] = new bool[numColunas];
  }
  
  //Pois é possível obter soma 0 com qualquer subconjunto de pesos. Basta que nenhum participe da soma.
  for (int l=0; l<numLinhas; l++){
    tabelaPD[l][0] = true;
  }

  //Pois não é possível obter alguma soma diferente de 0 com um conjunto vazio de elementos
  for (int c=1; c<numColunas; c++){
    tabelaPD[0][c] = false;
  }

  /*Se tabelaPD[l-1][c] é false, tabelaPD[l][c] poderá receber true se this->pesosDiamantes[l-1] <= c e tabelaPD[l-1][c - this->pesosDiamantes[l-1]] for true,
  já que, se era possível somar c-this->pesosDiamantes[l-1] com os elementos anteriores ao que será adicionado agora, ao adicionnar o elemento ao conjunto,
  será possível somar c. Isso é melhor explicado com um exemplo na documentação do trabalho.*/
  for (int l=1; l<numLinhas; l++){
    for (int c=1; c<numColunas; c++){
      tabelaPD[l][c] = tabelaPD[l-1][c];

      if (tabelaPD[l][c] == 0 && this->pesosDiamantes[l-1] <= c){
        tabelaPD[l][c] = tabelaPD[l-1][c - this->pesosDiamantes[l-1]]; 
      }
    }
  }

  /*Quando o primeiro true for encontrado durante a iteração, significa que foi possível encontrar uma soma igual a c utilizando todos os elementos do conjunto.
  Para saber a solução ótima, basta subtrair essa soma encontrada para o subconjunto 1 da soma restante do subconjunto 2. Essa ideia também é melhor explicada
  com um exemplo na documentação do trabalho.*/
  int somaSubconjunto1, somaSubconjunto2 = 0;
  for (int c=somaPesosTotal/2; c>=0; c--){
    if (tabelaPD[this->numDiamantes][c] == true){
      somaSubconjunto1 = c;
      somaSubconjunto2 = somaPesosTotal - c;
      pesoRestante = abs(somaSubconjunto2 - somaSubconjunto1); //pesoRestante = somaPesosTotal - (2*c);

      break;
    }
  }

  cout<<pesoRestante<<endl;

  for(int i=0; i<numLinhas; i++){
    delete[] tabelaPD[i];
  }
  delete[] tabelaPD;
}