#include "liga.h"
#include "time.h"

struct retornoDesempenhoGF
{
    string nomeTime;
    double desempenhoGolsFeitos;
};

struct retornoDesempenhoGS {
    string nomeTime;
    double desempenhoGolsSofridos;
};


bool validarEscolhaMedia(int n) {
    if(n < 3 || n > 7) {
        return true;
    }
    return false;
};

bool erroEscolhaCampeonato(int n) {
    if (n < 0 || n > 3) {
        return true;
    }
    return false;
};

double compararMaiorNumero(double n1, double n2, double n3) {
    if (n1 > n2 && n1 > n3) {
        return n1;
    } else if (n2 > n1 && n2 > n3){
        return n2;
    } else {
        return n3;
    }
};

retornoDesempenhoGF compararMaiorDesempenhoGolsFeitos(Liga liga1, Liga liga2, Liga liga3) {

    if (
        liga1.DesempenhoGolsEfetuadosTime(liga1.maiorEvolucaoGolsEfetuados())
        >
        liga2.DesempenhoGolsEfetuadosTime(liga2.maiorEvolucaoGolsEfetuados())
        &&
        liga1.DesempenhoGolsEfetuadosTime(liga1.maiorEvolucaoGolsEfetuados())
        >
        liga3.DesempenhoGolsEfetuadosTime(liga3.maiorEvolucaoGolsEfetuados())
        ) 
        {
            return {
                liga1.buscarTimePorIndice(liga1.maiorEvolucaoGolsEfetuados()).getNomeTime(),
                liga1.DesempenhoGolsEfetuadosTime(liga1.maiorEvolucaoGolsEfetuados()),
            };
    } else if (
        liga2.DesempenhoGolsEfetuadosTime(liga2.maiorEvolucaoGolsEfetuados())
        >
        liga1.DesempenhoGolsEfetuadosTime(liga1.maiorEvolucaoGolsEfetuados())
        &&
        liga2.DesempenhoGolsEfetuadosTime(liga2.maiorEvolucaoGolsEfetuados())
        >
        liga3.DesempenhoGolsEfetuadosTime(liga3.maiorEvolucaoGolsEfetuados())
    ) {
        return {
            liga2.buscarTimePorIndice(liga2.maiorEvolucaoGolsEfetuados()).getNomeTime(),
            liga2.DesempenhoGolsEfetuadosTime(liga2.maiorEvolucaoGolsEfetuados())
        };
    } else {
        return {
            liga3.buscarTimePorIndice(liga3.maiorEvolucaoGolsEfetuados()).getNomeTime(),
            liga3.DesempenhoGolsEfetuadosTime(liga3.maiorEvolucaoGolsEfetuados())
        };
    }
}

retornoDesempenhoGS compararMelhorDesempenhoGolsSofridos(Liga liga1, Liga liga2, Liga liga3) {
    if (
        liga1.DesempenhoGolsSofridosTime(liga1.maiorEvolucaoGolsSofridos())
        <
        liga2.DesempenhoGolsSofridosTime(liga2.maiorEvolucaoGolsSofridos())
        &&
        liga1.DesempenhoGolsSofridosTime(liga1.maiorEvolucaoGolsSofridos())
        <
        liga3.DesempenhoGolsSofridosTime(liga3.maiorEvolucaoGolsSofridos())
    ) {
        return {
            liga1.buscarTimePorIndice(liga1.maiorEvolucaoGolsSofridos()).getNomeTime(),
            liga1.DesempenhoGolsSofridosTime(liga1.maiorEvolucaoGolsSofridos())
        };
    } else if (
        liga2.DesempenhoGolsSofridosTime(liga2.maiorEvolucaoGolsSofridos())
        <
        liga1.DesempenhoGolsSofridosTime(liga1.maiorEvolucaoGolsSofridos())
        &&
        liga2.DesempenhoGolsSofridosTime(liga2.maiorEvolucaoGolsSofridos())
        <
        liga3.DesempenhoGolsSofridosTime(liga3.maiorEvolucaoGolsSofridos())
    ) {
        return {
            liga2.buscarTimePorIndice(liga2.maiorEvolucaoGolsSofridos()).getNomeTime(),
            liga2.DesempenhoGolsSofridosTime(liga2.maiorEvolucaoGolsSofridos())
        };
    } else {
        return {
            liga3.buscarTimePorIndice(liga3.maiorEvolucaoGolsSofridos()).getNomeTime(),
            liga3.DesempenhoGolsSofridosTime(liga3.maiorEvolucaoGolsSofridos())
        };
    }
}