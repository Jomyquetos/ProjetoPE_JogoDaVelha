#include <stdio.h>
#include "partida.h"
#include "jogadorRemoto.h"

#define LOCAL 0
#define REMOTO 1

void configuraJogadores(Partida *p, int tipoLocal, int tipoRemoto)
{
    p->jogador1.tipo = tipoLocal; 
    p->jogador2.tipo = tipoRemoto; 
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

void inicia(Partida *p, int quem_comeca)
{
    int vencedor = 0;
    int jogadas = 0;
    
    int turno_atual = quem_comeca;

    inicializaTabuleiro(&p->tabuleiro);

    while (vencedor == 0 && jogadas < 9)
    {
        desenha(&p->tabuleiro);

        acharJogada(p, turno_atual);
        jogadas++;
        vencedor = temVencedor(&p->tabuleiro);

        if (turno_atual == LOCAL) {
            turno_atual = REMOTO;
        } else {
            turno_atual = LOCAL;
        }
    }

    desenha(&p->tabuleiro);

    if (vencedor == 1)
        printf("Jogador O venceu!\n");
    else if (vencedor == 4)
        printf("Jogador X venceu!\n");
    else
        printf("Empate!\n");
}