#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main (void)
{

    srand(time(0));

    int numero1 = (rand() % 6) + 1;
    int numero2 = (rand() % 6) + 1;
    int numero3 = (rand() % 6) + 1;

    system("clear"); //limpa a tela mac e linux
    system("cls"); //limpa a tela windows

    printf("%i ", numero1);
    printf("%i ", numero2);
    printf("%i ", numero3);
    
    printf("\n\n");

    return 0;
}