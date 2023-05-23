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
        void listarMediasMoveisGolsSofridos(int );
        void listarMediasMoveisGolsEfetuados(int );


    private:
        string nomeLiga;
        int codigoLiga;
        vector<Time> times;
        const long unsigned maxTimes = 5;
};

#endif