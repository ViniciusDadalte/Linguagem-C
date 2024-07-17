#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

int fatorial(int num);

int main(void)
{
    system("cls");

    int valor;

    printf("Digite um numero maior que zero para o fatorial: ");
    scanf("%i", &valor);
    printf("\tFatorial de %i: %i\n", valor, fatorial(valor));

    return 0;
}

int fatorial(int num)
{
    No *remover, *pilha = NULL;

    while (num > 1)
    {
        pilha = push(pilha, num);
        num--;
    }
    
    imprimir(pilha);

    while (pilha)
    {
        remover = pop(&pilha);
        num = num * remover->valor;
        free(remover);
    }
    
    return num;
}