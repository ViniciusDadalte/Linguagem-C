#include <stdio.h>

#define TAMANHO_ARRAY 5

int main() {
    int array[TAMANHO_ARRAY] = {1, 2, 3, 4, 5};
    int i;

    // Obtendo o tamanho do array usando a macro TAMANHO_ARRAY
    int tamanho = sizeof(array) / sizeof(array[0]);

    // Percorrendo o array usando array[i]
    for (i = 0; i < tamanho; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    return 0;
}
