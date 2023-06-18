#include <iostream>
#include <iomanip>
#include <limits>
#include <algorithm>
#include <unordered_map>
#include "grafo.h"



double Grafo::custoCaminho() {
    double soma = 0;

    for (unsigned i = 0; i < arestas.size(); i++) {
        soma += arestas.at(i)->getPeso();
    }

    return soma;
}


void Grafo::ordenarVertices(vector<Vertice> vertices) {
    for (unsigned i = 0; i < vertices.size()-1; i++) {
        for (unsigned j = i+1; j < vertices.size(); j++) {
            if (vertices.at(i).getRotulo() > vertices.at(j).getRotulo()) {
                Vertice aux = vertices.at(i);
                vertices.at(i) = vertices.at(j);
                vertices.at(j) = aux;
            }   
        }
    }
}

vector<Vertice> Grafo::contaVerticesObj() {
    vector<Vertice> vertices;
    vector<int> qtdArestas;
    bool contains;

    //analisando vertices de origem
    for (unsigned i=0; i < arestas.size(); i++) {
        if(vertices.size() == 0) { //vazio 
            vertices.push_back(*arestas.at(i)->getVerticeOrigem());
        } else {
            contains = false;
            for (unsigned j = 0; j < vertices.size(); j++) {
                if (vertices.at(j).getRotulo() == arestas.at(i)->getVerticeOrigem()->getRotulo()) {
                    contains = true;
                }
            }
            if (!contains) {
                vertices.push_back(*arestas.at(i)->getVerticeOrigem());
            }
        }
    }

    //analisando vertices de destino
    for (unsigned i=0; i < arestas.size(); i++) {
        if(vertices.size() == 0) { //vazio 
            vertices.push_back(*arestas.at(i)->getVerticeDestino());
        } else {
            contains = false;
            for (unsigned j = 0; j < vertices.size(); j++) {
                if (vertices.at(j).getRotulo() == arestas.at(i)->getVerticeDestino()->getRotulo()) {
                    contains = true;
                }
            }
            if (!contains) {
                vertices.push_back(*arestas.at(i)->getVerticeDestino());
            }
        }
    }
    return vertices;
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
    vector<Vertice> vertices = contaVerticesObj();
    vector<int>qtdArestas;
    int soma;
    for(unsigned i = 0; i < vertices.size(); i++) {
        soma = 0;
        for (unsigned j = 0; j < arestas.size(); j++) {
            if(arestas.at(j)->getVerticeOrigem()->getRotulo() == vertices.at(i).getRotulo()) {
                soma += 1;
            }
            if(arestas.at(j)->getVerticeDestino()->getRotulo() == vertices.at(i).getRotulo()) {
                soma += 1;
            }
        }
        qtdArestas.push_back(soma);
    }
    return qtdArestas;
}


