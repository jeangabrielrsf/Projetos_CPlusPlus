#ifndef LIGA_H
#define LIGA_H

#include <iostream>
#include <string>
#include <vector>
#include "time.h"

using namespace std;

class Liga {
    public :
        Liga(string nomeLiga);
        void listarTimes();
        string getNomeLiga();
        void inserirTime(Time );


    private:
        string nomeLiga;
        vector<Time> times;
        const long unsigned maxTimes = 5;
};

#endif