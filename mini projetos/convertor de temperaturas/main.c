#include <stdio.h>
#include <ctype.h>

int main ()
{

    char unidade;
    float temperatura;

    printf("Qual o tipo de unidade? (F) ou (C): ");
    scanf("%C", &unidade);

    unidade = toupper(unidade);

    if (unidade == 'C')
    {
        printf("\ncoloque a temperatura em celcius: ");
        scanf("%f", &temperatura);
        
        temperatura = (temperatura * 9 / 5) + 32;
        
        printf("\na temperatura em farenhaint e: %.1f\n", temperatura);
    }
    else if (unidade == 'F')
    {
        printf("\ncoloque a temperatura em farenhaint: ");
        scanf("%f", &temperatura);

        temperatura = ((temperatura - 32) * 5) / 9;
        
        printf("\na temperatura em  celcius e: %.1f\n", temperatura);
    }
    else
    {
        printf("\nDigite corretamente!\n");
    }

    return 0;
}