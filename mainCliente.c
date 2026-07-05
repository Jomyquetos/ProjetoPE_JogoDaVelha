#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORTA 8080
#define TAM_BUFFER 1024

int main() {
    int sock;
    struct sockaddr_in servidor;
    char buffer[TAM_BUFFER];

    sock = socket(AF_INET, SOCK_STREAM, 0);

    if (sock < 0) {
        perror("Erro ao criar socket");
        exit(EXIT_FAILURE);
    }

    servidor.sin_family = AF_INET;
    servidor.sin_port = htons(PORTA);

    if (inet_pton(AF_INET, "127.0.0.1", &servidor.sin_addr) <= 0) {
        perror("Endereco invalido");
        close(sock);
        exit(EXIT_FAILURE);
    }

    if (connect(sock, (struct sockaddr *)&servidor, sizeof(servidor)) < 0) {
        perror("Erro ao conectar");
        close(sock);
        exit(EXIT_FAILURE);
    }

    printf("Conectado ao servidor!\n");

    while (1) {
        // Envia mensagem
        printf("Cliente: ");
        fgets(buffer, TAM_BUFFER, stdin);

        buffer[strcspn(buffer, "\n")] = '\0';

        send(sock, buffer, strlen(buffer) + 1, 0);

        if (strcmp(buffer, "sair") == 0)
            break;

        // Recebe resposta
        memset(buffer, 0, TAM_BUFFER);

        int bytes = recv(sock, buffer, TAM_BUFFER - 1, 0);

        if (bytes <= 0) {
            printf("Servidor desconectou.\n");
            break;
        }

        printf("Servidor: %s\n", buffer);

        if (strcmp(buffer, "sair") == 0)
            break;
    }

    close(sock);

    return 0;
}