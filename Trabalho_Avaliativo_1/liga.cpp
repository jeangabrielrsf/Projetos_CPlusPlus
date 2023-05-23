#include "liga.h"

Liga::Liga(string _nomeLiga) {
    nomeLiga = _nomeLiga;
};

void Liga::listarTimes() {
    system("clear");
    for (long int i=0; i < times.size(); i++) {
        cout
            << times.at(i).getNomeTime() << endl;
    }
};

string Liga::getNomeLiga() {
    return nomeLiga;
}