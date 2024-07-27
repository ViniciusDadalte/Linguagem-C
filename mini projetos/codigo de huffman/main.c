#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define TAM 256

typedef struct no
{
    unsigned char letra;
    int frequencia;
    struct no *esquerda, *direita, *proximo;
} No;

typedef struct lista
{
    No *inicio;
    int tam;
} Lista;

// Tabela de frequencia
void iniciaTabelaComZero(unsigned int tab[]);
void preencheTabFrequencia(unsigned char texto[], unsigned int tab[]);
void imprimeTabFrequencia(unsigned int tab[]);
// Lista encadeada ordenada
void criarLista(Lista *l);
void inserirOrdenado(Lista *l, No *n);
void preencherLista(unsigned int tab[], Lista *l);
void imprimeLista(Lista *l);
// Montar arvore de huffman
No* removeNoInico(Lista *l);
No* montarArvore(Lista *l);
void imprimeArvore(No *raiz, int tam);

int main(void)
{
    setlocale(LC_ALL, "Portuguese");
    system("cls");

    unsigned char texto[] = "Vamos aprender a programa";
    unsigned int tabelaFrequencia[TAM];
    Lista l;
    No *arvore;
    
    // Tabela de frequencia
    iniciaTabelaComZero(tabelaFrequencia);
    preencheTabFrequencia(texto, tabelaFrequencia);
    imprimeTabFrequencia(tabelaFrequencia);
    
    // Lista encadeada ordenada
    criarLista(&l);
    preencherLista(tabelaFrequencia, &l);
    imprimeLista(&l);

    // Montar arvore de huffman
    arvore = montarArvore(&l);
    printf("\n\tArvore de huffman\n");
    imprimeArvore(arvore, 0);

    return 0;
}

void iniciaTabelaComZero(unsigned int tab[])
{
    for (int i = 0; i < TAM; i++)
        tab[i] = 0;
}

void preencheTabFrequencia(unsigned char texto[], unsigned int tab[])
{
    int i = 0;
    while (texto[i] != '\0')
    {
        tab[texto[i]]++;
        i++;
    }
}

void imprimeTabFrequencia(unsigned int tab[])
{
    printf("\tTABELA DE FREQUENCIA\n");
    for (int i = 0; i < TAM; i++)
    {
        if (tab[i] > 0)
            printf("\t%i = %u = %c\n", i , tab[i], i);
    }
}

void criarLista(Lista *l)
{
    l->inicio = NULL;
    l->tam = 0;
}

void inserirOrdenado(Lista *l, No *n)
{
    No *aux;

    if (l->inicio == NULL) // A lista esta vazia?
    {
        l->inicio = n;
    }
    else if (n->frequencia < l->inicio->frequencia) // Tem frequencia menor que o inicio da lista
    {
        n->proximo = l->inicio;
        l->inicio = n;
    }
    else
    {
        aux = l->inicio;
        while (aux->proximo != NULL && aux->proximo->frequencia <= n->frequencia)
            aux = aux->proximo;
        n->proximo = aux->proximo;
        aux->proximo = n;
    }
    l->tam++;
}

void preencherLista(unsigned int tab[], Lista *l)
{
    No *novo;
    for (int i = 0; i < TAM; i++)
    {
        if (tab[i] > 0)
        {
            novo = malloc(sizeof(No));
            if (novo == NULL)
            {
                printf("\tErro ao alocar memoria em preencherLista!\n");
                break;
            }

            novo->letra = i;
            novo->frequencia = tab[i];
            novo->esquerda = NULL;
            novo->direita = NULL;
            novo->proximo = NULL;

            inserirOrdenado(l, novo);
        }
    }
}

void imprimeLista(Lista *l)
{
    No *aux = l->inicio;
    
    printf("\n\tLista ordenada: Tamanho: %i\n", l->tam);
    while (aux)
    {
        printf("\tCaracter: %c Frequencia: %i\n", aux->letra, aux->frequencia);
        aux = aux->proximo;
    }
}

No* removeNoInico(Lista *l)
{
    No *aux = NULL;

    if (l->inicio != NULL)
    {
        aux = l->inicio;
        l->inicio = aux->proximo;
        aux->proximo = NULL;
        l->tam--;
    }

    return aux;
}

No* montarArvore(Lista *l)
{
    No *primeiro, *segundo, *novo;
    while (l->tam > 1)
    {
        primeiro = removeNoInico(l);
        segundo = removeNoInico(l);
        
        novo = malloc(sizeof(No));
        if (novo == NULL)
        {
            printf("erro ao alocar memoria em montarArvore\n");
            break;
        }

        novo->letra = '+';
        novo->frequencia = primeiro->frequencia + segundo->frequencia;
        novo->esquerda = primeiro;
        novo->direita = segundo;
        novo->proximo = NULL;

        inserirOrdenado(l, novo);
    }
    return l->inicio;   
}

void imprimeArvore(No *raiz, int tam)
{
    if (raiz->esquerda == NULL && raiz->direita == NULL)
        printf("\tFolha: %c\tAltura: %i\n", raiz->letra, tam);
    else
    {
        imprimeArvore(raiz->esquerda, tam + 1);
        imprimeArvore(raiz->direita, tam + 1);
    }
}

