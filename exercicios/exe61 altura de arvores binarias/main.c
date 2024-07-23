#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
    int valor;
    struct no *esquerda, *direita;
} NoArv;

void inserir(int num, NoArv **raiz);
NoArv* buscar(int num, NoArv *raiz);
int alutra(NoArv *raiz);
void imprimirArvore(NoArv *raiz);
void imprimirArvoreOrdenado(NoArv *raiz);

int main(void)
{
    system("cls");

    NoArv *buscado, *raiz = NULL;
    int opcao, dado;

    do
    {
        printf("\n0 - sair\n1 - inserir\n2 - imprimirN\n3 - imprimirO\n4 - buscar\n5 - altura\n");
        scanf("%i", &opcao);

        switch (opcao)
        {
        case 1:
            printf("digite o dado: ");
            scanf("%i", &dado);
            inserir(dado, &raiz);
            system("cls");
            break;
        case 2:
            system("cls");
            imprimirArvore(raiz);
            break;
        case 3:
            system("cls");
            imprimirArvoreOrdenado(raiz);
            break;
        case 4:
            printf("digite o dado a ser buscado: ");
            scanf("%i", &dado);
            system("cls");
            buscado = buscar(dado, raiz);
            if (buscado)
                printf("valor encontrado: %i\n", buscado->valor);
            else
                printf("valor nao encontrado!\n");
            break;
        case 5:
            system("cls");
            printf("Altura da arvore: %i\n", alutra(raiz));
            break;
        default:
            if (opcao != 0)
            {
                system("cls");
                printf("opcao invalido!\n");
            }
            break;
        }
    } while (opcao != 0);  

    return 0;
}

void inserir(int num, NoArv **raiz)
{
    NoArv *aux = *raiz;
    while (aux)
    {
        if (num < aux->valor)
            raiz = &aux->esquerda;
        else
            raiz = &aux->direita;
        aux = *raiz;
    }
    
    aux = malloc(sizeof(NoArv));
    if (aux == NULL)
    {
        printf("Erro ao alocar memoria\n");
        return;
    }
    aux->valor = num;
    aux->esquerda = NULL;
    aux->direita = NULL;
    *raiz = aux;
}

NoArv* buscar(int num, NoArv *raiz)
{
    while (raiz)
    {
        if (num < raiz->valor)
            raiz = raiz->esquerda;
        else if (num > raiz->valor)
            raiz = raiz->direita;
        else
            return raiz;
    }
    return NULL;
}

int alutra(NoArv *raiz)
{
    if (raiz == NULL)
    {
        return -1;
    }
    else
    {
        int esq = alutra(raiz->esquerda);
        int dir = alutra(raiz->direita);

        if (esq > dir)
            return esq + 1;
        else
            return dir + 1;
    }
}

void imprimirArvore(NoArv *raiz)
{
    if (raiz)
    {
        printf("%i ", raiz->valor);
        imprimirArvore(raiz->esquerda);
        imprimirArvore(raiz->direita);
    }
}

void imprimirArvoreOrdenado(NoArv *raiz)
{
    if (raiz)
    {
        imprimirArvoreOrdenado(raiz->esquerda);
        printf("%i ", raiz->valor);
        imprimirArvoreOrdenado(raiz->direita);
    }
}

