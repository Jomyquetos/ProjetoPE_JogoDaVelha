#ifndef PARTIDA_H
#define PARTIDA_H

#include "tabuleiro.h"
#include "jogadorTeclado.h"
#include "jogadorIA.h"

typedef struct 
{
    Tabuleiro tabuleiro;

    JogadorIA jogadorIA;

    JogadorTeclado jogador2;
} Partida;

void configuraJogadores(Partida *p);

void inicia(Partida *p);

#endif