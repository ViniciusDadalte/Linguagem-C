#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

int main (void)
{
    setlocale(LC_ALL, "Portuguese");

    //criando arquivo de texto
    
    FILE *poema = fopen("C:\\Users\\Administrador\\Desktop\\poema.txt", "w");

    fprintf(poema, "No reino da lógica e da arte digital,\nOnde zeros e uns dançam em harmonia,\n\nEcos de algoritmos ecoam pela vastidão,\nNa sinfonia dos bits, uma magia se cria.\n\nCada linha de código, um verso a tecer,\nEntre chaves e parênteses, o mundo floresce,\n\nUm poema binário, em linguagem a crescer,\nOnde a mente do programador se aquece.\n\nDo HTML ao Python, da C ao Java,\nCada linguagem conta sua própria história,\n\nEm cada função, uma melodia se embala,\nNuma dança de bytes, em busca da glória.\n\nNas entranhas do código, o pensamento voa,\nComo um poeta, o programador cria e sonha,\n\nCombinando palavras, num mundo que aboa,\nUm universo de possibilidades risonhas.\n\nEntão, que a tela em branco seja como o papel,\nE o teclado, a pena do poeta da era digital,\n\nQue cada linha de código seja um novelo fiel,\nTecendo o poema da programação universal.\n");

    fclose(poema);

    system("cls");
    //system("clear");

    FILE *pF = fopen("C:\\Users\\Administrador\\Desktop\\poema.txt", "r");
    char buffer[255];

    if (pF == NULL) //detectando se o arquivo existe
    {
        printf("Incapaz de ler o arquivo\n");
    }   
    else  //lendo o arquivo de texto
    {
        while (fgets(buffer, 255, pF) != NULL)
        {
            printf("%s", buffer); 
        }
    }

    fclose(pF);

    //deletando o arquivo de texto
    
    // if (remove("C:\\Users\\Administrador\\Desktop\\poema.txt") == 0)
    // {
    //     printf("Deletado com sucesso\n");
    // }
    // else 
    // {
    //     printf("Nao foi possivel deletar o arquivo\n");
    // }

    return 0;
}
// deixar essa merda aqui caso eu precise de relembrar de algo