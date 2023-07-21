# Trabalho Final - Linguagens de Programação

Este trabalho consiste em aplicar o conceito de Foreign Function Interface (FFI) usando C++ e Python. A ideia aqui é ter um programa gerenciador escrito em C++ que faz chamadas para funções Python, com o objetivo de manipular um arquivo .CSV usando a biblioteca pandas.

## Pré-Requisitos

- Ter o compilador g++ instalado.
- Ter o Python 3 instalado.

## Instalação / Compilação

1. Clonar o repositório para o seu computador
2. Na pasta raíz, compilar o programa utilizando o comando make do Makefile:

```bash
make
```

3. Executar o arquivo executável com o comando:

```bash
./executeGerenciador
```

## Como Utilizar

O programa consegue ler dados de um arquivo .csv localizado na pasta raíz do projeto. Para alterar o arquivo a ser lido, basta modificar o valor da macro NOME_ARQUIVO presente no arquivo runApp.cpp

O programa apresenta um menu principal contendo 5 opções numéricas. Digitar o número desejado e apertar enter.
OBS: Algumas opções contém sub-menus onde ocorrem interações com o usuário.

Operações possíveis:

1. Ler dados de um arquivo CSV;
2. Inserir dados em um arquivo CSV;
3. Remover dados de um arquivo CSV;
4. Procurar dados em um arquivo CSV;
5. Sair do programa

Ao finalizar o programa, o usuário pode optar por apagar o arquivo executável e os arquivos objeto, a fim de manter apenas os arquivos de código fonte. Basta rodar o seguinte comando na pasta raíz:

```bash
make clean
```

### Autor

Jean Gabriel Frusca
