#include <stdio.h>
#include <string.h>

struct Jogadores
{
    char nome[12];
    int pontuacao;
};


int main (void)
{

    struct Jogadores jogador1;
    struct Jogadores jogador2;

    strcpy(jogador1.nome, "Carlos");
    jogador1.pontuacao = 4;

    strcpy(jogador2.nome, "Joao");
    jogador2.pontuacao = 5;

    printf("\nSalve mano %s\n", jogador1.nome);
    printf("Sua pontuacao e: %i\n\n", jogador1.pontuacao);
    
    printf("Salve mano %s\n", jogador2.nome);
    printf("Sua pontuacao e: %i\n\n", jogador2.pontuacao);
    
    return 0;
}