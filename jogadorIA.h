#ifndef JOGADORIA_H
#define JOGADORIA_H

#include "tabuleiro.h"

typedef struct Partida Partida;

typedef struct
{   
    int tipo;
} JogadorIA;

void jogaIA(Partida *p, Tabuleiro *t);

int r1EvitaDerrota(Partida *p, Tabuleiro *t);

int r2CriaDuasSequencias(Partida *p, Tabuleiro *t);

int r3CentroLivre(Partida *p, Tabuleiro *t);

int r4CantoOposto(Partida *p, Tabuleiro *t);

int r5CantoVazio(Partida *p, Tabuleiro *t);

int r6QuadradoVazio(Partida *p, Tabuleiro *t);

#endif