#include <stdio.h>
#include <stdlib.h>

#define tam 10

void ordenacaoSelecaoCrescente(int *array, int t);
void ordenacaoSelecaoDecrescente(int *array, int t);
void imprimirArray(int *array, int t);

int main(void)
{
    system("cls");

    int array[tam] = {12, 20, 5, 38, 27, 3, 10, 42, 54, 2};

    printf("Array original: ");
    imprimirArray(array, tam);

    printf("\n");
    
    printf("Array ordenado de forma crescente: ");
    ordenacaoSelecaoCrescente(array, tam);
    imprimirArray(array, tam);

    printf("\n");

    printf("Array ordenado de forma decrescente: ");
    ordenacaoSelecaoDecrescente(array, tam);
    imprimirArray(array, tam);
    
    return 0;
}

void ordenacaoSelecaoCrescente(int *array, int t)
{
    for (int i = 0; i < t - 1; i++)
    {
        int iMin = i;
        for (int j = i + 1; j < t; j++)
        {
            if (array[j] < array[iMin])
            {
                iMin = j;
            }
        }
        int tmp = array[i];
        array[i] = array[iMin];
        array[iMin] = tmp;
    }
}

void ordenacaoSelecaoDecrescente(int *array, int t)
{
    for (int i = 0; i < t - 1; i++)
    {
        int iMin = i;
        for (int j = i + 1; j < t; j++)
        {
            if (array[j] > array[iMin])
            {
                iMin = j;
            }
        }
        int tmp = array[i];
        array[i] = array[iMin];
        array[iMin] = tmp;
    }
}

void imprimirArray(int *array, int t)
{
    for (int i = 0; i < t; i++)
    {
        printf("%i ", array[i]);
    }
    printf("\n");
}