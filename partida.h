#ifndef PARTIDA_H
#define PARTIDA_H

#include "tabuleiro.h"
#include "jogadorTeclado.h"

typedef struct 
{
    Tabuleiro tabuleiro;

    JogadorTeclado jogador1;

    JogadorTeclado jogador2;
} Partida;

void configuraJogadores(Partida *p);

void inicia(Partida *p);

#endif