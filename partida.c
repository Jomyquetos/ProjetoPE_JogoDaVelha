#include <stdio.h>
#include "partida.h"

void configuraJogadores(struct Partida *p)
{
    p->jogador1.tipo = 1; // O

    p->jogador2.tipo = 4; // X
}

void inicia(struct Partida *p)
{
    int vencedor = 0;
    int jogadas = 0;

    inicializaTabuleiro(&p->tabuleiro);

    while (vencedor == 0 && jogadas < 9)
    {
        desenha(&p->tabuleiro);

        joga(&p->jogador1, &p->tabuleiro);

        jogadas++;

        vencedor = temVencedor(&p->tabuleiro);

        if (vencedor != 0 || jogadas == 9)
            break;

        desenha(&p->tabuleiro);

        joga(&p->jogador2, &p->tabuleiro);

        jogadas++;

        vencedor = temVencedor(&p->tabuleiro);
    }

    desenha(&p->tabuleiro);

    if (vencedor == 1)
        printf("Jogador O venceu!\n");

    else if (vencedor == 4)
        printf("Jogador X venceu!\n");

    else
        printf("Empate!\n");
}