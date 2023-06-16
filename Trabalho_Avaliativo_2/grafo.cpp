#include <iostream>
#include "grafo.h"

Grafo::Grafo() {
    nomeArquivo = "grafo.txt";

    lerArquivo();
}


double Grafo::custoCaminho() {
    double soma = 0;

    for (unsigned i = 0; i < arestas.size(); i++) {
        soma += arestas.at(i)->getPeso();
    }

    return soma;
}

void Grafo::imprimirCaminho() {
    cout << "Caminho: ";
    for (unsigned i=0; i < arestas.size(); i++) {
        cout << arestas.at(i)->getVerticeOrigem()->getRotulo() << " -> ";
    }
    cout << arestas.at(arestas.size()-1)->getVerticeDestino()->getRotulo() << endl;
    cout << "Custo: " << custoCaminho() << endl;
}


void Grafo::inserirAresta(Aresta *aresta) {
    arestas.push_back(aresta);
}

void Grafo::lerArquivo() {
    Aresta *a;
    Vertice *v1, *v2;
    double peso;
    string data;
    
    file.open(nomeArquivo, fstream::in);
    if(!file.is_open()) {
        cout << "Erro ao abrir arquivo!" << endl;
        return;
    }

    while (file.good()) {
        file >> data;
        cout
            << "conteúdo do arquivo:\n"
            << data
        << endl;
    }


    file.close();
}
