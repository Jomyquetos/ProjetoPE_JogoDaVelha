#include <stdio.h>
#include "partida.h"


void configuraJogadores(Partida *p)
{
    char aux;
    printf("Jogador, escolha seu símbolo (O ou X): ");
    scanf(" %c", &aux);

    if(aux == 'O' || aux == 'o'){
        p->jogador1.tipo = 1; // O
        p->jogadorIA.tipo = 4; // X
    }
    else{
        p->jogador1.tipo = 4; // X
        p->jogadorIA.tipo = 1; // O
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

        joga(&p->jogador1, &p->tabuleiro);

        jogadas++;

        vencedor = temVencedor(&p->tabuleiro);

        if (vencedor != 0 || jogadas == 9)
            break;

        desenha(&p->tabuleiro);

        jogaIA(p, &p->tabuleiro);

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