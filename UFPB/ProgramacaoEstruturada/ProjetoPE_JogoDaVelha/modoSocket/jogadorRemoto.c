#include "jogadorRemoto.h"


#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h> 

#include <stdio.h>
#include <stdlib.h>


int socket_fd;
struct sockaddr_in endereco;

void conecta(char *ip, int porta)
{
    socket_fd = socket(AF_INET, SOCK_STREAM, 0);


    if (socket_fd < 0)
    {
        perror("Erro ao criar socket");
        exit(EXIT_FAILURE);
    }

    endereco.sin_family = AF_INET;
    endereco.sin_port = htons(porta);

    endereco.sin_addr.s_addr = inet_addr(ip);
    if (endereco.sin_addr.s_addr == INADDR_NONE)
    {
        printf("Endereco IP invalido.\n");
        close(socket_fd);
        exit(EXIT_FAILURE);
    }

    if (connect(socket_fd, (struct sockaddr *)&endereco, sizeof(endereco)) < 0)
    {
        perror("Erro ao conectar");
        close(socket_fd);
        exit(EXIT_FAILURE);
    }

    printf("Conectado ao servidor!\n");
}

void aceitaConexao(int porta)
{
    int servidor_fd;
    socklen_t tamanho = sizeof(endereco);

    servidor_fd = socket(AF_INET, SOCK_STREAM, 0);

    if (servidor_fd < 0)
    {
        perror("Erro ao criar socket servidor");
        exit(EXIT_FAILURE);
    }

    endereco.sin_family = AF_INET;
    endereco.sin_addr.s_addr = INADDR_ANY;
    endereco.sin_port = htons(porta);

    if (bind(servidor_fd, (struct sockaddr *)&endereco, sizeof(endereco)) < 0)
    {
        perror("Erro no bind");
        close(servidor_fd);
        exit(EXIT_FAILURE);
    }

    if (listen(servidor_fd, 1) < 0)
    {
        perror("Erro no listen");
        close(servidor_fd);
        exit(EXIT_FAILURE);
    }

    printf("Aguardando conexao...\n");

    socket_fd = accept(servidor_fd, (struct sockaddr *)&endereco, &tamanho);

    if (socket_fd < 0)
    {
        perror("Erro no accept");
        close(servidor_fd);
        exit(EXIT_FAILURE);
    }

    printf("Cliente conectado!\n");

    close(servidor_fd); 
}

void enviaJogada(int linha, int coluna)
{
    send(socket_fd, &linha, sizeof(int), 0);
    send(socket_fd, &coluna, sizeof(int), 0);
}

void jogaRemoto(JogadorRemoto *jr, Tabuleiro *t)
{
    int linha;
    int coluna;

    if (recv(socket_fd, &linha, sizeof(int), 0) <= 0)
    {
        printf("Erro ao receber linha ou conexao encerrada.\n");
        return;
    }

    if (recv(socket_fd, &coluna, sizeof(int), 0) <= 0)
    {
        printf("Erro ao receber coluna ou conexao encerrada.\n");
        return;
    }

    marcaJogada(t, linha, coluna, jr->tipo);
}