#include <iostream>
#include "grafo.h"



double Grafo::custoCaminho() {
    double soma = 0;

    for (unsigned i = 0; i < arestas.size(); i++) {
        soma += arestas.at(i)->getPeso();
    }

    return soma;
}


vector<string> Grafo::contaVertices() {
    vector<string> vertices;
    vector<int> qtdArestas;
    bool contains;

    //analisando vertices de origem
    for (unsigned i=0; i < arestas.size(); i++) {
        if(vertices.size() == 0) { //vazio 
            vertices.push_back(arestas.at(i)->getVerticeOrigem()->getRotulo());
        } else {
            contains = false;
            for (unsigned j = 0; j < vertices.size(); j++) {
                if (vertices.at(j) == arestas.at(i)->getVerticeOrigem()->getRotulo()) {
                    contains = true;
                }
            }
            if (!contains) {
                vertices.push_back(arestas.at(i)->getVerticeOrigem()->getRotulo());
            }
        }
    }

    //analisando vertices de destino
    for (unsigned i=0; i < arestas.size(); i++) {
        if(vertices.size() == 0) { //vazio 
            vertices.push_back(arestas.at(i)->getVerticeDestino()->getRotulo());
        } else {
            contains = false;
            for (unsigned j = 0; j < vertices.size(); j++) {
                if (vertices.at(j) == arestas.at(i)->getVerticeDestino()->getRotulo()) {
                    contains = true;
                }
            }
            if (!contains) {
                vertices.push_back(arestas.at(i)->getVerticeDestino()->getRotulo());
            }
        }
    }

    return vertices;
}

vector<int> Grafo::contaArestas() {
    vector<string> vertices = contaVertices();
    vector<int>qtdArestas;
    int soma;
    for(unsigned i = 0; i < vertices.size(); i++) {
        soma = 0;
        for (unsigned j = 0; j < arestas.size(); j++) {
            if(arestas.at(j)->getVerticeOrigem()->getRotulo() == vertices.at(i)) {
                soma += 1;
            }
            if(arestas.at(j)->getVerticeDestino()->getRotulo() == vertices.at(i)) {
                soma += 1;
            }
        }
        qtdArestas.push_back(soma);
    }
    return qtdArestas;
}


void Grafo::imprimirCaminho() {
    vector<string> vertices = contaVertices();
    vector<int> qtdArestas = contaArestas();


    cout << "Lista de Vértices: (";
    for (unsigned i = 0; i < vertices.size(); i++) {
        cout 
            << vertices.at(i) <<": "
            << qtdArestas.at(i) << " ";
    }
    cout << ")" << endl;
    
}


void Grafo::inserirAresta(Aresta *aresta) {
    if (arestas.size() == 0) {
        arestas.push_back(aresta);
    } else {
        if (aresta->getVerticeOrigem()->getRotulo() == aresta->getVerticeDestino()->getRotulo()) {
            cout 
                << "impossível inserir aresta (" 
                << aresta->getVerticeOrigem()->getRotulo()
                << "," << aresta->getVerticeDestino()->getRotulo()
                <<")"
            <<endl;
        } else {
            arestas.push_back(aresta);
        }
    }

}

void Grafo::lerArquivo() {
    double peso;
    string rotuloV1, rotuloV2;
    
    file.open(nomeArquivo, fstream::in);
    if(!file.is_open()) {
        cout << "arquivo inexistente!" << endl;
        return;
    }

    while (file.good()) {
        file >> rotuloV1 >> rotuloV2 >> peso;
        if (rotuloV1 == "" || rotuloV2 == "") continue;
        Vertice* v1 = new Vertice(rotuloV1);
        Vertice* v2 = new Vertice(rotuloV2);
        Aresta* a = new Aresta(v1, v2, peso);
        inserirAresta(a);
    }
    file.close();
}

void Grafo::salvarArquivo() {
    file.open(nomeArquivo, fstream::out);
    for (unsigned i = 0; i < arestas.size(); i++) {
        file
            << arestas.at(i)->getVerticeOrigem()->getRotulo() << " "
            << arestas.at(i)->getVerticeDestino()->getRotulo() << " "
            << arestas.at(i)->getPeso()
        << endl;
    }
    file.close();
    cout << "Arquivo salvo!" << endl;
}


int Grafo::getArestasSize() {
    return arestas.size();
}