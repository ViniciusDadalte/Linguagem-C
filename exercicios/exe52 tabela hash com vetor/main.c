#include <stdio.h>
#include <stdlib.h>

#define TAM 31

void iniciaTable(int t[]);
int funcaoHash(int chave);
void inserir(int valor, int t[]);
int busca(int chave, int t[]);
void imprimirTabela(int t[]);

int main(void)
{
    system("cls");

    int tabela[TAM], opcao, dado, retorno;
    iniciaTable(tabela);

    do
    {
        printf("\n0 - sair\n1 - inserir\n2 - buscar\n3 - imprimir\n");
        scanf("%i", &opcao);

        switch (opcao)
        {
        case 1:
            printf("Digite o dado: ");
            scanf("%i", &dado);
            inserir(dado, tabela);
            system("cls");
            break;
        case 2:
            printf("Digite o dado para buscar: ");
            scanf("%i", &dado);
            system("cls");
            retorno = busca(dado, tabela);
            if (retorno != 0)
                printf("valor encontrado: %i\n", retorno);
            else
                printf("valor nao encontrado\n");
            break;
        case 3:
            system("cls");
            imprimirTabela(tabela);
            break;
        default:
            if (opcao != 0)
            {
                system("cls");
                printf("opcao invalida!\n");
            }
            break;
        }
    } while (opcao != 0);
    

    return 0;
}

void iniciaTable(int t[])
{
    for (int i = 0; i < TAM; i++)
        t[i] = 0;
}

int funcaoHash(int chave)
{
    return chave % TAM;
}

void inserir(int valor, int t[])
{
    int id = funcaoHash(valor);

    while (t[id] != 0)
        id = funcaoHash(id + 1);
    t[id] = valor;
}

int busca(int chave, int t[])
{
    int id = funcaoHash(chave);
    printf("indice gerado: %i\n", id);
    while (t[id] != 0)
    {
        if (t[id] == chave)
            return t[id];
        else
            id = funcaoHash(id + 1);
    }
    return 0;
}

void imprimirTabela(int t[])
{
    for (int i = 0; i < TAM; i++)
        printf("%i = %i\n", i, t[i]);
}
