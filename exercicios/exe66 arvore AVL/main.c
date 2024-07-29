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
No* balancear(No *raiz);
No* inserir(int x, No *raiz);

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

No* balancear(No *raiz)
{
    short fb = fatorDeBalanceamento(raiz);

    if (fb < -1 && fatorDeBalanceamento(raiz->direito) <= 0)
        raiz = rotacaoEsquerda(raiz);
    else if (fb > 1 && fatorDeBalanceamento(raiz->esquerdo) >= 0)
        raiz = rotacaoDireita(raiz);
    else if (fb > 1 && fatorDeBalanceamento(raiz->esquerdo) < 0)
        raiz = rotacaoEsquerdaDireita(raiz);
    else if (fb < -1 && fatorDeBalanceamento(raiz->direito) > 0)
        raiz = rotacaoDireitaEsquerda(raiz);

    return raiz;
}

No* inserir(int x, No *raiz)
{
    if (raiz == NULL)
        return novoNo(x);
    else
    {
        if (x < raiz->valor)
            raiz->esquerdo = inserir(x, raiz->esquerdo);
        else if (x > raiz->valor)
            raiz->direito = inserir(x, raiz->direito);
        else
            printf("\nInsericao nao realizada\nO elemento %i ja existe!\n", x);
    }

    raiz->altura = maior(alturaDoNo(raiz->esquerdo), alturaDoNo(raiz->direito)) + 1;
    raiz = balancear(raiz);
    return raiz;
}

No* remover(int num, No *raiz)
{
    if (raiz == NULL)
    {
        printf("valor nao encontrado\n");
        return NULL;
    }
    else
    {
        if (raiz->valor == num)
        {
            if (raiz->esquerdo == NULL && raiz->direito == NULL)
            {
                free(raiz);
                printf("Elemento folha removido: %i", num);
                return NULL;
            }
            else
            {
                if (raiz->esquerdo != NULL && raiz->direito != NULL)
                {
                    No *aux = raiz->esquerdo;
                    while (aux->direito)
                        aux = aux->direito;
                    raiz->valor = aux->valor;
                    aux->valor = num;
                    printf("elemento trocado: %i\n", num);
                    raiz->esquerdo = remover(num, raiz->esquerdo);
                    return raiz;
                }
                else
                {
                    No *aux;
                    if (raiz->esquerdo != NULL)
                        aux = raiz->esquerdo;
                    else
                        aux = raiz->direito;
                    free(raiz);
                    printf("elemento com 1 filho removido: %i\n", num);
                    return aux;
                }
            }
        }
        else
        {
            if (num < raiz->valor)
                raiz->esquerdo = remover(num, raiz->esquerdo);
            else
                raiz->direito = remover(num, raiz->direito);
        }

        raiz->altura = maior(alturaDoNo(raiz->esquerdo), alturaDoNo(raiz->direito)) + 1;
        raiz = balancear(raiz);
        return raiz;
    }
}
