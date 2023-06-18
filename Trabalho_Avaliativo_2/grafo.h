#ifndef GRAFO_H
#define GRAFO_H

#include <vector>
#include <fstream>
#include <unordered_map>
#include <string>
#include "aresta.h"

using namespace std;

class Grafo {
    public:
        void inserirAresta(Aresta *);
        void imprimirListaVertices();
        void imprimirCaminhoMenorCusto(vector<Aresta *> &);
        vector<Aresta *>caminhoMenorCusto(Vertice *origem, Vertice *destino); 
        double custoCaminho();

        void gerarMatriz();
        void imprimirMatriz();

        int getIndiceVertice(Vertice *v);
        Vertice *getVerticePorRotulo(string &rotulo);
        void lerArquivo();
        void salvarArquivo();
        void ordenarVertices(vector<Vertice> vertices);
        void getPesoArestas();

        vector<string> contaVertices();
        vector<Vertice> contaVerticesObj();
        vector<int> contaArestas();

        int getArestasSize();
        void imprimirVerticeMaiorCentralidade();

    private:
        vector<Aresta *>arestas;
        vector<double> pesoArestas;
        fstream file;
        const string nomeArquivo = "grafos.txt";
        vector<vector<double>> matrizAdj;
};

#endif