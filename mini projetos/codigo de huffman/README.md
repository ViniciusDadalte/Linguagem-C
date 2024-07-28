# Algoritmo de Huffman em C

Este projeto implementa o algoritmo de compressão de Huffman em linguagem C. O algoritmo de Huffman é um método de compressão de dados sem perdas que utiliza uma árvore binária para representar os caracteres de um texto com base em suas frequências.

## Estrutura do Projeto

- `main.c`: Contém a implementação do algoritmo de Huffman.
- `teste.txt`: Arquivo de texto de entrada para ser comprimido e descomprimido.

## Funcionalidades

1. **Tabela de Frequência**: Calcula a frequência de cada caractere no texto.
2. **Lista Encadeada Ordenada**: Armazena os nós da árvore de Huffman de forma ordenada por frequência.
3. **Árvore de Huffman**: Constrói a árvore de Huffman a partir da lista encadeada.
4. **Dicionário de Huffman**: Gera um dicionário que mapeia cada caractere para seu código binário correspondente.
5. **Codificação**: Codifica o texto original utilizando o dicionário de Huffman.
6. **Decodificação**: Decodifica o texto codificado de volta ao texto original.
7. **Compactação**: Compacta o texto codificado em um arquivo binário.
8. **Descompactação**: Descompacta o arquivo binário de volta ao texto original.

## Como Compilar e Executar

### Compilar

Use um compilador de C, como o `gcc`, para compilar o código:

```sh
gcc -o huffman main.c
```

### Executar

Depois de compilar, execute o programa:

```sh
./huffman
```

Certifique-se de que o arquivo `teste.txt` esteja no mesmo diretório que o executável, pois ele será lido pelo programa.

## Funções Principais

- **Tabela de Frequência**
  - `void iniciaTabelaComZero(unsigned int tab[]);`
  - `void preencheTabFrequencia(unsigned char texto[], unsigned int tab[]);`
  - `void imprimeTabFrequencia(unsigned int tab[]);`

- **Lista Encadeada Ordenada**
  - `void criarLista(Lista *l);`
  - `void inserirOrdenado(Lista *l, No *n);`
  - `void preencherLista(unsigned int tab[], Lista *l);`
  - `void imprimeLista(Lista *l);`

- **Árvore de Huffman**
  - `No* removeNoInico(Lista *l);`
  - `No* montarArvore(Lista *l);`
  - `void imprimeArvore(No *raiz, int tam);`

- **Dicionário de Huffman**
  - `int alturaArvore(No *raiz);`
  - `char** alocaDicionario(int colunas);`
  - `void gerarDicionario(char **dicionario, No *raiz, char *caminho, int colunas);`
  - `void imprimeDicionario(char **dicionario);`

- **Codificação e Decodificação**
  - `int calculaTamanhoString(char **dicionario, unsigned char *texto);`
  - `char* codificar(char **dicionario, unsigned char *texto);`
  - `char* decodificar(unsigned char *texto, No *raiz);`

- **Compactação e Descompactação**
  - `void compactar(unsigned char str[]);`
  - `unsigned int ehBitUm(unsigned char byte, int i);`
  - `void descompactar(No *raiz);`
  - `int descobrirTamanho();`
  - `void lerTexto(unsigned char *texto);`

- **Liberação de Memória**
  - `void liberarDicionario(char **dicionario, int linhas);`
  - `void liberarArvore(No *raiz);`

## Considerações

Este código foi desenvolvido para fins educacionais e pode ser melhorado para maior eficiência e robustez. Sinta-se à vontade para contribuir com melhorias ou sugestões.

## Licença

Este projeto é licenciado sob a licença MIT. Veja o arquivo [LICENSE](LICENSE) para mais detalhes.
