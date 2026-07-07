#include <stdio.h>
#include "tabuleiro.h"

void inicializaTabuleiro(Tabuleiro *t)
{
    int i, j;

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            t->M[i][j] = 0;
        }
    }
}

void desenha(Tabuleiro *t)
{
    printf("\033[2J\033[H");

    int i, j;

    printf("\n   0   1   2\n");

    for (i = 0; i < 3; i++)
    {
        printf("%d ", i);

        for (j = 0; j < 3; j++)
        {
            char simbolo = ' ';

            if (t->M[i][j] == 1)
                simbolo = 'O';

            else if (t->M[i][j] == 4)
                simbolo = 'X';

            printf(" %c ", simbolo);

            if (j < 2)
                printf("|");
        }

        printf("\n");

        if (i < 2)
            printf("  ---+---+---\n");
    }

    printf("\n");
}

void marcaJogada(Tabuleiro *t, int x, int y, int tipo)
{
    t->M[x][y] = tipo;
}

int temVencedor(Tabuleiro *t)
{
    int i, soma;

    for (i = 0; i < 3; i++)
    {
        soma = t->M[i][0] + t->M[i][1] + t->M[i][2];

        if (soma == 3)
            return 1;

        if (soma == 12)
            return 4;
    }

    for (i = 0; i < 3; i++)
    {
        soma = t->M[0][i] + t->M[1][i] + t->M[2][i];

        if (soma == 3)
            return 1;

        if (soma == 12)
            return 4;
    }

    soma = t->M[0][0] + t->M[1][1] + t->M[2][2];

    if (soma == 3)
        return 1;

    if (soma == 12)
        return 4;

    soma = t->M[0][2] + t->M[1][1] + t->M[2][0];

    if (soma == 3)
        return 1;

    if (soma == 12)
        return 4;

    return 0;
}