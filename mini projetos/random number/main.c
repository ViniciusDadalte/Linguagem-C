#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main (void)
{

    const int min = 1;
    const int max = 100;

    int guess, answer;
    int guesses = 0;

    srand(time(0));

    answer = (rand() % max) + min;

    //system("clear");
    system("cls");

    do {

        printf("Enter a guess (1 and 100): ");
        scanf("%i", &guess);

        if (guess < min || guess > max)
        {
            printf("Number is not between (1 and 100)\n");
        }
        else if (guess > answer)
        {
            printf("Too hight!\n");
        }
        else if (guess < answer)
        {
            printf("Too low!\n");
        }
        else
        {
            //system("clear");
            system("cls");
            printf("CORRECT!!\n");
        }
        guesses++;
    } while (guess != answer);


    printf("**************************\n");
    printf("answer: %i\n", answer);
    printf("guesses: %i\n", guesses);
    printf("**************************\n\n");

    return 0;
}