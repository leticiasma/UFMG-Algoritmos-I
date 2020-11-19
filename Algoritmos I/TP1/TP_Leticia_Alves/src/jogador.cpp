#include "../includes/jogador.hpp"

int Jogador::getPosicaoInicial(){
	return this->posicaoInicial;
}

int Jogador::getHaCaminho(){
	return this->haCaminho;
}

int Jogador::getTamCaminho(){
	return this->tamCaminho;
}

int Jogador::getPenultimaCasa(){
	return this->penultimaCasa;
}

void Jogador::setPosicaoInicial(int posicaoInicial){
	this->posicaoInicial = posicaoInicial;
}

void Jogador::setHaCaminho(int haCaminho){
	this->haCaminho = haCaminho;
}

void Jogador::setTamCaminho(int tamCaminho){
	this->tamCaminho = tamCaminho;
}

void Jogador::setPenultimaCasa(int penultimaCasa){
	this->penultimaCasa = penultimaCasa;
}