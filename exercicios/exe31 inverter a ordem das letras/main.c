#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no
{
    char caracter;
    struct no *proximo;
} No;

void readString(char *str, int maxLen);
No* push(No *pilha, char valor);
No* pop(No **pilha);
void changeWords(char *x);

int main(void)
{
    system("cls");

    int max = 100;
    char text[max]; 

    printf("Digite um texto para inverter: ");
    readString(text, max);
    changeWords(text);

    return 0;
}

void readString(char *str, int maxLen) 
{
    if (fgets(str, maxLen, stdin) != NULL) 
    {
        // Remove o '\n' se existir
        char *newline = strchr(str, '\n');
        if (newline) 
        {
            *newline = '\0';
        }
    } 
    else 
    {
        // Se fgets falhar, assegure-se que a string é vazia
        str[0] = '\0';
    }
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

void changeWords(char *x)
{
    No *remover, *pilha = NULL;

    for (int i = 0; x[i] != '\0'; i++)
    {
        if (x[i] != ' ')
            pilha = push(pilha, x[i]);                    
        else
        {
            while (pilha)
            {
                remover = pop(&pilha);
                printf("%c", remover->caracter);
                free(remover);
            }
            printf(" ");
        }
    }
    while (pilha)
    {
        remover = pop(&pilha);
        printf("%c", remover->caracter);
        free(remover);
    }
    printf("\n");
}
