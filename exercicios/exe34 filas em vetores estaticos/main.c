#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define n 3

typedef struct fila
{
    int dados[n];
    int fim;
} Fila;

void iniciaFila(Fila *f);
void enfilera(int dado, Fila *f);
int desenfileira(Fila *f);
void imprimeFila(Fila *f);

int main(void)
{
    system("cls");

    Fila *f1;
    iniciaFila(f1);

    int opcao, dado;
    do
    {
        printf("0 - sair\n1 - enfileirar\n2 - desenfileirar\n3 - imprimir\n");
        scanf("%i", &opcao);

        switch (opcao)
        {
        case 1:
            if (f1->fim == n)
            {
                system("cls");
                printf("A fila esta cheia\n");
                break;
            }

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
    int i;
    for (int i = 0; i < n; i++)
    {
        f->dados[i] = 0;
    }
    f->fim = 0;
}

void enfilera(int dado, Fila *f)
{
    if (f->fim == n)
    {
        printf("A fila esta cheia\n");
        return;
    }

    f->dados[f->fim] = dado;
    f->fim++;
}

int desenfileira(Fila *f)
{
    int dado;

    if (f->fim == 0)
    {
        printf("A fila esta vazia\n");
        return 1;
    }

    dado = f->dados[0];
    for (int i = 0; i < f->fim; i++)
    {
        f->dados[i] = f->dados[i + 1];
    }
    f->fim--;

    return dado;
}

void imprimeFila(Fila *f)
{
    if (f->fim == 0)
    {
        printf("A fila esta vazia\n");
        return;
    }

    printf("Imprimindo a fila\n\nINICIO");
    for (int i = 0; i < f->fim; i++)
    {
        printf("\n%i", f->dados[i]);
    }
    printf("\nFIM\n\n");
}