#include "aresta.h"

Aresta::Aresta(Vertice *v1, Vertice *v2, double peso) {
    origem = v1;
    destino = v2;
    this->peso = peso;
};

Vertice *Aresta::getVerticeOrigem() {
    return origem;
}

Vertice *Aresta::getVerticeDestino() {
    return destino;
}

double Aresta::getPeso() {
    return peso;
}