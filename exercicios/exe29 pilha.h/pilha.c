#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

No* push(No *pilha, int num)
{
    No *novo = malloc(sizeof(No));
    if (novo == NULL)
    {
        printf("Erro ao alocar memoria\n");
        return NULL;
    }

    novo->valor = num;
    novo->proximo = pilha;
    return novo;
}

No* pop(No **pilha)
{
    No *remover = NULL;
    
    if (*pilha )
    {    
        remover = *pilha;
        *pilha = remover->proximo;
    }
    else
        printf("Pilha vazia!\n");
    return remover;
}

void imprimir(No *pilha)
{
    printf("\n\tPILHA\n");

    while (pilha)
    {
        printf("\t%i\n", pilha->valor);
        pilha = pilha->proximo;
    }
    
    printf("\n\tPILHA\n");
}
