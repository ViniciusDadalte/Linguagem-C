#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    //system("clear");
    system("cls");
    // memory = an array of bytes within RAM (street)
    // memory block = a single unit (byte) within memory (house), used to hold some value (person)
    // memory address = the address of where a memory block is located (house address)

    /*
        memory = an array of bytes within RAM (street):

        Aqui, o comentário compara a memória do computador a uma "rua" (street) que consiste em um "array de bytes". A memória do computador é organizada em uma sequência linear de células de armazenamento chamadas bytes. Cada byte tem um endereço único que o identifica dentro da memória.
        Assim como em uma rua onde casas estão alinhadas, na memória do computador, os bytes são alinhados sequencialmente.

        memory block = a single unit (byte) within memory (house), used to hold some value (person):

        Aqui, o comentário compara um "bloco de memória" (memory block) a uma "casa" (house) individual dentro da rua da memória.
        Um "bloco de memória" refere-se a uma única unidade de armazenamento na memória do computador, que é o byte. Cada byte pode armazenar uma pequena quantidade de dados, como um caractere, um número ou uma instrução.
        Assim como em uma casa onde uma pessoa pode viver, em um bloco de memória, um valor pode ser armazenado.

        memory address = the address of where a memory block is located (house address):

        Aqui, o comentário explica o conceito de "endereço de memória" comparando-o a um "endereço de casa".
        Um "endereço de memória" é uma identificação única que especifica a localização de um bloco de memória na memória do computador. Da mesma forma que uma casa tem um endereço único para identificá-la em uma rua, um bloco de memória tem um endereço único para identificá-lo na memória do computador.
        Esses endereços são usados para acessar e manipular dados na memória, permitindo que o computador saiba onde armazenar e recuperar informações.
    */

    char a;
    char b[1];

    printf("%d bytes\n", sizeof(a));
    printf("%d bytes\n", sizeof(b));

    printf("%p\n", &a);
    printf("%p\n", &b);
    
    /*
        Vamos analisar o código linha por linha:

        char a;: Declaração de uma variável a do tipo char. char é um tipo de dado que ocupa 1 byte na memória e pode armazenar um caractere ou um pequeno número.

        char b[1];: Declaração de um array b de tamanho 1 de char. Isso significa que b é capaz de armazenar apenas um caractere.

        printf("%d bytes\n", sizeof(a));: Esta linha imprime o tamanho em bytes da variável a usando a função sizeof(). A função sizeof() retorna o tamanho em bytes do tipo ou da variável fornecida como argumento. Como a é do tipo char, que ocupa 1 byte na memória, o resultado impresso será 1 byte.

        printf("%d bytes\n", sizeof(b));: Esta linha imprime o tamanho em bytes do array b. Como b é um array de 1 elemento do tipo char, o tamanho total do array será 1 byte.

        printf("%p\n", &a);: Esta linha imprime o endereço de memória da variável a usando a função printf() com o especificador de formato %p para imprimir endereços de memória. O operador & é usado para obter o endereço de memória de a.

        printf("%p\n", &b);: Esta linha imprime o endereço de memória do array b. Assim como antes, o operador & é usado para obter o endereço de memória do array b.

        Em resumo, este código ilustra como obter o tamanho em bytes e os endereços de memória de variáveis em C, o que é útil para entender como os dados são armazenados na memória do computador.
    */

    system("pause");
    
    return 0;
}
// utilizar essa merda quando eu precisar lembrar