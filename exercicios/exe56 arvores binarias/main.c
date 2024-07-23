#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
    int valor;
    struct no *esquerda, *direita;
} NoArv;

NoArv* inserir(int num, NoArv *raiz);
void imprimirArvore(NoArv *raiz);
void imprimirArvoreOrdenado(NoArv *raiz);

int main(void)
{
    system("cls");

    NoArv *raiz = NULL;
    int opcao, dado;

    do
    {
        printf("\n0 - sair\n1 - inserir\n2 - imprimirN\n3 - imprimirO\n");
        scanf("%i", &opcao);

        switch (opcao)
        {
        case 1:
            printf("digite o dado: ");
            scanf("%i", &dado);
            raiz = inserir(dado, raiz);
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

NoArv* inserir(int num, NoArv *raiz)
{
    if (raiz == NULL)
    {
        NoArv *aux = malloc(sizeof(NoArv));
        if (aux == NULL)
        {
            printf("Erro ao alocar memoria\n");
            return NULL;
        }

        aux->valor = num;
        aux->esquerda = NULL;
        aux->direita = NULL;
        return aux;
    }
    else
    {
        if (num < raiz->valor)
            raiz->esquerda = inserir(num, raiz->esquerda);
        else
            raiz->direita = inserir(num, raiz->direita);
        return raiz;
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
