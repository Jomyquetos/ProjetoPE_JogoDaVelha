#ifndef JOGADOR_REMOTO_H
#define JOGADOR_REMOTO_H

#include "tabuleiro.h"

typedef struct
{
    int socket_fd;
} JogadorRemoto;

void conecta(char *ip, int porta);

void jogaRemoto(JogadorRemoto *jr, Tabuleiro *t);

void aceitaConexao(int porta);

void enviaJogada(int linha, int coluna);

#endif