#include "partida.h"

int main()
{
    struct Partida jogo;

    configuraJogadores(&jogo);

    inicia(&jogo);

    return 0;
}