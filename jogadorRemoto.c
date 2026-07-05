#include "jogadorRemoto.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORTA 8080
#define TAM_BUFFER 1024

int main()
{

    int socket_fd;
    struct sockaddr_in endereco;
    char buffer[TAM_BUFFER];

    void conecta()
    {
        socket_fd = socket(AF_INET, SOCK_STREAM, 0);

        if (socket_fd < 0)
        {
            perror("Erro ao criar socket");
            exit(EXIT_FAILURE);
        }

        endereco.sin_family = AF_INET;
        endereco.sin_port = htons(PORTA);

        if (inet_pton(AF_INET, "127.0.0.1", &endereco.sin_addr) <= 0)
        {
            perror("Endereco invalido");
            close(socket_fd);
            exit(EXIT_FAILURE);
        }

        if (connect(socket_fd, (struct sockaddr *)&endereco,
                    sizeof(endereco)) < 0)
        {
            perror("Erro ao conectar");
            close(socket_fd);
            exit(EXIT_FAILURE);
        }

        printf("Conectado ao servidor!\n");
    }

    void accept()
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
        endereco.sin_port = htons(PORTA);

        bind(servidor_fd,
             (struct sockaddr *)&endereco,
             sizeof(endereco));

        listen(servidor_fd, 1);

        printf("Aguardando conexao...\n");

        socket_fd = accept(servidor_fd,
                           (struct sockaddr *)&endereco,
                           &tamanho);

        printf("Cliente conectado!\n");
    }
}
}