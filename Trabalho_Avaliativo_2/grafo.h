#ifndef GRAFO_H
#define GRAFO_H

#include <vector>
#include <fstream>
#include <string>
#include "aresta.h"

using namespace std;

class Grafo {
    public:
        void inserirAresta(Aresta *);
        void imprimirCaminho();
        double custoCaminho();

        void gerarMatriz();
        void imprimirMatriz();

        int getIndiceVertice(Vertice *v);
        void lerArquivo();
        void salvarArquivo();

        vector<string> contaVertices();
        vector<int> contaArestas();

        int getArestasSize();

    private:
        vector<Aresta *>arestas;
        fstream file;
        const string nomeArquivo = "grafos.txt";
        vector<vector<double>> matrizAdj;
};

#endif