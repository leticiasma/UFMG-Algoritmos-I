#include "../includes/jogoDosDiamantes.hpp"

using namespace std;

int main(int argc, const char** argv){

  ifstream entrada = ifstream();

  if (argc > 1){
    entrada.open(argv[1]);

    if (entrada.is_open()){

      JogoDosDiamantes* jogo = new JogoDosDiamantes(entrada);      
      jogo->pesoRestante();

      delete jogo;

      entrada.close();
    }
    else{
      cout<<"Nao foi possivel abrir o arquivo."<<endl;
    }
  }
  else{
    cout<<"Arquivo nao informado."<<endl;
    exit(1);
  }

  return 0;
}