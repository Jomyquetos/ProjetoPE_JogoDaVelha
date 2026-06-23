#ifndef JOGADOR_TECLADO_H
#define JOGADOR_TECLADO_H

#include "tabuleiro.h"

struct JogadorTeclado
{
    int tipo;
};

void joga(struct JogadorTeclado *j, struct Tabuleiro *t);

#endif