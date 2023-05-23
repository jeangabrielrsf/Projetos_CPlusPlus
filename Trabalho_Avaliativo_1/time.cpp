#include "time.h"

Time::Time(string nome) {
    nomeTime = nome;
};

void Time::setGolsSofridos(int competicao, int _golsSofridos, int ano) {
    golsSofridos[competicao][0][ano] = _golsSofridos;
};

void Time::setGolsEfetuados(int competicao, int _golsEfetuados, int ano) {
    golsEfetuados[competicao][0][ano] = _golsEfetuados;
};

long int Time::getGolsEfetuados(int competicao, int ano) {
    return golsEfetuados[competicao][0][ano];
};

long int Time::getGolsSofridos(int competicao, int ano) {
    return golsSofridos[competicao][0][ano];
};

double Time::getMMGolsEfetuados() {
    return mediaGolsEfetuados;
};

double Time::getMMGolsSofridos() {
    return mediaGolsSofridos;
};

double Time::computeMMGolsEfetuados(int N) { // N = numero de anos para calcular a média

};

string Time::getNomeTime() {
    return nomeTime;
}