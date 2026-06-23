#include <stdio.h>
#include "jogadorTeclado.h"

void joga(JogadorTeclado *j, Tabuleiro *t)
{
    int linha, coluna;

    do
    {
        if (j->tipo == 1)
            printf("Jogador O\n");
        else
            printf("Jogador X\n");

        printf("Linha: ");
        scanf("%d", &linha);

        printf("Coluna: ");
        scanf("%d", &coluna);

    } while (linha < 0 || linha > 2 ||
             coluna < 0 || coluna > 2 ||
             t->M[linha][coluna] != 0);

    marcaJogada(t, linha, coluna, j->tipo);
}