#include <iostream>
#include <iomanip>
#include "liga.h"

Liga::Liga(string _nomeLiga, int _codigoLiga) {
    nomeLiga = _nomeLiga;
    codigoLiga = _codigoLiga;
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
        // cout 
        //     << "\nTime "
        //     << novoTime.getNomeTime()
        //     << " adicionado com sucesso "
        //     << "em " << nomeLiga
        // << endl;
    }
    
};



void Liga::listarMediasMoveis(int N) {

    cout 
        << "\n"
        << nomeLiga
        <<  setw(25) << "\n#########################"    
    << endl;

    for (long unsigned int i = 0; i < times.size(); i++) {
        cout
            << "\nMédia Movel do "
            << times.at(i).getNomeTime()
            << ":"
        << endl;

        cout 
            << "Gols efetuados: "
            << setprecision(2) << fixed
            << times.at(i).getMMGolsEfetuados(codigoLiga ,N)
        << endl;

        cout
            << "Gols sofridos: "
            << times.at(i).getMMGolsSofridos(codigoLiga, N)
        << endl;
    }
    cout    
        << setw(25) << "\n#########################"
    <<endl;
}

void Liga::listarDesempenho() {
    system("clear");
    
}