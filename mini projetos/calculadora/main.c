#include <stdio.h>

int main ()
{
    
    char operador;
    double num1, num2, resultado;

    printf("\nEscreva o operador (+,-,*,/): ");
    scanf("%c", &operador);

    printf("\nDigite o primeiro numero: ");
    scanf("%lf", &num1);

    printf("\nDigite o segundo numero: ");
    scanf("%lf", &num2);

    switch (operador)
    {
    case '+':
        printf("A soma desses dois numero e: %lf", num1 + num2);
        break;
    case '-':
        printf("A subtracao desses dois numero e: %lf", num1 - num2);
        break;
    case '*':
        printf("A multiplicacao desses dois numero e: %lf", num1 * num2);
        break;
    case '/':
        printf("A divisao desses dois numero e: %lf", num1 / num2);
        break;
    default:
        printf("\n%c este operaodor nao e valido com esses aqui: (+,-,*,/)\n", operador);
        break;
    }

    return 0;
}