#include <stdio.h>
#include "jogadorIA.h"
#include "partida.h"

void jogaIA(Partida *p, Tabuleiro *t)
{
    int jogadaFeita;

    jogadaFeita = r1EvitaDerrota(p, t);
    if (jogadaFeita == 0)
        jogadaFeita = r2CriaDuasSequencias(p, t);
    else if (jogadaFeita == 0)
        jogadaFeita = r3CentroLivre(p, t);
    else if (jogadaFeita == 0)
        jogadaFeita = r4CantoOposto(p, t);
    else if (jogadaFeita == 0)
        jogadaFeita = r5CantoVazio(p, t);
    else
        jogadaFeita = r6QuadradoVazio(p, t);
} 

int r1EvitaDerrota(Partida *p, Tabuleiro *t){
        int i, j, soma, rival;
        rival= p->jogador2.tipo *2;

        for (i = 0; i < 3; i++)
        {
            for (j=0; i<3; i++){
                soma = t->M[i][0] + t->M[i][1] + t->M[i][2];
                if (soma == rival){
                    if (t->M[i][0]==0){
                        marcaJogada(t, i, 0, p->jogadorIA.tipo);
                    }
                    else if (t->M[i][1]==0){
                        marcaJogada(t, i, 1, p->jogadorIA.tipo);
                    }
                    else{
                        marcaJogada(t, i, 2, p->jogadorIA.tipo);
                    }
                    return 1;
                }
            }
        return 0;
    }
}

int r2CriaDuasSequencias(Partida *p, Tabuleiro *t){
    int i, j, soma, tipo;
    tipo= p->jogador2.tipo;

    for (i = 0; i < 3; i++)
    {
        for (j=0; i<3; i++){
            soma = t->M[i][0] + t->M[i][1] + t->M[i][2];
            if (soma == tipo){
                if (t->M[i][0]==0){
                    marcaJogada(t, i, 0, p->jogadorIA.tipo);
                }
                else if (t->M[i][1]==0){
                    marcaJogada(t, i, 1, p->jogadorIA.tipo);
                }
                else{
                    marcaJogada(t, i, 2, p->jogadorIA.tipo);
                }
                return 1;
            }
        }
    return 0;    
    }
}

int r3CentroLivre(Partida *p, Tabuleiro *t){
    int tipo= p->jogadorIA.tipo;

    if (t->M[2][2]==0){
        marcaJogada(t, 2, 2, tipo);
        return 1;
    }

    return 0;
}
