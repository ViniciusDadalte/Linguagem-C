#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
    int valor;
    struct no *proximo;
} No;

typedef struct 
{
    No *inicio;
    int tam;
} Lista;

void criaLista(Lista *l);
void inserirNoInicio(int num, Lista *l);
void inserirNoFinal(int num, Lista *l);
void inserirNoMeio(int num, Lista *l, int ant);
void inserirOrdenado(int num, Lista *l);
void imprimirLista(Lista l);

int main(void)
{
    system("cls");

    Lista lista;
    criaLista(&lista);

    int opcao, dado, ant;

    do
    {
        printf("\n0 - sair\n1 - InserirI\n2 - InserirF\n3 - InserirM\n4 - InserirO\n5 - imprimir\n");
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
            system("cls");
            imprimirLista(lista);
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

void criaLista(Lista *l)
{
    l->inicio = NULL;
    l->tam = 0;
}

void inserirNoInicio(int num, Lista *l)
{
    No *novo = malloc(sizeof(No));
    if (novo == NULL)
    {
        printf("erro ao alocar memoria\n");
        return;
    }

    novo->valor = num;
    novo->proximo = l->inicio;
    l->inicio = novo;
    l->tam++;
}

void inserirNoFinal(int num, Lista *l)
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
    if (l->inicio == NULL)
        l->inicio = novo;
    else
    {
        aux = l->inicio;
        while(aux->proximo)
            aux = aux->proximo;
        aux->proximo = novo;
    }
    l->tam++;
}

void inserirNoMeio(int num, Lista *l, int ant)
{
    No *aux, *novo = malloc(sizeof(No));
    if (novo == NULL)
    {
        printf("erro ao alocar memoria\n");
        return;
    }

    novo->valor = num;

    // é o primeiro?
    if (l->inicio == NULL)
    {
        novo->proximo = NULL;
        l->inicio = novo;
    }
    else
    {
        aux = l->inicio;
        while (aux->valor != ant && aux->proximo)
            aux = aux->proximo;
        novo->proximo = aux->proximo;
        aux->proximo = novo; 
    }
    l->tam++;
}

void inserirOrdenado(int num, Lista *l)
{
    No *aux, *novo = malloc(sizeof(No));
    if (novo == NULL)
    {
        printf("erro ao alocar memoria\n");
        return;
    }

    novo->valor = num;
    if (l->inicio == NULL)
    {
        novo->proximo = NULL;
        l->inicio = novo;
    }
    else if (novo->valor < l->inicio->valor)
    {
        novo->proximo = l->inicio;
        l->inicio = novo;
    }
    else
    {
        aux = l->inicio;
        while (aux->proximo && novo->valor > aux->proximo->valor)
            aux = aux->proximo;    
        novo->proximo = aux->proximo;
        aux->proximo = novo;
    }
}

void imprimirLista(Lista l)
{
    No *aux = l.inicio;

    printf("------------ LISTA / TAM: %i ------------\n\n", l.tam);
    while (aux)
    {
        printf("%d ", aux->valor);
        aux = aux->proximo;
    }
    printf("\n\n------------ FIM LISTA ------------\n");
}