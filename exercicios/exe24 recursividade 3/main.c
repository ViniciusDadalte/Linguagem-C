#include <stdio.h>
#include <stdlib.h>

int fibonacci(int n);

int main(void)
{
    system("cls");

    int n = 10;
    int res = fibonacci(n);
    printf("%i\n", res);

    return 0;
}

int fibonacci(int n)
{
    // Casos base
    if (n == 0)
    {
        return 0;
    }
    if (n == 1)
    {
        return 1;
    }
    // Caso recursivo
    return fibonacci(n - 1) + fibonacci(n - 2);
}