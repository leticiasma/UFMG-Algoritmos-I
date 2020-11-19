#include <iostream>
#include <fstream>

using namespace std;

class JogoDosDiamantes{
  public:
    JogoDosDiamantes(ifstream& entrada);
    ~JogoDosDiamantes();
  
  	void pesoRestante();
  	
  private:
  	int numDiamantes = 0;
    int* pesosDiamantes = nullptr;
};