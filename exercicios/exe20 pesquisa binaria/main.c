#include <stdio.h>
#include <stdlib.h>

#define max 12

int pesquisaB(int valores[], int procurado, int tamanho);

int main(void)
{
    system("cls");

    int lista[max] = {2, 10, 15, 17, 21, 28, 40, 55, 60, 61, 62, 83};
    printf("%i\n", pesquisaB(lista, 2, max));

    return 0;
}

int pesquisaB(int valores[], int procurado, int tamanho)
{
    int posLi = 0;
    int posLs = tamanho - 1;

    while (posLi <= posLs)
    {
        int posMeio = (posLi + posLs) / 2;
        int palpite = valores[posMeio];

        if (palpite == procurado)
        {
            return posMeio;
        }
        else if (palpite > procurado)
        {
            posLs = posMeio - 1;
        }
        else
        {
            posLi = posMeio + 1;
        }
    }
    return -1;
}
