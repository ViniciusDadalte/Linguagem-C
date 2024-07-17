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

    Pilha *p1 = malloc(sizeof(Pilha));
    if (p1 == NULL)
    {
        printf("Erro ao alocar memoria\n");
        return 1;
    }

    iniciaPilha(p1);

    push(10, p1);
    push(20, p1);
    push(30, p1);

    write(p1);

    printf("Desempilhando:\n%i\n", pop(p1));
    write(p1);
    
    printf("Desempilhando:\n%i\n", pop(p1));
    write(p1);

    printf("Desempilhando:\n%i\n", pop(p1));
    pop(p1);
    
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
        printf("Erro ao alocar memoria\n");
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
        printf("Pilha vazia\n");
        return 1;
    }
    else
    {
        p->topo = ptr->prox;
        ptr->prox = NULL;
        dado = ptr->dado;
        free(ptr);
        return dado;
    }
}

void write(Pilha *p)
{
    No *ptr = p->topo;
    if (ptr == NULL)
    {
        printf("Pilha vazia\n");
        return;
    }
    else
    {
        while(ptr)
        {
            printf("%d\n", ptr->dado);
            ptr = ptr->prox;
        }
    }
}