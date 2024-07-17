#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void display (int var, int *ptr);
void update (int *p);

int main (void)
{
    setlocale(LC_ALL, "Portuguese");
    
    system("cls");
    //system("clear");
    
    int var = 15;
    int *ptr;
    
    ptr = &var;

    display(var, ptr);

    printf("*******************************************\n\n");

    update(&var);

    display(var, ptr);
    
    system("pause");

    return 0;
} //end main


void display (int var, int *ptr) 
{
    printf("conteudo de var: %i\n", var);
    printf("enderesso de var: %p\n\n", &var);

    printf("conteudo apontado por prt: %i\n", *ptr);
    printf("enderesso apontado por ptr: %p\n", ptr);
    printf("enderesso de ptr: %p\n\n", &ptr);
} //end display

void update (int *p)
{
    *p = *p + 1;
} //end update

// ponteiros:
// *ptr : aponta o conteudo da variavel apontada
// ptr : aponta o endereço da variavel apontada
// &ptr : mostra o endereço do ptr 