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

        double getMMGolsSofridos();
        double getMMGolsEfetuados();

        string getNomeTime();
        

    private:
        long int golsSofridos[3][1][8], golsEfetuados[3][1][8];
        double mediaGolsEfetuados, mediaGolsSofridos;
        double computeMMGolsSofridos(int ), computeMMGolsEfetuados(int );
        string nomeTime;

};


#endif