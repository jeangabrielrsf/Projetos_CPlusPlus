#ifndef ARESTA_H
#define ARESTA_H

#include "vertice.h"

using namespace std;

class Aresta {
    public:
        Aresta(Vertice *v1, Vertice *v2, double peso);
        Vertice *getVerticeOrigem();
        Vertice *getVerticeDestino();
        double getPeso();

    private:
        Vertice *origem, *destino;
        double peso;

};


#endif