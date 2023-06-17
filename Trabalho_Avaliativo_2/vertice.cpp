#include "vertice.h"

Vertice::Vertice(string rotuloVertice) {
    this->rotulo = rotuloVertice;
}

string Vertice::getRotulo(){
    return rotulo;
}

void Vertice::setRotulo(string rotuloVertice) {
    rotulo = rotuloVertice;
}
