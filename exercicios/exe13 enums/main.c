#include <stdio.h>

enum dia {seg, ter, qua, qui, sex, sab, dom};

int main (void)
{

    enum dia hoje = sab;

    if (hoje == sab || hoje == dom)
    {
        printf("\nFinal de semana :)\n\n");
    }
    else 
    {
        printf("\nDia de escola :(\n\n");
    }

    return 0;
}