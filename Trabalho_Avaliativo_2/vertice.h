#ifndef VERTICE_H
#define VERTICE_H

#include <string>


using namespace std;

class Vertice {
    public:
        Vertice(string rotuloVertice);
        string getRotulo();
        void setRotulo(string rotuloVertice);

    private:
        string rotulo;
};


#endif