#include "partida.h"
#include "jogadorRemoto.h"

int main()
{
    Partida jogo;

    aceitaConexao(8080);

    configuraJogadores(&jogo);

    inicia(&jogo);

    return 0;
}