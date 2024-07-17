#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <locale.h>

void limparBuffer() 
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF) { }
}

int main (void)
{
    setlocale(LC_ALL, "Portuguese");

    char perguntas[][100] = {"1. Quem e o pai do cleverson?: ",
                             "2. Qual e o professor mais maluco?: ",
                             "3. Quem e o mais viado do grupo?: ",
                             "4. O alexandre e?: ",
                             "5. A eveline e?: ",
                             "6. A tatiana e?: ",
                             "7. O jogo favorito do evandro e?:",
                             "8. mimimimimiimimiimi?: ",
                             "9. Se vc nao tirar a mao de mim eu vou?: ",
                             "10. Qual a bebida favorita do joao pedro?: "};

    char opicoes[][100] = {"A. O cassio", "B. O vitor", "C. Ninguem sabe", "D. Edi japa maluco",
                           "A. Professora leticia", "B. Professor edi", "C. Professor alessandro", "D. Professor handerson",
                           "A. Vitor", "B. Evandro", "C. Bert", "D. Ana sofhia",
                           "A. Viado", "B. Coach", "C. Pobre", "D. Bonito",
                           "A. Puta", "B. Bonita", "C. Vagabunda", "D. Inteligente",
                           "A. Da galera", "B. Privada", "C. Apertada", "D. Careca",
                           "A. Among us", "B. Fortnite", "C. Free fire", "D. Geoguester",
                           "A. Thiago paci", "B. Bert", "C. Evandro", "D. Joao pedro",
                           "A. Te bater", "B. Te dar carinho", "C. Te beijar", "D. Rasgar sua roupa",
                           "A. Agua", "B. Poha", "C. Guarana", "D. Coca"};

    char respostas[10] = {'C', 'B', 'A', 'B', 'C', 'A', 'D', 'A', 'D', 'B'};

    int numeroDeQuestoes = sizeof(perguntas) / sizeof(perguntas[0]);

    char palpite;
    int pontuacao = 0; 
    
    system("cls");
    //system("clear");

    printf("QUIZ GAME\n");
    
    for (int i = 0; i < numeroDeQuestoes; i++)
    {
        printf("******************************\n");
        printf("%s\n", perguntas[i]);
        printf("******************************\n");

        for (int j = (i * 4); j < (i * 4) + 4; j++)
        {
            printf("%s \n", opicoes[j]);
        }

        printf("Palpite: ");
        scanf("%c", &palpite);
        limparBuffer();

        palpite = toupper(palpite);
        
        system("cls");
        //system("clear");

        if (palpite != 'A' && palpite != 'B' && palpite != 'C' && palpite != 'D') 
        {
            printf("Opcao invalida! Por favor, escolha entre A, B, C ou D.\n");
            i--;
            continue;
        }
        
        if (palpite == respostas[i])
        {
            printf("CORRETO!! :D\n");
            pontuacao++;
        }
        else
        {
            printf("Errado :/\n");
        }
    }

    system("cls");
    //system("clear");

    printf("**************************\n");
    printf("Pontuacao final: %i/%i\n", pontuacao, numeroDeQuestoes);
    printf("**************************\n\n");

    return 0;
}