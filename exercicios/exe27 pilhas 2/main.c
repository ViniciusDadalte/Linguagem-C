#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int dia, mes, ano;
} Data;

typedef struct {
    char nome[50];
    Data aniversario;
} Pessoa;

typedef struct no {
    Pessoa p;
    struct no *proximo;
} No;

typedef struct 
{
    No *topo;
    int tam;
} Pilha;

void criarPilha(Pilha *p);
Pessoa lerPessoa();
void imprimirPessoa(Pessoa p);
void push(Pilha *p);
No* pop(Pilha *p);
void imprimirPilha(Pilha *p) ;

int main(void) 
{
    system("cls");
    
    No *remover;
    Pilha p;
    int opcao;

    criarPilha(&p);

    do 
    {
        printf("\n0 - Sair\n1 - Empilhar\n2 - Desempilhar\n3 - Imprimir\n");
        scanf("%i", &opcao);
        getchar();

        switch (opcao) 
        {
            case 1:
                system("cls");

                push(&p);
                
                break;
            case 2:
                system("cls");
                
                remover = pop(&p);
                if (remover == NULL) 
                {
                    printf("\nSem nó a remover\n");
                } 
                else 
                {
                    printf("\nElemento removido com sucesso!");
                    imprimirPessoa(remover->p);
                    free(remover);
                }

                break;
            case 3:
                system("cls");
                
                imprimirPilha(&p);

                break;
            default:
                if (opcao != 0)
                {
                    printf("Opção inválida!");
                }
        }
    } while (opcao != 0);

    return 0;
}

void criarPilha(Pilha *p)
{
    p->topo = NULL;
    p->tam = 0;
}

Pessoa lerPessoa() 
{
    Pessoa p;
    printf("Digite seu nome e sua data de nascimento dd mm aaaa:\n");
    scanf(" %49[^\n]", p.nome);
    scanf("%d%d%d", &p.aniversario.dia, &p.aniversario.mes, &p.aniversario.ano);
    return p;
}

void imprimirPessoa(Pessoa p) 
{
    printf("\nNome: %s\nData: %i/%i/%i\n", p.nome, p.aniversario.dia, p.aniversario.mes, p.aniversario.ano);
}

void push(Pilha *p)
{
    No *novo = malloc(sizeof(No));
    
    if (novo)
    {
        novo->p = lerPessoa();
        novo->proximo = p->topo;
        p->topo = novo;
        p->tam++;
    }
    else 
    {
        printf("Erro ao alocar memória\n");
    }
}

No* pop(Pilha *p) 
{
    if (p->topo == NULL) 
    {
        printf("\nPilha vazia!\n");
        return NULL;
    }

    No *remover = p->topo;
    p->topo = remover->proximo;
    p->tam--;
    return remover;
}

void imprimirPilha(Pilha *p) 
{
    No *aux = p->topo;

    printf("\n-------------- PILHA Tam: %i --------------\n", p->tam);

    while (aux) 
    {
        imprimirPessoa(aux->p);
        aux = aux->proximo;       
    }

    printf("\n-------------- FIM PILHA --------------\n");
}