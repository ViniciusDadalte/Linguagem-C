#include <stdio.h>
#include <stdlib.h>

#define TAM 15

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
    int cpf;
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
void iniciaTabela(Pessoa t[]);
int funcaoHash(int chave);
void inserir(Pessoa t[]);
Pessoa* busca(int chave, Pessoa t[]);
void imprimirTabela(Pessoa t[]);

int main(void)
{
    system("cls");

    int opcao, dado;
    Pessoa *buscando, tabela[TAM];
    iniciaTabela(tabela);

    do
    {
        printf("\n0 - sair\n1 - inserir\n2 - buscar\n3 - imprimir\n");
        scanf("%i", &opcao);
        getchar();

        switch (opcao)
        {
        case 1:
            inserir(tabela);
            system("cls");
            break;
        case 2:
            printf("Digite o cpf para buscar: ");
            scanf("%i", &dado);
            system("cls");
            buscando = busca(dado, tabela);
            if (buscando != NULL)
            {
                printf("\nCpf encontrado\n");
                imprimirPessoa(*buscando);
            }
            else
                printf("Cpf nao encontrado\n");
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
    printf("cpf: %i\n", p.cpf);
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
    printf("\nCpf: ");
    scanf("%i", &p.cpf);
    printf("\nData de nascimento;");
    p.dataNas = lerData();
    p.cont = lerContrato();
    p.end = lerEndereco();

    return p;
}

void iniciaTabela(Pessoa t[])
{
    for (int i = 0; i < TAM; i++)
        t[i].cpf = 0;
}

int funcaoHash(int chave)
{
    return chave % TAM;
}

void inserir(Pessoa t[])
{
    Pessoa p = lerPessoa(); 
    int id = funcaoHash(p.cpf);

    while (t[id].cpf != 0)
        id = funcaoHash(id + 1);
    t[id] = p;
}

Pessoa* busca(int chave, Pessoa t[])
{
    Pessoa p;
    p.cpf = 0;
    
    int id = funcaoHash(chave);
    
    printf("indice gerado: %i\n", id);

    while (t[id].cpf != 0)
    {
        if (t[id].cpf == chave)
            return &t[id];
        else
            id = funcaoHash(id + 1);
    }
    return NULL;
}

void imprimirTabela(Pessoa t[])
{
    for (int i = 0; i < TAM; i++)
    {
        printf("%i\n", i);
        if (t[i].cpf != 0)
            imprimirPessoa(t[i]);
        printf("\n----------------------\n");
    }
}

