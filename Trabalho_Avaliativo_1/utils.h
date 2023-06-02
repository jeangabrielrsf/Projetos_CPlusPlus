#include "liga.h"
#include "time.h"

#define CAMPEONATO_BRASILEIRO           0
#define COPA_DO_BRASIL                  1
#define ESTADUAL                        2

#define ANO_ATUAL                       0
//Se ano atual = 2023, 2022 = ANO_ATUAL + 1,
// 2021 = ANO_ATUAL + 2
// 2020 = ANO_ATUAL + 3
// 2019 = ANO_ATUAL + 4
// 2018
// 2017
// e assim sucessivamente...

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
    if (n < 0 || n > 2) {
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
    retornoDesempenhoGF resposta;

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
            resposta.nomeTime = liga1.buscarTimePorIndice(liga1.maiorEvolucaoGolsEfetuados()).getNomeTime();
            resposta.desempenhoGolsFeitos = liga1.DesempenhoGolsEfetuadosTime(liga1.maiorEvolucaoGolsEfetuados());
    } else if (
        liga2.DesempenhoGolsEfetuadosTime(liga2.maiorEvolucaoGolsEfetuados())
        >
        liga1.DesempenhoGolsEfetuadosTime(liga1.maiorEvolucaoGolsEfetuados())
        &&
        liga2.DesempenhoGolsEfetuadosTime(liga2.maiorEvolucaoGolsEfetuados())
        >
        liga3.DesempenhoGolsEfetuadosTime(liga3.maiorEvolucaoGolsEfetuados())
    ) {
        resposta.nomeTime = liga2.buscarTimePorIndice(liga2.maiorEvolucaoGolsEfetuados()).getNomeTime();
        resposta.desempenhoGolsFeitos = liga2.DesempenhoGolsEfetuadosTime(liga2.maiorEvolucaoGolsEfetuados());

    } else {
        resposta.nomeTime =  liga3.buscarTimePorIndice(liga3.maiorEvolucaoGolsEfetuados()).getNomeTime();
        resposta.desempenhoGolsFeitos = liga3.DesempenhoGolsEfetuadosTime(liga3.maiorEvolucaoGolsEfetuados());
    }
    return resposta;
};

retornoDesempenhoGS compararMelhorDesempenhoGolsSofridos(Liga liga1, Liga liga2, Liga liga3) {
    retornoDesempenhoGS resposta;
    if (
        liga1.DesempenhoGolsSofridosTime(liga1.maiorEvolucaoGolsSofridos())
        <
        liga2.DesempenhoGolsSofridosTime(liga2.maiorEvolucaoGolsSofridos())
        &&
        liga1.DesempenhoGolsSofridosTime(liga1.maiorEvolucaoGolsSofridos())
        <
        liga3.DesempenhoGolsSofridosTime(liga3.maiorEvolucaoGolsSofridos())
    ) {
        resposta.nomeTime = liga1.buscarTimePorIndice(liga1.maiorEvolucaoGolsSofridos()).getNomeTime();
        resposta.desempenhoGolsSofridos = liga1.DesempenhoGolsSofridosTime(liga1.maiorEvolucaoGolsSofridos());
    } else if (
        liga2.DesempenhoGolsSofridosTime(liga2.maiorEvolucaoGolsSofridos())
        <
        liga1.DesempenhoGolsSofridosTime(liga1.maiorEvolucaoGolsSofridos())
        &&
        liga2.DesempenhoGolsSofridosTime(liga2.maiorEvolucaoGolsSofridos())
        <
        liga3.DesempenhoGolsSofridosTime(liga3.maiorEvolucaoGolsSofridos())
    ) {
        resposta.nomeTime = liga2.buscarTimePorIndice(liga2.maiorEvolucaoGolsSofridos()).getNomeTime();
        resposta.desempenhoGolsSofridos = liga2.DesempenhoGolsSofridosTime(liga2.maiorEvolucaoGolsSofridos());
    } else {
        resposta.nomeTime = liga3.buscarTimePorIndice(liga3.maiorEvolucaoGolsSofridos()).getNomeTime();
        resposta.desempenhoGolsSofridos = liga3.DesempenhoGolsSofridosTime(liga3.maiorEvolucaoGolsSofridos());
    }
    return resposta;
};