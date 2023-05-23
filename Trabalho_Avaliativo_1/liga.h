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


    private:
        string nomeLiga;
        vector<Time> times;
};

#endif