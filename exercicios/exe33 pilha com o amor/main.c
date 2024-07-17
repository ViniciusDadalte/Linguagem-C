#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
    int dado;
    struct no *prox;  
} No;

typedef struct pilha
{
    No *topo;
} Pilha;

void iniciaPilha(Pilha *p);
void push(int dado, Pilha *p);
int pop(Pilha *p);
void write(Pilha *p);

int main(void)
{
    system("cls");

    Pilha *p = malloc(sizeof(Pilha));
    if (p == NULL)
    {
        printf("erro ao alocar memoria\n");
        return 1;
    }

    int opcao;
    int dado;
    iniciaPilha(p);

    do
    {
        printf("0 - sair\n1 - empilhar\n2 - desempilhar\n3 - imprimir\n");  
        scanf("%i", &opcao);  
        switch (opcao)
        {
        case 1:
            printf("Digite o dado: ");
            scanf("%i", &dado);
            system("cls");
            push(dado, p);
            break;
        case 2:
            system("cls");
            pop(p);
            break;
        case 3:
            system("cls");
            write(p);
            break;    
        default:
            if (opcao != 0)
            {
                system("cls");
                printf("Opcao invalida!\n");
            }
            break;
        }
    } while (opcao != 0);
    

    return 0;
}

void iniciaPilha(Pilha *p)
{
    p->topo = NULL;
}

void push(int dado, Pilha *p)
{
    No *ptr = malloc(sizeof(No));
    if (ptr == NULL)
    {
        printf("erro ao alocar memoria\n");
        return;
    }

    ptr->dado = dado;
    ptr->prox = p->topo;
    p->topo = ptr;
}

int pop(Pilha *p)
{
    No *ptr = p->topo;
    int dado;

    if (ptr == NULL)
    {
        printf("a pilha esta vazia\n");
        return 1;
    }

    p->topo = ptr->prox;
    ptr->prox = NULL;
    dado = ptr->dado;
    free(ptr);
    return dado;
}

void write(Pilha *p)
{
    system("cls");

    No *ptr = p->topo;
    if (ptr == NULL)
    {
        printf("pilha vazia\n");
        return;
    }

    printf("\n----------- PILHA -----------\n");
    while (ptr)
    {
        printf("%i\n", ptr->dado);
        ptr = ptr->prox;    
    }
    printf("----------- FIM PILHA -----------\n\n");
}