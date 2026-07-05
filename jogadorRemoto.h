#ifndef JOGADOR_REMOTO_H
#define JOGADOR_REMOTO_H

typedef struct Tabuleiro Tabuleiro

    typedef struct
{
    int tipo;
} JogadorRemoto;

void conecta(char *ip, int porta);
void jogaRemota(struct JogadorRemoto *jr, Tabuleiro *t);
void aceitaConexao(int porta);
void enviaJogada(int linha, int coluna);

#endif