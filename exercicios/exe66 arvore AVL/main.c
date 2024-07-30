#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct 
{
    char nome[25];
    int idade;
    int cpf;
} Pessoa;

typedef struct no
{
    Pessoa *p;
    struct no *esquerdo, *direito;
    short altura;
} No;

No* novoNo(Pessoa *x);
short maior(short a, short b);
short alturaDoNo(No *n);
short fatorDeBalanceamento(No *n);
No* rotacaoEsquerda(No *r);
No* rotacaoDireita(No *r);
No* rotacaoDireitaEsquerda(No *r);
No* rotacaoEsquerdaDireita(No *r);
No* balancear(No *raiz);
No* inserir(Pessoa *x, No *raiz);
No* remover(int cpf, No *raiz);
void imprimirPessoa(Pessoa *pes);
void imprimirArvore(No *raiz, int nivel);

int main(void)
{
    system("cls");

    int opcao, dado;
    No *raiz = NULL;
    Pessoa *p;

    do
    {
        printf("\n0 - sair\n1 - inserir\n2 - remover\n3 - imprimir\n\n");
        scanf("%i", &opcao);

        switch (opcao)
        {
        case 0:
            system("cls");
            printf("Saindo!!!\n\n");
            break;
        case 1:
            p = malloc(sizeof(Pessoa));
            printf("Digite o nome: ");
            scanf("%s", p->nome);
            printf("Digite o cpf e a idade: ");
            scanf("%i%i", &p->cpf, &p->idade);
            raiz = inserir(p, raiz);
            system("cls");
            break;
        case 2:
            printf("Digite o CPF a ser removido: ");
            scanf("%i", &dado);
            system("cls");
            raiz = remover(dado, raiz);
            break;
        case 3:
            system("cls");
            imprimirArvore(raiz, 1);
            break;        
        default:
            system("cls");
            printf("Opcao invalida!!\n");
            break;
        }
    } while (opcao != 0);
    
    return 0;
}

No* novoNo(Pessoa *x)
{
    No *novo = malloc(sizeof(No));
    if (novo)
    {
        novo->p = x;
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

No* inserir(Pessoa *x, No *raiz)
{
    if (raiz == NULL)
        return novoNo(x);
    else
    {
        if (x->cpf < raiz->p->cpf)
            raiz->esquerdo = inserir(x, raiz->esquerdo);
        else if (x->cpf > raiz->p->cpf)
            raiz->direito = inserir(x, raiz->direito);
        else
            printf("\nInsericao nao realizada\nO elemento %i ja existe!\n", x->cpf);
    }

    raiz->altura = maior(alturaDoNo(raiz->esquerdo), alturaDoNo(raiz->direito)) + 1;
    raiz = balancear(raiz);
    return raiz;
}

No* remover(int cpf, No *raiz)
{
    if (raiz == NULL)
    {
        printf("valor nao encontrado\n");
        return NULL;
    }
    else
    {
        if (raiz->p->cpf == cpf)
        {
            if (raiz->esquerdo == NULL && raiz->direito == NULL)
            {
                free(raiz);
                printf("Elemento folha removido: %i", cpf);
                return NULL;
            }
            else
            {
                if (raiz->esquerdo != NULL && raiz->direito != NULL)
                {
                    No *aux = raiz->esquerdo;
                    while (aux->direito)
                        aux = aux->direito;
                    
                    Pessoa *pessoaAux;
                    pessoaAux = raiz->p;

                    raiz->p = aux->p;
                    aux->p = pessoaAux;
                    
                    printf("elemento trocado: %i\n", cpf);
                    raiz->esquerdo = remover(cpf, raiz->esquerdo);
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
                    printf("elemento com 1 filho removido: %i\n", cpf);
                    return aux;
                }
            }
        }
        else
        {
            if (cpf < raiz->p->cpf)
                raiz->esquerdo = remover(cpf, raiz->esquerdo);
            else
                raiz->direito = remover(cpf, raiz->direito);
        }

        raiz->altura = maior(alturaDoNo(raiz->esquerdo), alturaDoNo(raiz->direito)) + 1;
        raiz = balancear(raiz);
        return raiz;
    }
}

void imprimirPessoa(Pessoa *pes)
{
    printf("Nome: %s ", pes->nome);
    printf("CPF: %i ", pes->cpf);
    printf("Idade: %i\n", pes->idade);
}

void imprimirArvore(No *raiz, int nivel)
{
    if (raiz)
    {
        imprimirArvore(raiz->direito, nivel + 1);
        printf("\n\n");

        for (int i = 0; i < nivel; i++)
            printf("\t");

        imprimirPessoa(raiz->p);
        imprimirArvore(raiz->esquerdo, nivel + 1);
    }
}

