#include <stdio.h>
#include <locale.h>

int main ()
{
    setlocale(LC_ALL, "Portuguese");
    int num1, num2;
    
    printf("\nDigite um numero:\n\n");
    scanf("%i", &num1);

    printf("\nDigite outro numero:\n\n");
    scanf("%i", &num2);
    
    printf("A soma desses dois numeros e %i\n\n", num1 + num2);

    return 0;
}