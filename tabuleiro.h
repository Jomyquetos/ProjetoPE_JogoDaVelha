#ifndef TABULEIRO_H
#define TABULEIRO_H

struct Tabuleiro
{
    int M[3][3];
};

void inicializaTabuleiro(struct Tabuleiro *t);

void desenha(struct Tabuleiro *t);

void marcaJogada(struct Tabuleiro *t, int x, int y, int tipo);

int temVencedor(struct Tabuleiro *t);

#endif