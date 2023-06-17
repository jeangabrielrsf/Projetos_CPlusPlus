# Trabalho Avaliativo 2 - LingProg

O trabalho consiste em um programa de grafos. O programa le dados das arestas e seus respectivos pesos a partir do arquivo grafos.txt para fazer as operações.

## Pré-Requisitos

- Ter o compilador g++ instalado.

## Instalação / Compilação

1. Clonar o repositório para o seu computador
2. Na pasta raíz, compilar o programa utilizando o comando make do Makefile:

```bash
make
```

3. Executar o arquivo executável com o comando:

```bash
./executeGrafo
```

## Como Utilizar

O programa apresenta um menu principal contendo 6 opções numéricas. Digitar o número desejado e apertar enter.
OBS: Algumas opções contém sub-menus para que o usuário escolha alguma opção para imprimir na tela.

Operações possíveis:

1. Imprimir na tela a lista de vértices e o respectivo número de arestas;
2. Imprimir na tela a matriz de adjacências do grafo;
3. Exibir na tela a sequência de arestas atravessadas e o custo total do caminho com o menor custo entre dois vértices escolhidos pelo usuário;
4. Imprimir na tela se o grafo é totalmente conectado ou não com um true ou false;
5. Imprimir na tela o vértice com a maior centralidade de grau.

Ao finalizar o programa, o usuário pode optar por apagar o arquivo executável e os arquivos objeto, a fim de manter apenas os arquivos de código fonte. Basta rodar o seguinte comando na pasta raíz:

```bash
make clean
```

### Autor

Jean Gabriel Frusca
