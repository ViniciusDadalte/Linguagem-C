#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
    int valor;
    struct no *proximo;
} No;

No* push(No *pilha, int num);
No* pop(No **pilha);
void imprimir(No *pilha);
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