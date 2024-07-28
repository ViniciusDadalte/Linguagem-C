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
No* rotacaoEsquerda(No *r);
No* rotacaoDireita(No *r);
No* rotacaoDireitaEsquerda(No *r);
No* rotacaoEsquerdaDireita(No *r);

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

No* rotacaoEsquerda(No *r)
{
    No *y, *f;
    y = r->direito;
    f = y->esquerdo;

    y->esquerdo = r;
    r->direito = f;

    r->altura = maior(alturaDoNo(r->esquerdo), alturaDoNo(r->direito)) + 1;
    y->altura = maior(alturaDoNo(y->esquerdo), alturaDoNo(y->direito)) + 1;

    return y;
}

No* rotacaoDireita(No *r)
{
    No *y, *f;
    y = r->esquerdo;
    f = y->direito;

    y->direito = r;
    r->esquerdo = f;

    r->altura = maior(alturaDoNo(r->esquerdo), alturaDoNo(r->direito)) + 1;
    y->altura = maior(alturaDoNo(y->esquerdo), alturaDoNo(y->direito)) + 1;

    return y;
}

No* rotacaoDireitaEsquerda(No *r)
{
    r->direito = rotacaoDireita(r->direito);
    return rotacaoEsquerda(r);
}

No* rotacaoEsquerdaDireita(No *r)
{
    r->esquerdo = rotacaoEsquerda(r->esquerdo);
    return rotacaoDireita(r);
}

