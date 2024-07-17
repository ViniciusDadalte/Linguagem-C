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

Pessoa lerPessoa();
void imprimirPessoa(Pessoa p);
No* push(No *topo);
No* pop(No **topo);
void imprimirPilha(No *topo);

int main(void) 
{
    system("cls");
    
    No *remover, *topo = NULL;
    int opcao;

    do 
    {
        printf("\n0 - Sair\n1 - Empilhar\n2 - Desempilhar\n3 - Imprimir\n");
        scanf("%i", &opcao);
        getchar();

        switch (opcao) 
        {
            case 1:
                system("cls");
                
                topo = push(topo);
                break;
            case 2:
                system("cls");
                
                remover = pop(&topo);
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
                
                imprimirPilha(topo);
                break;
            default:
                if (opcao != 0)
                    printf("Opção inválida!");
        }
    } while (opcao != 0);

    return 0;
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

No* push(No *topo) 
{
    No *novo = malloc(sizeof(No));
    if (novo == NULL) 
    {
        printf("Erro ao alocar memória\n");
        return topo;
    }

    novo->p = lerPessoa();
    novo->proximo = topo;
    return novo;
}

No* pop(No **topo) 
{
    if (*topo == NULL) 
    {
        printf("\nPilha vazia!\n");
        return NULL;
    }

    No *remover = *topo;
    *topo = remover->proximo;
    return remover;
}

void imprimirPilha(No *topo) 
{
    printf("\n-------------- PILHA --------------\n");

    while (topo) 
    {
        imprimirPessoa(topo->p);
        topo = topo->proximo;       
    }

    printf("\n-------------- FIM PILHA --------------\n");
}