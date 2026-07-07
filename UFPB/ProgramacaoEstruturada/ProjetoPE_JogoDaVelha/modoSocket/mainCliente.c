#include "partida.h"
#include "jogadorRemoto.h"

int main()
{
    Partida jogo;

    conecta("127.0.0.1", 8080);
    
    configuraJogadores(&jogo, 1, 4);
    
    inicia(&jogo, 1); 

    return 0;
}