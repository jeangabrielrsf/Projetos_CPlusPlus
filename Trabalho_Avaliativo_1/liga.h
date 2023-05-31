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
        long unsigned maiorEvolucaoGolsEfetuados();
        long unsigned maiorEvolucaoGolsSofridos();

        double DesempenhoGolsEfetuadosTime(long unsigned indice);
        double DesempenhoGolsSofridosTime(long unsigned indice);

        Time buscarTimePorIndice(long unsigned indice);
        long unsigned buscarTimePorNome(string nome);
        void computarDesempenho();

    private:
        string nomeLiga;
        int codigoLiga;

        vector<Time> times;
        
        const static long unsigned maxTimes = 5;

        double desempenhoGolsEfetuados[maxTimes];
        double desempenhoGolsSofridos[maxTimes];


};

#endif