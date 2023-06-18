#include <iostream>
#include <iomanip>
#include "vertice.h"
#include "aresta.h"
#include "grafo.h"

using namespace std;

int main() {

    int escolhaMenu = 0;
    Vertice* origem = nullptr;
    Vertice* destino = nullptr;
    string rotuloOrigem;
    string rotuloDestino;
    Grafo g;
    g.lerArquivo();
    g.getPesoArestas();



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
                g.imprimirListaVertices();
            break;

            case 2:
                g.gerarMatriz();
                g.imprimirMatriz();
            break;

            case 3:
                system("clear");
                cout << "Digite o rótulo do vértice de origem:" << endl;
                cin >> rotuloOrigem;
                cout << "Digite o rótulo do vértice de destino:" << endl;
                cin >> rotuloDestino;

                origem = g.getVerticePorRotulo(rotuloOrigem);
                cout << origem->getRotulo();
                destino = g.getVerticePorRotulo(rotuloDestino);
                cout << destino->getRotulo();

                if (origem == nullptr || destino == nullptr) {
                    cout << "Vértice não encontrado!" << endl;
                    continue;
                } else {
                    vector<Aresta *>caminho = g.caminhoMenorCusto(origem, destino);
                    g.imprimirCaminhoMenorCusto(caminho);
                }

            break;

            case 4:
                cout << "em desenvolvimento" << endl;
                cout << (g.ehConectado() ? "O grafo é totalmente conectado!" : "O grafo não é totalmente conectado") << endl;
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