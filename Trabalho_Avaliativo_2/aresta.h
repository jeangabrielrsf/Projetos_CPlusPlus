#ifndef ARESTA_H
#define ARESTA_H

#include "vertice.h"

using namespace std;

class Aresta {
    public:
        Aresta(Vertice *v1, Vertice *v2, double peso);
        Vertice *getVertice1();
        Vertice *getVertice2();
        double getPeso();

    private:
        Vertice *vertice1, *vertice2;
        double peso;

};


#endif