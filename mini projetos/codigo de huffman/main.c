#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define TAM 256

// Tabela de frequencia
void iniciaTabelaComZero(unsigned int tab[]);
void preencheTabFrequencia(unsigned char texto[], unsigned int tab[]);
void imprimeTabFrequencia(unsigned int tab[]);

int main(void)
{
    setlocale(LC_ALL, "Portuguese");
    system("cls");

    unsigned char texto[] = "Vamos aprender programação";
    unsigned int tabelaFrequencia[TAM];

    iniciaTabelaComZero(tabelaFrequencia);
    preencheTabFrequencia(texto, tabelaFrequencia);
    imprimeTabFrequencia(tabelaFrequencia);

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

