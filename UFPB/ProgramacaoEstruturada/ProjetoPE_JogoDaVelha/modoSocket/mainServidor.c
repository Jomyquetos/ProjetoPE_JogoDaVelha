#include "partida.h"
#include "jogadorRemoto.h"

int main()
{
    Partida jogo;

    aceitaConexao(8080);
    
    configuraJogadores(&jogo, 4, 1);
    
    inicia(&jogo, 0); 

    return 0;
}