#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
    char caracter;
    struct no *proximo;
} No;

No* push(No *pilha, char valor);
No* pop(No **pilha);
void write(No *pilha);
int formPair(char f, char d);
int identifyCalculation(char *x);

int main(void)
{
    system("cls");

    char exp[50];

    printf("\tDigite uma expressao: ");
    fgets(exp, 50, stdin);
    printf("\nExpressao: %s\nRetorno: %i\n", exp, identifyCalculation(exp));

    return 0;
}

No* push(No *pilha, char valor)
{
    No *novo = malloc(sizeof(No));
    if (novo == NULL)
    {
        printf("\tErro ao alocar memoria!\n");
        return NULL;
    }

    novo->caracter = valor;
    novo->proximo = pilha;
    return novo;
}

No* pop(No **pilha)
{
    No *remover = NULL;
    if (*pilha == NULL)
    {
        printf("\tA pilha esta vazia\n");
        return NULL;
    }

    remover = *pilha;
    *pilha = remover->proximo;
    return remover;
}

void write(No *pilha)
{
    printf("\n\tPILHA\n");

    while (pilha)
    {
        printf("\t%c\n", pilha->caracter);
        pilha = pilha->proximo;
    }

    printf("\tFIM PILHA\n\n");
}

int formPair(char f, char d)
{
    switch (f)
    {
    case ')':
        if (d == '(')
            return 1; // bem formada
        else
            return 0; // mal formada
        break;
    case ']':
        if (d == '[')
            return 1; // bem formada
        else
            return 0; // mal formada
        break;
    case '}':
        if (d == '{')
            return 1; // bem formada
        else
            return 0; // mal formada
        break;
    }
}

int identifyCalculation(char *x)
{
    No *remover, *pilha = NULL;

    for (int i = 0; x[i] != '\0'; i++)
    {
        if (x[i] == '(' || x[i] == '[' || x[i] == '{')
        {
            pilha = push(pilha, x[i]);
            write(pilha);
        }
        else if (x[i] == ')' || x[i] == ']' || x[i] == '}')
        {
            remover = pop(&pilha);
            if (remover)
            {
                if (formPair(x[i], remover->caracter) == 0)
                {
                    printf("\tEXPRESSAO MAL FORMADA\n");
                    return 1;
                }
                free(remover);
            }
            else
            {
                printf("\tEXPRESSAO MAL FORMADA\n");
                return 1;
            }           
        }
    }

    write(pilha);
    if (pilha)
    {
        printf("\tExpressao mal formada!\n");
        return 1;
    }
    else
    {
        printf("\tExpressao bem formada\n");
        return 0;
    }
}
