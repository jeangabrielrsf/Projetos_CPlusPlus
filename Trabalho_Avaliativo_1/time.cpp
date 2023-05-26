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

double Time::getMMGolsEfetuados(int competicao, int min, int N) {
    double soma = 0;
    for (int i = min; i < N; i++) {
        soma = soma + golsEfetuados[competicao][0][i];
    }
    return (soma/N);
}

double Time::getMMGolsSofridos(int competicao, int min, int N) {
    double soma = 0;
    for (int i = min; i < N; i++) {
        soma = soma + golsSofridos[competicao][0][i];
    }

    return (soma/N);
}

void Time::somarGolsSofridos() {
    long int soma;
    for (int i = 0; i < 7; i++) {
        soma = 0;
        for (int j = 0; j < 3; j++) {
            soma = soma + golsSofridos[j][0][i];
        }
        totalGolsSofridos[i] = soma; //total de gols sofridos em um ano;
    } 
};


void Time::somarGolsEfetuados() {
    long int soma;
    for (int i = 0; i < 7; i++) {
        soma = 0;
        for (int j = 0; j < 3; j++) {
            soma = soma + golsEfetuados[j][0][i];
        }
        totalGolsEfetuados[i] = soma; //total de gols efetuados em um ano;
    } 
};


double Time::getMMTotalSofridos(int N) {
    somarGolsSofridos();
    double soma = 0;
    for (int i = 0; i < N; i++) {
        soma = soma + totalGolsSofridos[i];
    }
    return (soma/N);
};

double Time::getMMTotalEfetuados(int N) {
    somarGolsEfetuados();
    double soma = 0;
    for (int i = 0; i < N; i++) {
        soma = soma + totalGolsEfetuados[i];
    }
    return (soma/N);
};





string Time::getNomeTime() {
    return nomeTime;
}