#include <stdio.h>
#include <string.h>

int main ()
{
    char nome[25];
    int idade;

    printf("Digite seu nome: ");
    fgets(nome, 25, stdin );
    nome[strlen(nome) - 1 ] = '\0';

    printf("\nDigite sua idade: ");
    scanf("%i", &idade);

    printf("\nOLa %s voce tem %i anos certo? \n", nome, idade);

    return 0;
}
