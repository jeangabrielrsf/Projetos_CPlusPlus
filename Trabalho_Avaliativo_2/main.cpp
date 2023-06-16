#include <iostream>
#include "vertice.h"
#include "aresta.h"
#include "grafo.h"

using namespace std;

int main() {

    Vertice v1("A");
    Vertice v2("B");
    Vertice v3("C");
    Vertice v4("D");
    Vertice v5("E");

    Aresta a1(&v1, &v2, 1.0);
    Aresta a2(&v2, &v3, 1.0);
    Aresta a3(&v3, &v4, 1.0);
    Aresta a4(&v1, &v5, 1.0);    

    Grafo g;



    g.inserirAresta(&a1);
    g.inserirAresta(&a2);
    g.inserirAresta(&a3);
    g.inserirAresta(&a4);

    g.imprimirCaminho();




    return 0;
}