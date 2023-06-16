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

    private:
        vector<Aresta *>arestas;
        fstream file;
        string nomeArquivo;
};

#endif