#include <stdio.h>
#include <stdlib.h>

int contar(int n);
int fatorial(int n);
int somatorio(int n);

int main(void)
{
    system("cls");

    //contar(10);
    //printf("%i\n", fatorial(5));
    printf("%i\n", somatorio(5));

    return 0;
}

int contar(int n)
{
    if (n < 0) // Caso base
    {
        printf("\n");
        return 0;
    }
    else // Caso recursivo
    {
        printf("%i ", n);        
        contar(n - 1);        
    }
}

int fatorial(int n)
{
    if (n == 1) // Caso base
    {
        return 1;
    }
    // Caso recursivo
    return n * fatorial(n - 1);
}

int somatorio(int n)
{
    if (n <= 0) // Caso base
    {
        return 0;
    }
    // Caso recursivo
    return n + somatorio(n - 1);
}