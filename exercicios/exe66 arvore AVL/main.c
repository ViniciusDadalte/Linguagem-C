#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
    int valor;
    struct no *esquerdo, *direito;
    short altura;
} No;

No* novoNo(int x);
short maior(short a, short b);
short alturaDoNo(No *n);
short fatorDeBalanceamento(No *n);

int main(void)
{
    system("cls");



    return 0;
}

No* novoNo(int x)
{
    No *novo = malloc(sizeof(No));
    if (novo)
    {
        novo->valor = x;
        novo->esquerdo = NULL;
        novo->direito = NULL;
        novo->altura = 0;
    }
    else
        printf("Erro ao alocar memoria\n");
    return novo;
}

short maior(short a, short b)
{
    return (a > b)? a: b;
}

short alturaDoNo(No *n)
{
    if (n == NULL)
        return -1;
    else
        return n->altura;
}

short fatorDeBalanceamento(No *n)
{
    if (n)
        return (alturaDoNo(n->esquerdo) - alturaDoNo(n->direito));
    else
        return 0;
}

