#include <stdio.h>
#include <math.h>
#include <locale.h>

int main ()
{
    const float PI = 3.14159;
    double raio;
    double circuferencia;
    double area;

    printf("digite o raio do circulo: \n");
    scanf("%lf", &raio);

    circuferencia = 2 * PI * raio;
    area = PI * raio * raio;

    printf("A circuferencia do circulo e: %lf", circuferencia);
    printf("A Area do circulo e: %lf", area);

    return 0;
}