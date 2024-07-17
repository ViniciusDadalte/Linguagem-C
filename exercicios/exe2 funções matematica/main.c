#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <math.h>

int main ()
{
    setlocale(LC_ALL, "portuguese");

    double A = sqrt(9); //raiz quadrada de um numero
    
    double B = pow(2, 4); //potencia entao no caso 2 elevado a 4
    
    int C = round(3.14); //arredonda o numero para baixo
    
    int D = ceil(3.14); //arredondo o numero para cima
    
    int E = floor(3.99); //arredonda tbm
    
    double F = fabs(-100); // nao entendi muito bem mas meio que o numero fica maior
    
    double G = log(3); //vemos o logatiritimo de um numero
    
    double H = sin(45); //seno 
    
    double I = cos(45); //coseno
    
    double J = tan(45); //tangente
    
    
    printf("\n%lf", A); // 

    
    return 0;

}