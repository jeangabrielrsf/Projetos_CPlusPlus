#include <iostream>
#include <iomanip>
#include "liga.h"

Liga::Liga(string _nomeLiga, int _codigoLiga) {
    nomeLiga = _nomeLiga;
    codigoLiga = _codigoLiga;
};

void Liga::listarTimes() {
    cout 
        <<  "\nTimes presentes em "
        << nomeLiga << ": "
    << endl;
    for (long unsigned int i=0; i < times.size(); i++) {
        cout
            << times.at(i).getNomeTime() << endl;
    }
};

string Liga::getNomeLiga() {
    return nomeLiga;
};

void Liga::inserirTime(Time novoTime) {
    if (times.size() >= maxTimes) {
        cout 
            << "\nImpossível adicionar mais que 5 times!"
        << endl;
    } else {
        times.push_back(novoTime);
        // cout 
        //     << "\nTime "
        //     << novoTime.getNomeTime()
        //     << " adicionado com sucesso "
        //     << "em " << nomeLiga
        // << endl;
    }
    
};



void Liga::listarMediasMoveis(int N) {

    cout 
        << "\n"
        << nomeLiga
        <<  setw(25) << "\n#########################"    
    << endl;

    for (long unsigned int i = 0; i < times.size(); i++) {
        cout
            << "\nMédia Movel do "
            << times.at(i).getNomeTime()
            << ":"
        << endl;

        cout 
            << "Gols efetuados: "
            << setprecision(2) << fixed
            << times.at(i).getMMGolsEfetuados(codigoLiga , 0, N)
        << endl;

        cout
            << "Gols sofridos: "
            << times.at(i).getMMGolsSofridos(codigoLiga, 0, N)
        << endl;
    }
    cout    
        << setw(25) << "\n#########################"
    <<endl;
}

void Liga::listarDesempenho() {

    double desempenhoGolsEfetuados[maxTimes];
    double desempenhoGolsSofridos[maxTimes];
    double MMAnoAtualEfetuados, MMAnoAtualSofridos;
    double MMAnoAnteriorEfetuados, MMAnoAnteriorSofridos;

    for (long unsigned int i = 0; i < times.size(); i++) {
        MMAnoAtualEfetuados = times.at(i).getMMGolsEfetuados(codigoLiga, 0, 3);
        MMAnoAnteriorEfetuados = times.at(i).getMMGolsEfetuados(codigoLiga, 1, 4);
        desempenhoGolsEfetuados[i] = (MMAnoAtualEfetuados/MMAnoAnteriorEfetuados);

        MMAnoAtualSofridos = times.at(i).getMMGolsSofridos(codigoLiga, 0, 3);
        MMAnoAnteriorSofridos = times.at(i).getMMGolsSofridos(codigoLiga, 1, 4);
        desempenhoGolsSofridos[i] = (MMAnoAtualSofridos/MMAnoAnteriorSofridos);
    }
    
    //listar os desempenhos dos times

    cout
        << "\nAnálise de Desempenho no(a) "
        << nomeLiga
    << endl;

    cout << "\nTimes com melhoria de desempenho:" << endl;
    for (long unsigned int i=0; i < maxTimes; i++) {
       if (desempenhoGolsEfetuados[i] > 1.05 || desempenhoGolsSofridos[i] < 0.95) {
            cout
                << "\n"
                << times.at(i).getNomeTime()
                << "\nDesempenho em gols efetuados: "
                << setprecision(2) << desempenhoGolsEfetuados[i]
                <<"\nDesempenho em gols sofridos: "
                << setprecision(2) << desempenhoGolsSofridos[i]
            << endl;
       }
    }

    cout << "\nTimes com piora de desempenho:" << endl;
    for (long unsigned int i=0; i < maxTimes; i++) {
       if (desempenhoGolsEfetuados[i] < 0.95 || desempenhoGolsSofridos[i] > 1.05) {
            cout
                << "\n"
                << times.at(i).getNomeTime()
                << "\nDesempenho em gols efetuados: "
                << setprecision(2) << desempenhoGolsEfetuados[i]
                <<"\nDesempenho em gols sofridos: "
                << setprecision(2) << desempenhoGolsSofridos[i]
            << endl;
       }
    }

    cout << "\nTimes em estabilidade:" << endl; 
    for (long unsigned i=0; i < maxTimes; i++) {
       if (
            (desempenhoGolsEfetuados[i] >= 0.95 && desempenhoGolsEfetuados[i] <= 1.05)
            && 
            (desempenhoGolsSofridos[i] <= 1.05 && desempenhoGolsSofridos[i] >= 0.95)
            ) {
            cout
                << "\n"
                << times.at(i).getNomeTime()
                << "\nDesempenho em gols efetuados: "
                << setprecision(2) << desempenhoGolsEfetuados[i]
                <<"\nDesempenho em gols sofridos: "
                << setprecision(2) << desempenhoGolsSofridos[i]
            << endl;
       }
    }

}

void Liga::exibirMaiorSaldo() {
    long int maiorSaldo = 0;
    int indexTime, indexAno, ano;
    //TO-DO : Talvez seria melhor criar um método privado para calcular isso
    //        e fazer esse método aqui só mostrar a parada já calculada
    for (long unsigned int i = 0; i < times.size(); i++) {
        for (int j = 0; j < 7; j++) {
            long int diferenca =  (
                times.at(i).getGolsEfetuados(codigoLiga, j) 
                - times.at(i).getGolsSofridos(codigoLiga, j)
            );
            if (diferenca > maiorSaldo) {
                maiorSaldo = diferenca;
                indexTime = i;
                indexAno = j;
                ano = 2023 - indexAno;
            }
        }
    }


    system("clear");
    cout << "Considerando dados de 2023 até 2017..." << endl;

    cout 
        << "\nTime com maior saldo de gols em "
        << nomeLiga << ": "
        << times.at(indexTime).getNomeTime()
        << "\nAno: " << (ano)
        << "\nGols efetuados: "
        << times.at(indexTime).getGolsEfetuados(codigoLiga, indexAno)
        <<"\nGols sofridos: "
        << times.at(indexTime).getGolsSofridos(codigoLiga, indexAno)
        << "\nSaldo: "
        << maiorSaldo
    << endl;
    
}


