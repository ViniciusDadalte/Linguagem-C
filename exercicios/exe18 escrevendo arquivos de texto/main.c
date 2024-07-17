#include <stdio.h>

int main(void)
{
    // "r": Leitura, falha se o      arquivo não existir.
    // "w": Escrita, cria um novo arquivo ou sobrescreve um arquivo existente.
    // "a": Escrita, anexa ao final do arquivo ou cria um novo arquivo.
    // "r+": Leitura e escrita, falha se o arquivo não existir.
    // "w+": Leitura e escrita, cria um novo arquivo ou sobrescreve um arquivo existente.
    // "a+": Leitura e escrita, anexa ao final do arquivo ou cria um novo arquivo.
    //C:\Users\Administrador\Desktop

    
    FILE *pF = fopen("C:\\Users\\Administrador\\Desktop\\test.txt", "w"); 

    fprintf(pF, "Eu estou te vendo rs *piscadinha*");

    fclose(pF);

   
//    if (remove("C:\\Users\\Administrador\\Desktop\\test.txt") == 0)
//    {
//        printf("O arquivo foi deletado com sucesso!!\n");
//    }
//    else
//    {
//        printf("O arquivo não foi deletado\n");
//    }
    
    return 0;
}