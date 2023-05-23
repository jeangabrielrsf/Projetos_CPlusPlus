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

double Time::getMMGolsEfetuados(int competicao, int N) {
    double soma = 0;
    for (int i = 0; i < N; i++) {
        soma = soma + golsEfetuados[competicao][0][i];
    }
    return (soma/N);
}

double Time::getMMGolsSofridos(int competicao, int N) {
    double soma = 0;
    for (int i = 0; i < N; i++) {
        soma = soma + golsSofridos[competicao][0][i];
    }

    return (soma/N);
}


string Time::getNomeTime() {
    return nomeTime;
}