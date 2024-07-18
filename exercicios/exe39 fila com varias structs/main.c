#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int dia, mes, ano;
} Data;

typedef struct 
{
    char rua[50];
    char bairro[50];
    char cidade[50];
    char pais[50];
    int num, cep;
} Endereco;

typedef struct 
{
    int codigo;
    Data dataAss;
    char cargo[50];
    float salario;
} Contrato;

typedef struct 
{
    char nome[50];
    Data dataNas;
    Endereco end;
    Contrato cont;
} Pessoa;

typedef struct no
{
    Pessoa p;
    struct no *proximo;
} No;

void imprimirData(Data d);
void imprimirEndereco(Endereco end);
void imprimirContrato(Contrato cont);
void imprimirPessoa(Pessoa p);
Data lerData();
Endereco lerEndereco();
Contrato lerContrato();
Pessoa lerPessoa();
void enfileirar(Pessoa pessoa, No **fila);
No* desinfilerar(No **fila);
void imprimir(No *fila);

int main(void)
{
    system("cls");

    No *r, *fila = NULL;
    Pessoa p;
    int opcao;

    do
    {
        printf("0 - sair\n1 - enfileirar\n2 - desenfileirar\n3 - imprimir\n");
        scanf("%i", &opcao);
        getchar();

        switch (opcao)
        {
        case 1:
            p = lerPessoa(p);
            system("cls");
            enfileirar(p, &fila);
            break;
        case 2:
            system("cls");
            r = desinfilerar(&fila);
            if (r)
            {
                imprimirPessoa(r->p);
                free(r);
            }
            break;
        case 3:
            system("cls");
            imprimir(fila);
            break;
        default:
            system("cls");
            if (opcao != 0)
                printf("Opcao invalida\n");
            break;
        }
    } while (opcao != 0);

    return 0;
}

void imprimirData(Data d)
{
    printf("%i/%i/%i\n", d.dia, d.mes, d.ano);
}

void imprimirEndereco(Endereco end)
{
    printf("Endereco:\n");
    printf("\tRua: %s", end.rua);
    printf("\tBairro: %s", end.bairro);
    printf("\tCidade: %s", end.cidade);
    printf("\tpais: %s", end.pais);
    printf("\tNumero: %i\n", end.num);
    printf("\tCep: %i\n", end.cep);
}

void imprimirContrato(Contrato c)
{
    printf("Contrato: %i\n", c.codigo);
    printf("\tCargo: %s", c.cargo);
    printf("\tSalario: %.2f\n", c.salario);
    printf("\tData de ad.: ");
    imprimirData(c.dataAss);
}

void imprimirPessoa(Pessoa p)
{
    printf("\nNome: %s", p.nome);
    printf("Data de nas.: ");
    imprimirData(p.dataNas);
    imprimirEndereco(p.end);
    imprimirContrato(p.cont);
}

Data lerData()
{
    Data d;
    
    printf("\nDigite a data no formato dd mm aaaa: ");
    scanf("%i%i%i", &d.dia, &d.mes, &d.ano);
    getchar();

    return d;
}

Endereco lerEndereco()
{
    Endereco end;

    printf("\nRua: ");
    fgets(end.rua, 49, stdin);
    printf("\nBairro: ");
    fgets(end.bairro, 49, stdin);
    printf("\nCidade: ");
    fgets(end.cidade, 49, stdin);
    printf("\nPais: ");
    fgets(end.pais, 49, stdin);
    printf("\nNumero: ");
    scanf("%i", &end.num);
    printf("\nCep: ");
    scanf("%i", &end.cep);
    getchar();

    return end;
}

Contrato lerContrato()
{
    Contrato c;

    printf("\nCodigo do contrato: ");
    scanf("%i", &c.codigo);
    printf("\nData de assinatura;");
    c.dataAss = lerData();
    printf("\nCargo: ");
    fgets(c.cargo, 49, stdin);
    printf("\nSalario: R$");
    scanf("%f", &c.salario);
    getchar();

    return c;
}

Pessoa lerPessoa()
{
    Pessoa p;

    printf("\nNome: ");
    fgets(p.nome, 49, stdin);
    printf("\nData de nascimento;");
    p.dataNas = lerData();
    p.cont = lerContrato();
    p.end = lerEndereco();

    return p;
}

void enfileirar(Pessoa pessoa, No **fila)
{
    No *aux, *novo = malloc(sizeof(No));
    if (novo == NULL)
    {
        printf("erro ao alocar memoria\n");
        return;
    }

    novo->p = pessoa;
    novo->proximo = NULL;
    if (*fila == NULL)
        *fila = novo;
    else
    {
        aux = *fila;
        while (aux->proximo)
            aux = aux->proximo;
        aux->proximo = novo;
    }
}

No* desinfilerar(No **fila)
{
    No *remover = NULL;

    if (*fila)
    {
        remover = *fila;
        *fila = remover->proximo;
    }
    else
        printf("Fila vazia\n");
    return remover;
}

void imprimir(No *fila)
{
    printf("------------ FILA ------------\n");
    
    while (fila)
    {
        imprimirPessoa(fila->p);
        fila = fila->proximo;
        if (fila)
            printf("--------------------------");
    }

    printf("\n------------ FIM FILA ------------\n");
}