#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
    int valor;
    struct no *proximo;
} No;

typedef struct fila
{
    No *inicio;
    No *fim;
    int tam;
} Fila;

void iniciaFila(Fila *f);
void enfileirar(int num, Fila *fila);
No* desinfilerar(Fila *fila);
void imprimir(Fila *fila);

int main(void)
{
    system("cls");

    No *r;
    Fila fila;
    int opcao, dado;

    iniciaFila(&fila);

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
            enfileirar(dado, &fila);
            break;
        case 2:
            system("cls");
            r = desinfilerar(&fila);
            if (r)
            {
                printf("Removido: %i\n", r->valor);
                free(r);
            }
            break;
        case 3:
            system("cls");
            imprimir(&fila);
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
    f->tam = 0;
}

void enfileirar(int num, Fila *fila)
{
    No *aux, *novo = malloc(sizeof(No));
    if (novo == NULL)
    {
        printf("erro ao alocar memoria\n");
        return;
    }

    novo->valor = num;
    novo->proximo = NULL;
    if (fila->inicio == NULL)
    {
        fila->inicio= novo;
        fila->fim= novo;
    }
    else
    {
        fila->fim->proximo = novo;
        fila->fim = novo;
        novo->valor = num;
    }
    fila->tam++;
}

No* desinfilerar(Fila *fila)
{
    No *remover = NULL;

    if (fila->inicio)
    {
        remover = fila->inicio;
        fila->inicio = remover->proximo;
        fila->tam--;
    }
    else
        printf("Fila vazia\n");
    return remover;
}

void imprimir(Fila *fila)
{
    No *aux = fila->inicio;
    printf("------------ FILA / TAMANHO: %i ------------\n", fila->tam);
    
    while (aux)
    {
        printf("%i ", aux->valor);
        aux = aux->proximo;
    }

    printf("\n---------------- FIM FILA -----------------\n");
}