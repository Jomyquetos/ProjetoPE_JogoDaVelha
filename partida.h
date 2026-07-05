#ifndef PARTIDA_H
#define PARTIDA_H

#include "tabuleiro.h"
#include "jogadorTeclado.h"
#include "jogadorIA.h"


typedef struct Partida
{
    Tabuleiro tabuleiro;

    JogadorTeclado jogador1;

    JogadorIA jogadorIA;
} Partida;

void configuraJogadores(Partida *p);

void inicia(Partida *p);

#endif