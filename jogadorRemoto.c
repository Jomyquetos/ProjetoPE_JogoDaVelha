#include "jogadorRemoto.h"

#define _WIN32_WINNT 0x0600
#include <winsock2.h>
#include <ws2tcpip.h>

#include <stdio.h>
#include <stdlib.h>

#pragma comment(lib, "ws2_32.lib")

int socket_fd;

struct sockaddr_in endereco;

void iniciaRede()
{
    WSADATA wsaData;
    int iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);

    if (iResult != 0)
    {
        printf("Falha ao inicializar Winsock: %d\n", iResult);
        exit(EXIT_FAILURE);
    }
}

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

    if (endereco.sin_addr.s_addr = inet_addr(ip))
    {
        perror("Endereco invalido");
        closesocket(socket_fd);
        exit(EXIT_FAILURE);
    }

    if (connect(socket_fd, (struct sockaddr *)&endereco, sizeof(endereco)) < 0)
    {
        perror("Erro ao conectar");
        closesocket(socket_fd);
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
        perror("Erro ao criar socket");
        exit(EXIT_FAILURE);
    }

    endereco.sin_family = AF_INET;
    endereco.sin_addr.s_addr = INADDR_ANY;
    endereco.sin_port = htons(porta);

    if (bind(servidor_fd, (struct sockaddr *)&endereco, sizeof(endereco)) < 0)
    {
        perror("Erro no bind");
        closesocket(servidor_fd);
        exit(EXIT_FAILURE);
    }

    if (listen(servidor_fd, 1) < 0)
    {
        perror("Erro no listen");
        closesocket(servidor_fd);
        exit(EXIT_FAILURE);
    }

    printf("Aguardando conexao...\n");

    socket_fd = accept(servidor_fd, (struct sockaddr *)&endereco, &tamanho);

    if (socket_fd < 0)
    {
        perror("Erro no accept");
        closesocket(servidor_fd);
        exit(EXIT_FAILURE);
    }

    printf("Cliente conectado!\n");

    closesocket(servidor_fd);
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
        printf("Erro ao receber linha.\n");
        return;
    }

    if (recv(socket_fd, &coluna, sizeof(int), 0) <= 0)
    {
        printf("Erro ao receber coluna.\n");
        return;
    }

    marcaJogada(t, linha, coluna, jr->tipo);
}

void finalizaRede()
{
    WSACleanup();
}