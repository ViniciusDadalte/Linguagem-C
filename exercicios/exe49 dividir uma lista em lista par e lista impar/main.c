#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
    int valor;
    struct no *proximo;
} No;

void inserirNoInicio(int num, No **lista);
void inserirNoFinal(int num, No **lista);
void inserirNoMeio(int num, No **lista, int ant);
void inserirOrdenado(int num, No **lista);
No* remover(int num, No **lista);
No* buscar(int num, No **lista);
void dividir(No **l, No **p, No **i);
void imprimirLista(No *lista);

int main(void)
{
    system("cls");

    No *buscado, *removido;
    No *lista = NULL, *par = NULL, *impar = NULL;
    int opcao, dado, ant;

    do
    {
        printf("\n0 - sair\n1 - InserirI\n2 - InserirF\n3 - InserirM\n4 - InserirO\n5 - Remover\n6 - Buscar\n7 - imprimir\n8 - Dividir\n");
        scanf("%i", &opcao);

        switch (opcao)
        {
        case 1:
            printf("digite o dado: ");
            scanf("%i", &dado);
            system("cls");
            inserirNoInicio(dado, &lista);
            break;
        case 2:
            printf("digite o dado: ");
            scanf("%i", &dado);
            system("cls");
            inserirNoFinal(dado, &lista);
            break;
        case 3:
            printf("digite o anterior: ");
            scanf("%i", &ant);
            printf("digite o dado: ");
            scanf("%i", &dado);
            system("cls");
            inserirNoMeio(dado, &lista, ant);
            break;
        case 4:
            printf("digite o dado: ");
            scanf("%i", &dado);
            system("cls");
            inserirOrdenado(dado, &lista);
            break;
        case 5:
            printf("digite o dado para remover: ");
            scanf("%i", &dado);
            system("cls");
            removido = remover(dado, &lista);
            if (removido)
            {
                printf("elemento a ser remvido: %i\n", removido->valor);
                free(removido);
            }
            else
                printf("elemento nao existe\n");
            break;
        case 6:
            printf("digite o dado para buscar: ");
            scanf("%i", &dado);
            system("cls");
            buscado = buscar(dado, &lista);
            if (buscado)
                printf("elemento encontrado: %i", buscado->valor);
            else
                printf("elemento nao encontrado\n");
            break;
        case 7:
            system("cls");
            printf("\nLista L:\n");
            imprimirLista(lista);
            printf("Lista Par:\n");
            imprimirLista(par);
            printf("Lista Impar:\n");
            imprimirLista(impar);
            break;
        case 8:
            system("cls");
            dividir(&lista, &par, &impar);
            printf("Divisao realizada com sucesso!\n");
            break;
        default:
            if (opcao != 0)
            {
                system("cls");
                printf("opcao invalida!\n");
            }
            break;
        }
    } while (opcao != 0);
    

    return 0;
}

void inserirNoInicio(int num, No **lista)
{
    No *novo = malloc(sizeof(No));
    if (novo == NULL)
    {
        printf("erro ao alocar memoria\n");
        return;
    }

    novo->valor = num;
    novo->proximo = *lista;
    *lista = novo;
}

void inserirNoFinal(int num, No **lista)
{
    No *aux, *novo = malloc(sizeof(No));
    if (novo == NULL)
    {
        printf("erro ao alocar memoria\n");
        return;
    }

    novo->valor = num;
    novo->proximo = NULL;

    // é o primeiro?
    if (*lista == NULL)
        *lista = novo;
    else
    {
        aux = *lista;
        while(aux->proximo)
            aux = aux->proximo;
        aux->proximo = novo;
    }
}

void inserirNoMeio(int num, No **lista, int ant)
{
    No *aux, *novo = malloc(sizeof(No));
    if (novo == NULL)
    {
        printf("erro ao alocar memoria\n");
        return;
    }

    novo->valor = num;

    // é o primeiro?
    if (*lista == NULL)
    {
        novo->proximo = NULL;
        *lista = novo;
    }
    else
    {
        aux = *lista;
        while (aux->valor != ant && aux->proximo)
            aux = aux->proximo;
        novo->proximo = aux->proximo;
        aux->proximo = novo; 
    }
}

void inserirOrdenado(int num, No **lista)
{
    No *aux, *novo = malloc(sizeof(No));
    if (novo == NULL)
    {
        printf("erro ao alocar memoria\n");
        return;
    }

    novo->valor = num;
    if (*lista == NULL)
    {
        novo->proximo = NULL;
        *lista = novo;
    }
    else if (novo->valor < (*lista)->valor)
    {
        novo->proximo = *lista;
        *lista = novo;
    }
    else
    {
        aux = *lista;
        while (aux->proximo && novo->valor > aux->proximo->valor)
            aux = aux->proximo;    
        novo->proximo = aux->proximo;
        aux->proximo = novo;
    }
}

No* remover(int num, No **lista)
{
    No *aux, *remover = NULL;

    if (*lista)
    {
        if ((*lista)->valor == num)
        {
            remover = *lista;
            *lista = remover->proximo;
        }
        else 
        {
            aux = *lista;
            while (aux->proximo && aux->proximo->valor != num)
                aux = aux->proximo;
            if (aux->proximo)
            {
                remover = aux->proximo;
                aux->proximo = remover->proximo;
            }
        }
    }
    else
        printf("lista vazia\n");

    return remover;
}

No* buscar(int num, No **lista)
{
    No *aux, *no = NULL;

    aux = *lista;
    while (aux && aux->valor != num)
        aux = aux->proximo;
    if (aux)
        no = aux;
    return no;
}

void dividir(No **l, No **p, No **i)
{
    No *aux = *l;
    while (aux)
    {
        if (aux->valor > 0)
        {
            if (aux->valor % 2 == 0)
                inserirNoInicio(aux->valor, p);
            else
                inserirNoInicio(aux->valor, i); 
        }
        aux = aux->proximo;
    }
}

void imprimirLista(No *lista)
{
    printf("------------ LISTA ------------\n\n");

    while (lista)
    {
        printf("%d ", lista->valor);
        lista = lista->proximo;
    }

    printf("\n\n------------ FIM LISTA ------------\n");
}
