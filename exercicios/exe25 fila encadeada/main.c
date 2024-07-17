#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
    int valor;
    struct no *proximo;
} no;


void inserir_no_inicio(no **lista);

int main(void)
{
    system("cls");


    return 0;
}

void inserir_no_inicio(no **lista)
{
    no *novo = malloc(sizeof(no));
    if (novo == NULL)
    {
        return 1;
    }
}