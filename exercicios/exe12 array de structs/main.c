#include <stdio.h>

typedef struct 
{
    char nome[12];
    float gpa;
} Estudante;

int main (void)
{
    printf("\n");

    Estudante Estudante1 = {"Bob esponja", 3.0};
    Estudante Estudante2 = {"Patrick", 2.5};
    Estudante Estudante3 = {"Sandy", 4.0};
    Estudante Estudante4 = {"Lula molusco", 2.0};

    Estudante Estudantes[] = {Estudante1, Estudante2, Estudante3, Estudante4};
    
    for (int i = 0; i < sizeof(Estudantes) / sizeof(Estudantes[0]); i++)
    {
        printf("%-12s\t", Estudantes[i].nome);
        printf("%.2f\n", Estudantes[i].gpa);
    }

    printf("\n");

    return 0;
}