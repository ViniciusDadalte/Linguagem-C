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
int quantidadeDeNos(NoArv *raiz);
int quantidadeDeFolhas(NoArv *raiz);
void imprimirArvore(NoArv *raiz);
void imprimirArvoreOrdenado(NoArv *raiz);

int main(void)
{
    system("cls");

    NoArv *buscado, *raiz = NULL;
    int opcao, dado;

    do
    {
        printf("\n0 - sair\n1 - inserir\n2 - imprimirN\n3 - imprimirO\n4 - buscar\n5 - altura\n6 - tamanho\n7 - folhas\n");
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
        case 6:
            system("cls");
            printf("Tamanho: %i", quantidadeDeNos(raiz));
            break;
        case 7:
            system("cls");
            printf("Folhas: %i", quantidadeDeFolhas(raiz));
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

int quantidadeDeNos(NoArv *raiz)
{
    if (raiz == NULL)
        return 0;
    else
        return 1 + quantidadeDeNos(raiz->esquerda) + quantidadeDeNos(raiz->direita);
}

int quantidadeDeFolhas(NoArv *raiz)
{
    if (raiz == NULL)
        return 0;
    else if (raiz->esquerda == NULL && raiz->direita == NULL)
        return 1;
    else
        return quantidadeDeFolhas(raiz->esquerda) + quantidadeDeFolhas(raiz->direita);
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

