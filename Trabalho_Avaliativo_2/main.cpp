#include <iostream>
#include <iomanip>
#include "vertice.h"
#include "aresta.h"
#include "grafo.h"

using namespace std;

int main() {

    int escolhaMenu = 0;
    Grafo g;
    g.lerArquivo();


    while (escolhaMenu != 6) {
        cout << setw(30) << "==============================" << endl;
        cout << setw(30) << left << "Menu Principal" << endl;
        cout << "Escolha uma opção:" << endl;
        cout << "1 - Imprimir lista de vértices e o respectivo número de arestas." << endl;
        cout << "2 - Imprimir matriz de adjacências do grafo" << endl;
        cout << "3 - Exibir sequência de arestas atravessadas e o custo total do caminho com menor custo entre dois vértices escolhidos" << endl;
        cout << "4 - Exibir se grafo é totalmente conectado" << endl;
        cout << "5 - Imprimir vértice com maior centralidade de grau" << endl;
        cout << "6 - Sair do programa" << endl;
        cout << setw(30) << "==============================" << endl;
        cin >> escolhaMenu;


        switch (escolhaMenu) {
            case 1:
                g.imprimirCaminho();
            break;

            case 2:
                g.gerarMatriz();
                g.imprimirMatriz();
            break;

            case 3:
                cout << "em desenvolvimento" << endl;                
            break;

            case 4:
                cout << "em desenvolvimento" << endl;
            break;

            case 5:
                cout << "em desenvolvimento" << endl;
            break;

            case 6:
                cout << "Saindo..." << endl;
            break;

            default:
                cout << "escolhe certo, rapaz" << endl;
            break;
        }
    }

    return 0;
}