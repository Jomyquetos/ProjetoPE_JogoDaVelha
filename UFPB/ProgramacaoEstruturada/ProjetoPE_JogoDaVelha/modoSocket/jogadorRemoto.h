#ifndef JOGADOR_REMOTO_H
#define JOGADOR_REMOTO_H

#include "tabuleiro.h"

typedef struct
{
    int socket_fd;
    int tipo; 
} JogadorRemoto;

void conecta(char *ip, int porta);
void aceitaConexao(int porta);

void enviaJogada(int linha, int coluna);
void jogaRemoto(JogadorRemoto *jr, Tabuleiro *t);

#endif