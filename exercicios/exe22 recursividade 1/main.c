#include <stdio.h>
#include <stdlib.h>

#define tam 5

int somar(int *v, int n);
void imprimir(int *v, int t);

int main(void)
{
    system("cls");

    int valores[tam] = {5, 3, 1, 2, 4};
    int res = somar(valores, tam);

    printf("antes: ");
    imprimir(valores, tam);
    printf("soma: %i\n", res);

    return 0;
}

int somar(int *v, int n)
{
    // Caso base
    if (n <= 0)
    {
        return 0;
    }
    // Caso recursivo
    return v[n - 1] + somar(v, n - 1);
}

void imprimir(int *v, int t)
{
    for (int i = 0; i < t; i++)
    {
        printf("%i ", v[i]);
    }
    printf("\n");
}