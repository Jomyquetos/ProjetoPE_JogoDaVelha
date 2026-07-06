#include <stdio.h>
#include "partida.h"
#include "jogadorRemoto.h"

#define LOCAL 0
#define REMOTO 1

void configuraJogadores(Partida *p)
{
    p->jogador1.tipo = 1; // O
    p->jogador2.tipo = 4; // X: jogador remoto
}

void acharJogada(Partida *p, int vez)
{
    if (vez == LOCAL)
    {
        joga(&p->jogador1, &p->tabuleiro);
    }
    else
    {
        jogaRemoto(&p->jogador2, &p->tabuleiro);
    }
}

void inicia(Partida *p)
{
    int vencedor = 0;
    int jogadas = 0;

    inicializaTabuleiro(&p->tabuleiro);

    while (vencedor == 0 && jogadas < 9)
    {
        desenha(&p->tabuleiro);

        acharJogada(p, REMOTO);
        jogadas++;
        vencedor = temVencedor(&p->tabuleiro);

        if (vencedor != 0 || jogadas == 9)
            break;

        desenha(&p->tabuleiro);

        acharJogada(p, LOCAL);
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