void Grafo::imprimirListaVertices() {
    vector<Vertice> vertices = contaVerticesObj();
    vector<int> qtdArestas = contaArestas();


    cout << "Lista de Vértices: (";
    for (unsigned i = 0; i < vertices.size(); i++) {
        cout 
            << vertices.at(i).getRotulo() <<": "
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


void Grafo::gerarMatriz() {
    vector<string> vertices = contaVertices();
    matrizAdj = vector<vector<double>> (vertices.size(), vector<double>(vertices.size(), 0.0));

    for (unsigned i = 0; i < arestas.size(); i++) {
        unsigned indiceOrigem = getIndiceVertice(arestas.at(i)->getVerticeOrigem());
        unsigned indiceDestino = getIndiceVertice(arestas.at(i)->getVerticeDestino());
        matrizAdj[indiceOrigem][indiceDestino] = arestas.at(i)->getPeso();
        matrizAdj[indiceDestino][indiceOrigem] = arestas.at(i)->getPeso();
    }
}


void Grafo::imprimirMatriz() {
    const unsigned tamanho = contaVertices().size();
    cout << "Matriz de adjacências:" << endl;
    for (unsigned int i = 0; i < tamanho; i++) {
        for (unsigned int j = 0; j < tamanho; j++) {
            cout
                << setprecision(1)
                << fixed 
                << setw(3)
                << matrizAdj[i][j] 
                << " ";
        }
        cout << endl;
    }
}

int Grafo::getIndiceVertice(Vertice *v) {
    vector<string> vertices = contaVertices();
    for (unsigned i = 0; i < vertices.size(); i++) {
        if(vertices.at(i) == v->getRotulo()) {
            return i;
        }
    }
    return -1;
}




vector<Aresta *> Grafo::caminhoMenorCusto(Vertice *origem, Vertice *destino) {
    vector<Vertice> vertices = contaVerticesObj();
    //mapear vértices para seus índices na matriz de adjacências
    vector<int> indiceVertices(vertices.size(), -1);
    for (unsigned i = 0; i < vertices.size(); i++) {
        indiceVertices.at(i) = i;
    }

    //vetor de distancias
    vector<double> distancias(vertices.size(), numeric_limits<double>::infinity());

    //vetor de anteriores
    vector<int> anteriores(vertices.size(), -1);

    //vertices visitados
    vector<bool> visitados(vertices.size(), false);

    int indiceOrigemVertice = getIndiceVertice(origem);
    int indiceDestinoVertice = getIndiceVertice(destino);
    if (indiceOrigemVertice == -1 || indiceDestinoVertice == -1) {
        cout << "Vértice de origem ou destino inexistente!" << endl;
        return vector<Aresta *>();
    }

    distancias.at(indiceOrigemVertice) = 0;
    //Dijkstra
    while (true) {
        int indiceMenorDistancia = -1;
        double menorDistancia = numeric_limits<double>::infinity();
        for (unsigned i = 0; i < vertices.size(); i++) {
            if (!visitados.at(i) && distancias.at(i) < menorDistancia) {
                menorDistancia = distancias.at(i);
                indiceMenorDistancia = i;
            }
        }

        if (indiceMenorDistancia == -1) {
            break; //todos os vértices visitados
        }

        visitados.at(indiceMenorDistancia) = true;
        
        // Relaxar as arestas adjacentes ao vértice atual
        for (unsigned i = 0; i < vertices.size(); i++) {
            if (matrizAdj[indiceMenorDistancia][i] != numeric_limits<double>::infinity()) {
                double pesoAresta = matrizAdj[indiceMenorDistancia][i];
                double novaDistancia = distancias.at(indiceMenorDistancia) + pesoAresta;
                
                if (novaDistancia < distancias.at(i)) {
                    distancias.at(i) = novaDistancia;
                    anteriores.at(i) = indiceMenorDistancia;
                }
            }
        }
    }

    // Reconstruir o caminho de menor custo
    vector<Aresta*> caminho;
    int indiceDestino = getIndiceVertice(destino);
    int indiceAtual = indiceDestino;
    while (anteriores.at(indiceAtual) != -1) {
        int indiceAnterior = anteriores.at(indiceAtual);
        Aresta *aresta = new Aresta(&vertices.at(indiceAnterior), &vertices.at(indiceAtual), matrizAdj[indiceAnterior][indiceAtual]);
        caminho.push_back(aresta);
        indiceAtual = indiceAnterior;
    }
    
    reverse(caminho.begin(), caminho.end()); // Inverter o caminho para ficar na ordem correta
    
    return caminho;
}

void Grafo::imprimirCaminhoMenorCusto(vector<Aresta *> &caminho) {
    if (caminho.size() == 0){
        cout << "Não tem caminho!" << endl;
        return;
    }

    cout << "Caminho de menor custo: " << endl;
    for (unsigned i = 0; i < caminho.size(); i++) {
        Aresta* aresta = caminho.at(i);
        cout << aresta->getVerticeOrigem()->getRotulo() << " -> ";
    }
    cout << caminho.back()->getVerticeDestino()->getRotulo() << endl;
}

Vertice* Grafo::getVerticePorRotulo(string &rotulo) {
    vector<Vertice> vertices = contaVerticesObj();
    for (unsigned i = 0; i < vertices.size(); i++) {
        if (vertices.at(i).getRotulo() == rotulo) {
            return &vertices.at(i);
        }
    }
    return nullptr; // Retorna nullptr se o vértice não for encontrado
}


// void Grafo::imprimirVerticeMaiorCentralidade() {
//     double maiorCentralidade = 0;
//     Vertice* verticeMaiorCentralidade = nullptr;

//     vector<Vertice> vertices = contaVerticesObj();

//     for (unsigned i = 0; i < arestas.size(); i++) {
//         Vertice* origem = arestas.at(i)->getVerticeOrigem();
//         Vertice* destino = arestas.at(i)->getVerticeDestino();

//         int centralidadeOrigem = contaArestas().at(getIndiceVertice(origem));
//         if (centralidadeOrigem > maiorCentralidade) {
//             maiorCentralidade = centralidadeOrigem;
//             verticeMaiorCentralidade = origem;
//         }

//         int centralidadeDestino = contaArestas().at(getIndiceVertice(destino));
//         if (centralidadeDestino > maiorCentralidade) {
//             maiorCentralidade = centralidadeDestino;
//             verticeMaiorCentralidade = destino;
//         }

//     }
// }

void Grafo::getPesoArestas() {
    for (unsigned i = 0; i < arestas.size(); i++) {
        pesoArestas.push_back(arestas.at(i)->getPeso());
    }
}