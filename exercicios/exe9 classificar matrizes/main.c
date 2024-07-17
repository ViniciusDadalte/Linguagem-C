#include <stdio.h>
#include <string.h>

void sort(int array[], int tamanho);
void escreveArray (int array[], int tamanho);
void sortLetras (char array[], int tamanho);
void escreveArrayLetras (char array[], int tamanho);

int main(void)
{
    int array[] = {9, 1, 8, 2, 7, 3, 6, 4, 5};
    int tamanho = sizeof(array) / sizeof(array[0]);

    char arrayLetras[] = {'F', 'A', 'D', 'B', 'C'};
    int tamanhoLetra = sizeof(arrayLetras) / sizeof(arrayLetras[0]);

    sort(array, tamanho);
    escreveArray(array, tamanho);

    printf("\n");

    sortLetras(arrayLetras, tamanhoLetra);
    escreveArrayLetras(arrayLetras, tamanhoLetra);

    printf("\n");

    return 0;
}

void sort(int array[], int tamanho)
{
    for (int i = 0; i < tamanho - 1; i++)
    {
        for (int j = 0; j < tamanho - i - 1; j++)
        {
            if (array[j] > array[j + 1])
            {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

void escreveArray (int array[], int tamanho)
{
    for (int i = 0; i < tamanho; i++)
    {
        printf("%i ", array[i]);
    }
}

void sortLetras (char array[], int tamanho)
{
    for (int i = 0; i < tamanho - 1; i++)
    {
        for (int j = 0; j < tamanho - i - 1; j++)
        {
            if (array[j] > array[j + 1])
            {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

void escreveArrayLetras (char array[], int tamanho)
{
    for (int i = 0; i < tamanho; i++)
    {
        printf("%c ", array[i]);
    }
}