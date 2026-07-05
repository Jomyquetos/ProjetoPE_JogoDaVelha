#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORTA 8080
#define TAM_BUFFER 1024

int main()
{
    int servidor_fd, cliente_fd;
    struct sockaddr_in endereco;
    socklen_t endereco_len = sizeof(endereco);

    char buffer[TAM_BUFFER];

    // Cria socket
    servidor_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (servidor_fd < 0)
    {
        perror("Erro ao criar socket");
        exit(EXIT_FAILURE);
    }

    endereco.sin_family = AF_INET;
    endereco.sin_addr.s_addr = INADDR_ANY;
    endereco.sin_port = htons(PORTA);

    // Associa socket à porta
    if (bind(servidor_fd, (struct sockaddr *)&endereco, sizeof(endereco)) < 0)
    {
        perror("Erro no bind");
        close(servidor_fd);
        exit(EXIT_FAILURE);
    }

    // Escuta conexões
    if (listen(servidor_fd, 1) < 0)
    {
        perror("Erro no listen");
        close(servidor_fd);
        exit(EXIT_FAILURE);
    }

    printf("Servidor aguardando conexao na porta %d...\n", PORTA);

    cliente_fd = accept(servidor_fd, (struct sockaddr *)&endereco, &endereco_len);
    if (cliente_fd < 0)
    {
        perror("Erro no accept");
        close(servidor_fd);
        exit(EXIT_FAILURE);
    }

    printf("Cliente conectado!\n");

    while (1)
    {
        memset(buffer, 0, TAM_BUFFER);

        // Recebe mensagem do cliente
        int bytes = recv(cliente_fd, buffer, TAM_BUFFER - 1, 0);

        if (bytes <= 0)
        {
            printf("Cliente desconectou.\n");
            break;
        }

        printf("\nCliente: %s\n", buffer);

        if (strcmp(buffer, "sair") == 0)
            break;

        // Envia resposta
        printf("Servidor: ");
        fgets(buffer, TAM_BUFFER, stdin);

        buffer[strcspn(buffer, "\n")] = '\0';

        send(cliente_fd, buffer, strlen(buffer) + 1, 0);

        if (strcmp(buffer, "sair") == 0)
            break;
    }

    close(cliente_fd);
    close(servidor_fd);

    return 0;
}