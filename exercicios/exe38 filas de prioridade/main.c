#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
    int valor;
    struct no *proximo;
} No;

void enfileirar(int num ,No **fila);
void enfileirarComPrioridade(int num ,No **fila);
No* desinfilerar(No **fila);
void imprimir(No *fila);

int main(void)
{
    system("cls");

    No *r, *fila = NULL;
    int opcao, dado;

    do
    {
        printf("0 - sair\n1 - enfileirar\n2 - desenfileirar\n3 - imprimir\n4 - enfileirar com prioridade\n");
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
            imprimir(fila);
            break;
        case 4:
            printf("Digite o dado: ");
            scanf("%i", &dado);
            system("cls");
            enfileirarComPrioridade(dado, &fila);
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

void enfileirar(int num ,No **fila)
{
    No *aux, *novo = malloc(sizeof(No));
    if (novo == NULL)
    {
        printf("erro ao alocar memoria\n");
        return;
    }

    novo->valor = num;
    novo->proximo = NULL;
    if (*fila == NULL)
        *fila = novo;
    else
    {
        aux = *fila;
        while (aux->proximo)
            aux = aux->proximo;
        aux->proximo = novo;
    }
}

void enfileirarComPrioridade(int num ,No **fila)
{
    No *aux, *novo = malloc(sizeof(No));
    if (novo == NULL)
    {
        printf("erro ao alocar memoria\n");
        return;
    }

    novo->valor = num;
    novo->proximo = NULL;
    if (*fila == NULL)
        *fila = novo;
    else
    {
        // é prioridade?
        if (num >= 60)
        {
            // é a primeira prioridade?
            if ((*fila)->valor < 60)
            {
                novo->proximo = *fila;
                *fila = novo;
            }
            else
            {
                aux = *fila;
                while (aux->proximo && aux->proximo->valor >= 60)
                    aux = aux->proximo;
                novo->proximo = aux->proximo;
                aux->proximo = novo;
            }
        }
        else 
        {
            aux = *fila;
            while (aux->proximo)
                aux = aux->proximo;
            aux->proximo = novo;
        }
    }
}

No* desinfilerar(No **fila)
{
    No *remover = NULL;

    if (*fila)
    {
        remover = *fila;
        *fila = remover->proximo;
    }
    else
        printf("Fila vazia\n");
    return remover;
}

void imprimir(No *fila)
{
    printf("------------ FILA ------------\n");
    
    while (fila)
    {
        printf("%i ", fila->valor);
        fila = fila->proximo;
    }

    printf("\n------------ FIM FILA ------------\n");
}