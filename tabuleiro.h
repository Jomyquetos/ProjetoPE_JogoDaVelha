#ifndef TABULEIRO_H
#define TABULEIRO_H

typedef struct 
{
    int M[3][3];
} Tabuleiro;

void inicializaTabuleiro(Tabuleiro *t);

void desenha(Tabuleiro *t);

void marcaJogada(Tabuleiro *t, int x, int y, int tipo);

int temVencedor(Tabuleiro *t);

#endif