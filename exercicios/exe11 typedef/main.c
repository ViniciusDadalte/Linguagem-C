#include <stdio.h>

// typedef char usuario[25];

typedef struct
{
    char nome[25];
    char senha[12];
    int id;
} Usuario;

//ja pode fazer direto em uma struct, mas tbm da pra fazer separado pra ficar mais facil.

int main (void)
{

    // usuario carlos = "Carlos Rogerio da Costa";
    // printf("%s\n", carlos);

    Usuario carlos = {"Carlos Rogerio da Costa", "12345", 1};
    Usuario rogerio = {"Rogerio Carlos da Costa", "54321", 2};

    printf("%s\n", carlos.nome);
    printf("%s\n", carlos.senha);
    printf("%i\n\n", carlos.id);

    printf("%s\n", rogerio.nome);
    printf("%s\n", rogerio.senha);
    printf("%i\n\n", rogerio.id);

    return 0;
}