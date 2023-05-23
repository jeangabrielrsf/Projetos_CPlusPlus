#ifndef TIME_H
#define TIME_H

#include <string>

using namespace std;


class Time { //cada instância representa um time de futebol brasileiro
    public:
        Time(string );

        void setGolsSofridos(int competicao, int _golsSofridos, int ano);
        long int getGolsSofridos(int competicao, int ano);

        void setGolsEfetuados(int competicao, int _golsEfetuados, int ano);
        long int getGolsEfetuados(int competicao, int ano);

        double getMMGolsSofridos(int competicao, int N);
        double getMMGolsEfetuados(int competicao, int N);

        string getNomeTime();
        

    private:
        long int golsSofridos[3][1][7], golsEfetuados[3][1][7];
        string nomeTime;

        double MMGolsSofridos, MMGolsEfetuados;

};


#endif