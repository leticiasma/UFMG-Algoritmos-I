class Jogador{
	private:
			//Casa na qual o jogador começa o jogo
	  	int posicaoInicial = -1;
	  		//Se, a partir da posicaoInicial, foi encontrado um caminho para o final do tabuleiro haCaminho receberá 1
	  	int haCaminho = 0;
	  		/*Receberá o tamanho do caminho (se houver) da posicaoInicial até o final do tabuleiro, isto é, 
	  		a quantidade de jogadas até chegar ao final*/
    	int tamCaminho = -1;
    		//Receberá qual foi a casa que se encontrava duas jogadas antes de poder chegar à última casa do tabuleiro
    	int penultimaCasa = -1;

    public:
    	int getPosicaoInicial();
    	int getHaCaminho();
    	int getTamCaminho();
    	int getPenultimaCasa();

    	void setPosicaoInicial(int posicaoInicial);
    	void setHaCaminho(int haCaminho);
    	void setTamCaminho(int tamCaminho);
    	void setPenultimaCasa(int penultimaCasa);
};
