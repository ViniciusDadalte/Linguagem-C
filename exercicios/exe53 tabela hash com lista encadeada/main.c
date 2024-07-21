#include <stdio.h>
#include <stdlib.h>

#define TAM 31

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

void iniciaLista(Lista *l);
void inserirNaLista(int num, Lista *l);
void imprimirLista(Lista *l);
void iniciaTabela(Lista t[]);
int funcaoHash(int chave);
void inserir(int valor, Lista t[]);
int busca(int chave, Lista t[]);
void imprimirTabela(Lista t[]);

int main(void)
{
    system("cls");

    int opcao, dado, retorno;
    Lista tabela[TAM];
    iniciaTabela(tabela);

    do
    {
        printf("\n0 - sair\n1 - inserir\n2 - buscar\n3 - imprimir\n");
        scanf("%i", &opcao);

        switch (opcao)
        {
        case 1:
            printf("Digite o dado: ");
            scanf("%i", &dado);
            inserir(dado, tabela);
            system("cls");
            break;
        case 2:
            printf("Digite o dado para buscar: ");
            scanf("%i", &dado);
            system("cls");
            retorno = busca(dado, tabela);
            if (retorno != 0)
                printf("valor encontrado: %i\n", retorno);
            else
                printf("valor nao encontrado\n");
            break;
        case 3:
            system("cls");
            imprimirTabela(tabela);
            break;
        default:
            if (opcao != 0)
            {
                system("cls");
                printf("opcao invalida!\n");
            }
        }
    } while (opcao != 0);
    

    return 0;
}

void iniciaLista(Lista *l)
{
    l->inicio = NULL;
    l->tam = 0;
}

void inserirNaLista(int num, Lista *l)
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

int buscarNaLista(int num, Lista *l)
{
    No *aux = l->inicio;
    while (aux && aux->valor != num)
        aux = aux->proximo;
    if (aux)
        return aux->valor;
    return 0;
}

void imprimirLista(Lista *l)
{
    No *aux = l->inicio;
    printf("Tam: %i: ", l->tam);
    while (aux)
    {
        printf("%i ", aux->valor);
        aux = aux->proximo;
    }
}

void iniciaTabela(Lista t[])
{
    for (int i = 0; i < TAM; i++)
        iniciaLista(&t[i]);
}

int funcaoHash(int chave)
{
    return chave % TAM;
}

void inserir(int valor, Lista t[])
{
    int id = funcaoHash(valor);
    inserirNaLista(valor, &t[id]);
}

int busca(int chave, Lista t[])
{
    int id = funcaoHash(chave);
    printf("\nindice gerado: %i\n", id);
    return buscarNaLista(chave, &t[id]);
}

void imprimirTabela(Lista t[])
{
    for (int i = 0; i < TAM; i++)
    {
        printf("%i = ", i);
        imprimirLista(&t[i]);
        printf("\n");
    }
}
