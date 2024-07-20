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
    No *fim;
    int tam;
} Lista;

void criaLista(Lista *l);
void inserirNoInicio(int num, Lista *l);
void inserirNoFinal(int num, Lista *l);
void inserirOrdenado(int num, Lista *l);
No* remover(int num, Lista *l);
No* buscar(int num, Lista *l);
void imprimirLista(Lista l);

int main(void)
{
    system("cls");

    Lista lista;
    criaLista(&lista);
    No *buscado, *removido;
    int opcao, dado, ant;

    do
    {
        printf("\n0 - sair\n1 - InserirI\n2 - InserirF\n3 - InserirO\n4 - Remover\n5 - Buscar\n6 - imprimir\n");
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
            printf("digite o dado: ");
            scanf("%i", &dado);
            system("cls");
            inserirOrdenado(dado, &lista);
            break;
        case 4:
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
        case 5:
            printf("digite o dado para buscar: ");
            scanf("%i", &dado);
            system("cls");
            buscado = buscar(dado, &lista);
            if (buscado)
                printf("elemento encontrado: %i", buscado->valor);
            else
                printf("elemento nao encontrado\n");
            break;
        case 6:
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
    l->fim = NULL;
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
    if (l->fim == NULL)
        l->fim = novo;
    l->fim->proximo = l->inicio;
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

    // é o primeiro?
    if (l->inicio == NULL)
    {
        l->inicio = novo;
        l->fim = novo;
        l->fim->proximo = l->inicio;
    }
    else
    {
        l->fim->proximo = novo;
        l->fim = novo;
        l->fim->proximo = l->inicio;
        // novo->proximo = l->inicio;
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
        inserirNoInicio(num, l);
    }
    else if (novo->valor < l->inicio->valor)
    {
        inserirNoInicio(num, l);
    }
    else
    {
        aux = l->inicio;
        while (aux->proximo != l->inicio && novo->valor > aux->proximo->valor)
            aux = aux->proximo;    
        if (aux->proximo == l->inicio)
            inserirNoFinal(num, l);
        else
        {
            novo->proximo = aux->proximo;
            aux->proximo = novo;
            l->tam++;
        }
    }
}

No* remover(int num, Lista *l)
{
    No *aux, *remover = NULL;

    if (l->inicio)
    {
        if (l->inicio == l->fim && l->inicio->valor == num)
        {
            remover = l->inicio;
            l->inicio = NULL;
            l->fim = NULL;
            l->tam--;
        }
        else if (l->inicio->valor == num)
        {
            remover = l->inicio;
            l->inicio = remover->proximo;
            l->fim->proximo = l->inicio; 
            l->tam--;
        }
        else 
        {
            aux = l->inicio;
            while (aux->proximo != l->inicio && aux->proximo->valor != num)
                aux = aux->proximo;
            if (aux->proximo->valor == num)
            {
                if (l->fim == aux->proximo)
                {
                    remover = aux->proximo;
                    aux->proximo = remover->proximo;
                    l->fim = aux;
                }
                else 
                {
                    remover = aux->proximo;
                    aux->proximo = remover->proximo;
                }
                l->tam--;
            }
        }
    }
    else
        printf("lista vazia\n");

    return remover;
}

No* buscar(int num, Lista *l)
{
    No *aux = l->inicio;
    if (aux)
    {
        do
        {
            if (aux->valor == num)
                return aux;
            aux = aux->proximo;
        } while (aux != l->inicio);
    }
    return NULL;
}

void imprimirLista(Lista l)
{
    No *no = l.inicio;

    printf("------------ LISTA / TAM: %i ------------\n\n", l.tam);
    if (no)
    {
        do
        {
            printf("%i ", no->valor);
            no = no->proximo;
        } while (no != l.inicio);
        printf("\ninicio: %i\n", no->valor);
    }
    printf("\n\n------------ FIM LISTA ------------\n");
}
