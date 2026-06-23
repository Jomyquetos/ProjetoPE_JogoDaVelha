#ifndef PARTIDA_H
#define PARTIDA_H

#include "tabuleiro.h"
#include "jogadorTeclado.h"

struct Partida
{
    struct Tabuleiro tabuleiro;

    struct JogadorTeclado jogador1;

    struct JogadorTeclado jogador2;
};

void configuraJogadores(struct Partida *p);

void inicia(struct Partida *p);

#endif