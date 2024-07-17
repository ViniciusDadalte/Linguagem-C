#include <stdio.h>

int main(void)
{

    // & = E 
    // | = OU
    // ^ = OU Exclusivo 
    // ~ = Não
    // <<  vai para esquerda
    // >>  vai pra direita

    int x = 6;  //    6 = 00000110
    int y = 12; //   12 = 00001100
    int z = 0;  //    0 = 00000000

    z = x & y;
    printf("AND = %d\n", z);

    z = x | y;
    printf("OR = %d\n", z);

    z = x ^ y;
    printf("XOR = %d\n", z);

    z = ~x;
    printf("Not = %d\n", z);

    z = x << 2;
    printf("SHIFT LEFT = %d\n", z);

    z = x >> 2;
    printf("SHIFT RIGHT = %d\n", z);

    //Usar essa merda quando ficar com duvida de algo

    return 0;
}