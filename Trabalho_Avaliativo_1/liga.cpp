#include <iostream>
#include "liga.h"

Liga::Liga(string _nomeLiga) {
    nomeLiga = _nomeLiga;
};

void Liga::listarTimes() {
    cout 
        <<  "\nTimes presentes em "
        << nomeLiga << ": "
    << endl;
    for (long unsigned int i=0; i < times.size(); i++) {
        cout
            << times.at(i).getNomeTime() << endl;
    }
};

string Liga::getNomeLiga() {
    return nomeLiga;
};

void Liga::inserirTime(Time novoTime) {
    if (times.size() >= maxTimes) {
        cout 
            << "\nImpossível adicionar mais que 5 times!"
        << endl;
    } else {
        times.push_back(novoTime);
        cout 
            << "\nTime "
            << novoTime.getNomeTime()
            << " adicionado com sucesso "
            << "em " << nomeLiga
        << endl;
    }
    
};