#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
    char nome[50];
    int cpf;
} Pessoa;

typedef struct no
{
    Pessoa p;
    struct no *esquerda, *direita;
} NoArv;

Pessoa lerPessoa();
void imprimirPessoa(Pessoa p);
void inserir(Pessoa p, NoArv **raiz);
NoArv* buscar(int cpf, NoArv *raiz);
int altura(NoArv *raiz);
int quantidadeDeNos(NoArv *raiz);
int quantidadeDeFolhas(NoArv *raiz);
NoArv* remover(int cpf, NoArv *raiz);
void imprimirArvore(NoArv *raiz);
void imprimirArvoreOrdenado(NoArv *raiz);

int main(void)
{
    system("cls");

    NoArv *buscado, *raiz = NULL;
    int opcao, cpf;

    do
    {
        printf("\n0 - sair\n1 - inserir\n2 - imprimirN\n3 - imprimirO\n4 - buscar\n5 - altura\n6 - tamanho\n7 - folhas\n8 - remover\n");
        scanf("%i", &opcao);
        getchar();

        switch (opcao)
        {
        case 1:
            inserir(lerPessoa(), &raiz);
            system("cls");
            break;
        case 2:
            system("cls");
            imprimirArvore(raiz);
            break;
        case 3:
            system("cls");
            imprimirArvoreOrdenado(raiz);
            break;
        case 4:
            printf("digite o cpf a ser buscado: ");
            scanf("%i", &cpf);
            system("cls");
            buscado = buscar(cpf, raiz);
            if (buscado)
            {
                printf("valor encontrado:\n");
                imprimirPessoa(buscado->p);
            }
            else
                printf("valor nao encontrado!\n");
            break;
        case 5:
            system("cls");
            printf("Altura da arvore: %i\n", altura(raiz));
            break;
        case 6:
            system("cls");
            printf("Tamanho: %i", quantidadeDeNos(raiz));
            break;
        case 7:
            system("cls");
            printf("Folhas: %i", quantidadeDeFolhas(raiz));
            break;
        case 8:
            system("cls");
            if (raiz == NULL)
            {
                printf("arvore esta vazia\n");
            }
            else
            {
                imprimirArvoreOrdenado(raiz);
                printf("\ndigite o cpf que quer remover: ");
                scanf("%i", &cpf);
                raiz = remover(cpf, raiz);
            }
            break;
        default:
            if (opcao != 0)
            {
                system("cls");
                printf("opcao invalido!\n");
            }
            break;
        }
    } while (opcao != 0);  

    return 0;
}

Pessoa lerPessoa()
{
    Pessoa p;

    printf("Digite o nome da pessoa: ");
    fgets(p.nome, 49, stdin);
    printf("\nDigite o cpf da pessoa: ");
    scanf("%i", &p.cpf);

    return p;
}

void imprimirPessoa(Pessoa p)
{
    printf("\nPessoa:\n");
    printf("\tNome: %s", p.nome);
    printf("\tCpf: %i\n", p.cpf);
}

void inserir(Pessoa p, NoArv **raiz)
{
    NoArv *aux = *raiz;
    while (aux)
    {
        if (p.cpf < aux->p.cpf)
            raiz = &aux->esquerda;
        else
            raiz = &aux->direita;
        aux = *raiz;
    }
    
    aux = malloc(sizeof(NoArv));
    if (aux == NULL)
    {
        printf("Erro ao alocar memoria\n");
        return;
    }
    aux->p = p;
    aux->esquerda = NULL;
    aux->direita = NULL;
    *raiz = aux;
}

NoArv* buscar(int cpf, NoArv *raiz)
{
    while (raiz)
    {
        if (cpf < raiz->p.cpf)
            raiz = raiz->esquerda;
        else if (cpf > raiz->p.cpf)
            raiz = raiz->direita;
        else
            return raiz;
    }
    return NULL;
}

int altura(NoArv *raiz)
{
    if (raiz == NULL)
    {
        return -1;
    }
    else
    {
        int esq = altura(raiz->esquerda);
        int dir = altura(raiz->direita);

        if (esq > dir)
            return esq + 1;
        else
            return dir + 1;
    }
}

int quantidadeDeNos(NoArv *raiz)
{
    if (raiz == NULL)
        return 0;
    else
        return 1 + quantidadeDeNos(raiz->esquerda) + quantidadeDeNos(raiz->direita);
}

int quantidadeDeFolhas(NoArv *raiz)
{
    if (raiz == NULL)
        return 0;
    else if (raiz->esquerda == NULL && raiz->direita == NULL)
        return 1;
    else
        return quantidadeDeFolhas(raiz->esquerda) + quantidadeDeFolhas(raiz->direita);
}

NoArv* remover(int cpf, NoArv *raiz)
{
    if (raiz == NULL)
    {
        printf("valor nao encontrado\n");
        return NULL;
    }
    else
    {
        if (raiz->p.cpf == cpf)
        {
            if (raiz->esquerda == NULL && raiz->direita == NULL)
            {
                free(raiz);
                return NULL;
            }
            else
            {
                if (raiz->esquerda != NULL && raiz->direita != NULL)
                {
                    Pessoa p;
                    NoArv *aux = raiz->esquerda;
                    
                    while (aux->direita)
                    {
                        aux = aux->direita;
                    }
                    p = raiz->p;
                    raiz->p = aux->p;
                    aux->p = p;
                    
                    printf("elemento trocado: %i\n", cpf);
                    raiz->esquerda = remover(cpf, raiz->esquerda);
                    
                    return raiz;
                }
                else
                {
                    NoArv *aux;
                    if (raiz->esquerda != NULL)
                        aux = raiz->esquerda;
                    else
                        aux = raiz->direita;
                    free(raiz);
                    printf("elemento com 1 filho removido: %i", cpf);
                    return aux;
                }
            }
        }
        else
        {
            if (cpf < raiz->p.cpf)
                raiz->esquerda = remover(cpf, raiz->esquerda);
            else
                raiz->direita = remover(cpf, raiz->direita);
            return raiz;
        }
    }
}

void imprimirArvore(NoArv *raiz)
{
    if (raiz)
    {
        imprimirPessoa(raiz->p);
        imprimirArvore(raiz->esquerda);
        imprimirArvore(raiz->direita);
    }
}

void imprimirArvoreOrdenado(NoArv *raiz)
{
    if (raiz)
    {
        imprimirArvoreOrdenado(raiz->esquerda);
        imprimirPessoa(raiz->p);
        imprimirArvoreOrdenado(raiz->direita);
    }
}
