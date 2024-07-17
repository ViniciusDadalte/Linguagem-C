#include <stdio.h>
#include <math.h>

int main ()
{
    double A;
    double B;
    double C;

    printf("Digite o A: ");
    scanf("%lf", &A);

    printf("\nDigite o B: ");
    scanf("%lf", &B);

    C = sqrt(pow(A, 2) + pow(B, 2)); 

    printf("\n\nO C vale: %lf", C);

    return 0;
}