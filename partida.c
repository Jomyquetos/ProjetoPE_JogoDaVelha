#include <stdio.h>
#include "partida.h"

void configuraJogadores(Partida *p)
{
    char aux;
    printf("Jogador 1, escolha seu símbolo (O ou X): ");
    scanf(" %c", &aux);

    if(aux == 'O' || aux == 'o'){
        p->jogador1.tipo = 1; // O
        p->jogador2.tipo = 4; // X
    }
    else{
        p->jogador1.tipo = 4; // X
        p->jogador2.tipo = 1; // O
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