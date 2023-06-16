#ifndef GRAFO_H
#define GRAFO_H

#include <vector>
#include <fstream>
#include <string>
#include "aresta.h"

using namespace std;

class Grafo {
    public:
        Grafo();
        void inserirAresta(Aresta *);
        void imprimirCaminho();
        double custoCaminho();

        void lerArquivo();
        void salvarArquivo();

    private:
        vector<Aresta *>arestas;
        fstream file;
        string nomeArquivo;
};

#endif