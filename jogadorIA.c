#include "jogadorIA.h"
#include "partida.h"
#include <stdio.h>


void jogaIA(Partida *p, Tabuleiro *t)
{
    int jogadaFeita;

    jogadaFeita = r1EvitaDerrota(p, t);
    if (jogadaFeita == 0)
        jogadaFeita = r2CriaDuasSequencias(p, t);
    if (jogadaFeita == 0)
        jogadaFeita = r3CentroLivre(p, t);
    if (jogadaFeita == 0)
        jogadaFeita = r4CantoOposto(p, t);
    if (jogadaFeita == 0)
        jogadaFeita = r5CantoVazio(p, t);
    if (jogadaFeita == 0)
        jogadaFeita = r6QuadradoVazio(p, t);
} 

int r1EvitaDerrota(Partida *p, Tabuleiro *t){
    int i, j, soma, rival, tipo;
    rival= p->jogador1.tipo *2;
    tipo= p->jogadorIA.tipo *2;


    for (i = 0; i < 3; i++)
    {
        soma = t->M[i][0] + t->M[i][1] + t->M[i][2];
        if (soma == rival || soma == tipo){
            if (t->M[i][0]==0){
                marcaJogada(t, i, 0, p->jogadorIA.tipo);
                return 1;
            }
            if (t->M[i][1]==0){
                marcaJogada(t, i, 1, p->jogadorIA.tipo);
                return 1;
            }
            if(t->M[i][2]==0){
                marcaJogada(t, i, 2, p->jogadorIA.tipo);
                return 1;
            }
        }

        soma = t->M[0][i] + t->M[1][i] + t->M[2][i];
        if (soma == rival || soma == tipo){
            if (t->M[0][i]==0){
                marcaJogada(t, 0, i, p->jogadorIA.tipo);
                return 1;
            }
            if (t->M[1][i]==0){
                marcaJogada(t, 1, i, p->jogadorIA.tipo);
                return 1;
            }
            if(t->M[2][i]==0){
                marcaJogada(t, 2, i, p->jogadorIA.tipo);
                return 1;
            }
        }
    }

    soma = t->M[0][0] + t->M[1][1] + t->M[2][2];
    if (soma == rival || soma == tipo){
        if (t->M[0][0]==0){
            marcaJogada(t, 0, 0, p->jogadorIA.tipo);
            return 1;
        }
        if (t->M[1][1]==0){
            marcaJogada(t, 1, 1, p->jogadorIA.tipo);
            return 1;
        }
        if (t->M[2][2]==0){
            marcaJogada(t, 2, 2, p->jogadorIA.tipo);
            return 1;
        }
    }    

    soma = t->M[0][2] + t->M[1][1] + t->M[2][0];
    if (soma == rival || soma == tipo){
        if (t->M[0][2]==0){
            marcaJogada(t, 0, 2, p->jogadorIA.tipo);
            return 1;
        }
        if (t->M[1][1]==0){
            marcaJogada(t, 1, 1, p->jogadorIA.tipo);
            return 1;
        }
        if (t->M[2][0]==0){
            marcaJogada(t, 2, 0, p->jogadorIA.tipo);
            return 1;
        }
    }

    return 0;
}


int r2CriaDuasSequencias(Partida *p, Tabuleiro *t){
    int i, j, soma, tipo;
    tipo= p->jogadorIA.tipo;


    soma = t->M[0][0] + t->M[1][1] + t->M[2][2];
    if (soma == tipo){
        if (t->M[0][0]==0){
            marcaJogada(t, 0, 0, p->jogadorIA.tipo);
            return 1;
        }
        if (t->M[1][1]==0){
            marcaJogada(t, 1, 1, p->jogadorIA.tipo);
            return 1;
        }
        if (t->M[2][2]==0){
            marcaJogada(t, 2, 2, p->jogadorIA.tipo);
            return 1;
        }
    } 
    soma = t->M[0][2] + t->M[1][1] + t->M[2][0];
    if (soma == tipo){
        if (t->M[0][2]==0){
            marcaJogada(t, 0, 2, tipo);
            return 1;
        }
        if (t->M[1][1]==0){
            marcaJogada(t, 1, 1, tipo);
            return 1;
        }
        if (t->M[2][0]==0){
            marcaJogada(t, 2, 0, tipo);
            return 1;
        }
    }

    for (i = 0; i < 3; i++)
    {
        soma = t->M[i][0] + t->M[i][1] + t->M[i][2];
        if (soma == tipo){
            if (t->M[i][0]==0){
                marcaJogada(t, i, 0, tipo);
                return 1;
            }
            if (t->M[i][1]==0){
                marcaJogada(t, i, 1, tipo);
                return 1;
            }
            if (t->M[i][2]==0){
                marcaJogada(t, i, 2, tipo);
                return 1;
            }
        }

        soma = t->M[0][i] + t->M[1][i] + t->M[2][i];
        if (soma == tipo){
            if (t->M[0][i]==0){
                marcaJogada(t, 0, i, p->jogadorIA.tipo);
                return 1;
            }
            if (t->M[1][i]==0){
                marcaJogada(t, 1, i, p->jogadorIA.tipo);
                return 1;
            }
            if(t->M[2][i]==0){
                marcaJogada(t, 2, i, p->jogadorIA.tipo);
                return 1;
            }
        }
    }
    return 0;

}

int r3CentroLivre(Partida *p, Tabuleiro *t){
    int tipo= p->jogadorIA.tipo;

    if (t->M[1][1]==0){
        marcaJogada(t, 1, 1, tipo);
        return 1;
    }

    return 0;
}

int r4CantoOposto(Partida *p, Tabuleiro *t){
    int rival, tipo;
    rival= p->jogador1.tipo;
    tipo= p->jogadorIA.tipo;

    if (t->M[0][0]==rival){
        if (t->M[2][2]==0){
            marcaJogada(t, 2, 2, p->jogadorIA.tipo);
            return 1;
        }
    }
    if (t->M[2][2]==rival){
        if (t->M[0][0]==0){
            marcaJogada(t, 0, 0, p->jogadorIA.tipo);
            return 1;
        }
    }
    if (t->M[0][2]==rival){
        if (t->M[2][0]==0){
            marcaJogada(t, 2, 0, p->jogadorIA.tipo);
            return 1;
        }
    }
    if (t->M[2][0]==rival){
        if (t->M[0][2]==0){
            marcaJogada(t, 0, 2, p->jogadorIA.tipo);
            return 1;
        }
    }

    return 0;
}

int r5CantoVazio(Partida *p, Tabuleiro *t){
    int tipo;
    tipo= p->jogadorIA.tipo;

    if (t->M[0][0]==0){
        marcaJogada(t, 0, 0, tipo);
        return 1;
    }
    if (t->M[2][2]==0){
        marcaJogada(t, 2, 2, tipo);
        return 1;
    }
    if (t->M[0][2]==0){
        marcaJogada(t, 0, 2, tipo);
        return 1;
    }
    if (t->M[2][0]==0){
        marcaJogada(t, 2, 0, tipo);
        return 1;
    }

    return 0;
}

int r6QuadradoVazio(Partida *p, Tabuleiro *t){
    int i, j, tipo;
    tipo= p->jogadorIA.tipo;

    for (i=0; i<3; i++){
        for (j=0; j<3; j++){
            if (t->M[i][j]==0){
                marcaJogada(t, i, j, tipo);
                return 1;
            }
        }
    }
    return 0;
}