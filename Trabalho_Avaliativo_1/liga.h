#ifndef LIGA_H
#define LIGA_H

#include <iostream>
#include <string>
#include <vector>
#include "time.h"

using namespace std;

class Liga {
    public :
        Liga(string nomeLiga, int codigoLiga);
        void listarTimes();
        string getNomeLiga();
        void inserirTime(Time );

        void listarMediasMoveis(int );
        void exibirMaiorSaldo();
        void listarDesempenho();
        Time maiorEvolucao();


    private:
        string nomeLiga;
        int codigoLiga;

        vector<Time> times;
        
        const static long unsigned maxTimes = 5;

        double desempenhoGolsEfetuados[maxTimes];
        double desempenhoGolsSofridos[maxTimes];

        void computarDesempenho();
};

#endif