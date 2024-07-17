#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
    int dado;
    struct no *prox;
} No;

typedef struct fila
{
    No *inicio;
    No *fim;
} Fila;

void iniciaFila(Fila *f);
void enfilera(int dado, Fila *f);
int desenfileira(Fila *f);
void imprimeFila(Fila *f);

int main(void)
{
    system("cls");

    Fila *f1 = malloc(sizeof(Fila));
    if (f1 == NULL)
    {
        printf("Erro de alocacao de memoria");
        return 1;
    }

    iniciaFila(f1);

    int opcao, dado;
    do
    {
        printf("0 - sair\n1 - enfileirar\n2 - desenfileirar\n3 - imprimir\n");
        scanf("%i", &opcao);

        switch (opcao)
        {
        case 1:
            printf("Digite o dado: ");
            scanf("%i", &dado);
            system("cls");
            enfilera(dado, f1);
            break;
        case 2:
            system("cls");
            desenfileira(f1);
            break;
        case 3:
            system("cls");
            imprimeFila(f1);
            break;
        default:
            system("cls");
            if (opcao != 0)
                printf("Opcao invalida\n");
            break;
        }
    } while (opcao != 0);

    return 0;
}

void iniciaFila(Fila *f)
{
    f->inicio = NULL;
    f->fim = NULL;
}

void enfilera(int dado, Fila *f)
{
    No *ptr = malloc(sizeof(No));
    if (ptr == NULL)
    {
        printf("erro ao alocar memoria\n");
        return;
    }

    ptr->dado = dado;
    ptr->prox = NULL;

    if (f->inicio == NULL)
        f->inicio = ptr;
    else
        f->fim->prox = ptr;

    f->fim = ptr;
}

int desenfileira(Fila *f)
{
    No *ptr = f->inicio;
    int dado;
    
    if (ptr == NULL)
    {
        printf("fila vazia\n");
        return 1;
    }

    f->inicio = ptr->prox;
    ptr->prox == NULL;
    dado = ptr->dado;
    free(ptr);

    if (f->inicio == NULL)
    {
        f->fim = NULL;
    }

    printf("removendo: %i\n", dado);
    return dado;
}

void imprimeFila(Fila *f)
{
    No *ptr = f->inicio;
    if (ptr == NULL)
    {
        printf("fila vazia\n");
        return;
    }

    printf("--------- PILHA ---------\n");
    while (ptr)
    {
        printf("%i ", ptr->dado);
        ptr = ptr->prox;
    }
    printf("\n--------- FIM PILHA ---------\n\n");
}
