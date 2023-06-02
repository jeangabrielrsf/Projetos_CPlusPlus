#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include <iomanip>
#include <cstdlib>
#include "liga.h"
#include "time.h"
#include "utils.h"

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

using namespace std;

int main() {

    int escolhaMenu = 0;
    int escolhaTamanhoMedia, escolhaCampeonato;
    int escolhaEnter;
    Time fla("Flamengo");
    Time flu("Fluminense"); 
    Time bot("Botafogo");
    Time pal("Palmeiras");
    Time cor("Corinthians");
    retornoDesempenhoGF timeMaiorDesempenhoGF;
    retornoDesempenhoGS timeMaiorDesempenhoGS;

    Liga camp("Campeonato Brasileiro", CAMPEONATO_BRASILEIRO);
    Liga copa("Copa do Brasil", COPA_DO_BRASIL);
    Liga est("Estadual", ESTADUAL);


    //INSERINDO DADOS DO FLAMENGO NOS ÚLTIMOS 7 ANOS (CONTANDO O ATUAL)
    //NO CAMPEONATO BRASILEIRO
    fla.setGolsEfetuados(CAMPEONATO_BRASILEIRO, 13, ANO_ATUAL);
    fla.setGolsSofridos(CAMPEONATO_BRASILEIRO, 9, ANO_ATUAL);

    fla.setGolsEfetuados(CAMPEONATO_BRASILEIRO, 60, ANO_ATUAL+1);
    fla.setGolsSofridos(CAMPEONATO_BRASILEIRO, 39, ANO_ATUAL+1);

    fla.setGolsEfetuados(CAMPEONATO_BRASILEIRO, 69, ANO_ATUAL+2);
    fla.setGolsSofridos(CAMPEONATO_BRASILEIRO, 36, ANO_ATUAL+2);

    fla.setGolsEfetuados(CAMPEONATO_BRASILEIRO, 68, ANO_ATUAL+3);
    fla.setGolsSofridos(CAMPEONATO_BRASILEIRO, 48, ANO_ATUAL+3);

    fla.setGolsEfetuados(CAMPEONATO_BRASILEIRO, 86, ANO_ATUAL+4);
    fla.setGolsSofridos(CAMPEONATO_BRASILEIRO, 37, ANO_ATUAL+4);

    fla.setGolsEfetuados(CAMPEONATO_BRASILEIRO, 59, ANO_ATUAL+5);
    fla.setGolsSofridos(CAMPEONATO_BRASILEIRO, 29, ANO_ATUAL+5);

    fla.setGolsEfetuados(CAMPEONATO_BRASILEIRO, 49, ANO_ATUAL+6);
    fla.setGolsSofridos(CAMPEONATO_BRASILEIRO, 38, ANO_ATUAL+6);

    //INSERINDO DADOS DO FLAMENGO NOS ÚLTIMOS 7 ANOS (CONTANDO O ATUAL)
    //NA COPA DO BRASIL
    fla.setGolsEfetuados(COPA_DO_BRASIL, 8, ANO_ATUAL);
    fla.setGolsSofridos(COPA_DO_BRASIL, 4, ANO_ATUAL);

    fla.setGolsEfetuados(COPA_DO_BRASIL, 13, ANO_ATUAL+1);
    fla.setGolsSofridos(COPA_DO_BRASIL, 5, ANO_ATUAL+1);

    fla.setGolsEfetuados(COPA_DO_BRASIL, 18, ANO_ATUAL+2);
    fla.setGolsSofridos(COPA_DO_BRASIL, 5, ANO_ATUAL+2);

    fla.setGolsEfetuados(COPA_DO_BRASIL, 5, ANO_ATUAL+3);
    fla.setGolsSofridos(COPA_DO_BRASIL, 7, ANO_ATUAL+3);

    fla.setGolsEfetuados(COPA_DO_BRASIL, 4, ANO_ATUAL+4);
    fla.setGolsSofridos(COPA_DO_BRASIL, 2, ANO_ATUAL+4);

    fla.setGolsEfetuados(COPA_DO_BRASIL, 4, ANO_ATUAL+5);
    fla.setGolsSofridos(COPA_DO_BRASIL, 3, ANO_ATUAL+5);

    fla.setGolsEfetuados(COPA_DO_BRASIL, 8, ANO_ATUAL+6);
    fla.setGolsSofridos(COPA_DO_BRASIL, 6, ANO_ATUAL+6);

    //INSERINDO DADOS DO FLAMENGO NOS ÚLTIMOS 7 ANOS (CONTANDO O ATUAL)
    //NO CAMPEONATO ESTADUAL
    fla.setGolsEfetuados(ESTADUAL, 28, ANO_ATUAL);
    fla.setGolsSofridos(ESTADUAL, 13, ANO_ATUAL);

    fla.setGolsEfetuados(ESTADUAL, 30, ANO_ATUAL+1);
    fla.setGolsSofridos(ESTADUAL, 11, ANO_ATUAL+1);

    fla.setGolsEfetuados(ESTADUAL, 34, ANO_ATUAL+2);
    fla.setGolsSofridos(ESTADUAL, 13, ANO_ATUAL+2);

    fla.setGolsEfetuados(ESTADUAL, 34, ANO_ATUAL+3);
    fla.setGolsSofridos(ESTADUAL, 11, ANO_ATUAL+3);

    fla.setGolsEfetuados(ESTADUAL, 33, ANO_ATUAL+4);
    fla.setGolsSofridos(ESTADUAL, 13, ANO_ATUAL+4);

    fla.setGolsEfetuados(ESTADUAL, 23, ANO_ATUAL+5);
    fla.setGolsSofridos(ESTADUAL, 8, ANO_ATUAL+5);

    fla.setGolsEfetuados(ESTADUAL, 39, ANO_ATUAL+6);
    fla.setGolsSofridos(ESTADUAL, 12, ANO_ATUAL+6);




//INSERINDO DADOS DO FLUMINENSE NOS ÚLTIMOS 7 ANOS (CONTANDO O ATUAL)
//NO CAMPEONATO BRASILEIRO
    flu.setGolsEfetuados(CAMPEONATO_BRASILEIRO, 12, ANO_ATUAL);
    flu.setGolsSofridos(CAMPEONATO_BRASILEIRO, 6, ANO_ATUAL);

    flu.setGolsEfetuados(CAMPEONATO_BRASILEIRO, 63, ANO_ATUAL+1);
    flu.setGolsSofridos(CAMPEONATO_BRASILEIRO, 41, ANO_ATUAL+1);

    flu.setGolsEfetuados(CAMPEONATO_BRASILEIRO, 38, ANO_ATUAL+2);
    flu.setGolsSofridos(CAMPEONATO_BRASILEIRO, 38, ANO_ATUAL+2);
    
    flu.setGolsEfetuados(CAMPEONATO_BRASILEIRO, 55, ANO_ATUAL+3);
    flu.setGolsSofridos(CAMPEONATO_BRASILEIRO, 42, ANO_ATUAL+3);

    flu.setGolsEfetuados(CAMPEONATO_BRASILEIRO, 38, ANO_ATUAL+4);
    flu.setGolsSofridos(CAMPEONATO_BRASILEIRO, 46, ANO_ATUAL+4);

    flu.setGolsEfetuados(CAMPEONATO_BRASILEIRO, 32, ANO_ATUAL+5);
    flu.setGolsSofridos(CAMPEONATO_BRASILEIRO, 46, ANO_ATUAL+5);

    flu.setGolsEfetuados(CAMPEONATO_BRASILEIRO, 50, ANO_ATUAL+6);
    flu.setGolsSofridos(CAMPEONATO_BRASILEIRO, 53, ANO_ATUAL+6);


//INSERINDO DADOS DO FLUMINENSE NOS ÚLTIMOS 7 ANOS (CONTANDO O ATUAL)
//NA COPA DO BRASIL

    flu.setGolsEfetuados(COPA_DO_BRASIL, 6, ANO_ATUAL);
    flu.setGolsSofridos(COPA_DO_BRASIL, 0, ANO_ATUAL);

    flu.setGolsEfetuados(COPA_DO_BRASIL, 15, ANO_ATUAL+1);
    flu.setGolsSofridos(COPA_DO_BRASIL, 10, ANO_ATUAL+1);

    flu.setGolsEfetuados(COPA_DO_BRASIL, 8, ANO_ATUAL+2);
    flu.setGolsSofridos(COPA_DO_BRASIL, 7, ANO_ATUAL+2);
    
    flu.setGolsEfetuados(COPA_DO_BRASIL, 11, ANO_ATUAL+3);
    flu.setGolsSofridos(COPA_DO_BRASIL, 6, ANO_ATUAL+3);

    flu.setGolsEfetuados(COPA_DO_BRASIL, 15, ANO_ATUAL+4);
    flu.setGolsSofridos(COPA_DO_BRASIL, 5, ANO_ATUAL+4);

    flu.setGolsEfetuados(COPA_DO_BRASIL, 7, ANO_ATUAL+5);
    flu.setGolsSofridos(COPA_DO_BRASIL, 3, ANO_ATUAL+5);

    flu.setGolsEfetuados(COPA_DO_BRASIL, 17, ANO_ATUAL+6);
    flu.setGolsSofridos(COPA_DO_BRASIL, 13, ANO_ATUAL+6);


//INSERINDO DADOS DO FLUMINENSE NOS ÚLTIMOS 7 ANOS (CONTANDO O ATUAL)
//NO ESTADUAL

    flu.setGolsEfetuados(ESTADUAL, 32, ANO_ATUAL);
    flu.setGolsSofridos(ESTADUAL, 9, ANO_ATUAL);

    flu.setGolsEfetuados(ESTADUAL, 21, ANO_ATUAL+1);
    flu.setGolsSofridos(ESTADUAL, 5, ANO_ATUAL+1);

    flu.setGolsEfetuados(ESTADUAL, 26, ANO_ATUAL+2);
    flu.setGolsSofridos(ESTADUAL, 17, ANO_ATUAL+2);
    
    flu.setGolsEfetuados(ESTADUAL, 27, ANO_ATUAL+3);
    flu.setGolsSofridos(ESTADUAL, 13, ANO_ATUAL+3);

    flu.setGolsEfetuados(ESTADUAL, 26, ANO_ATUAL+4);
    flu.setGolsSofridos(ESTADUAL, 13, ANO_ATUAL+4);

    flu.setGolsEfetuados(ESTADUAL, 23, ANO_ATUAL+5);
    flu.setGolsSofridos(ESTADUAL, 11, ANO_ATUAL+5);

    flu.setGolsEfetuados(ESTADUAL, 34, ANO_ATUAL+6);
    flu.setGolsSofridos(ESTADUAL, 17, ANO_ATUAL+6);





//INSERINDO DADOS DO BOTAFOGO NOS ÚLTIMOS 7 ANOS (CONTANDO O ATUAL)
//NO CAMPEONATO BRASILEIRO
    bot.setGolsEfetuados(CAMPEONATO_BRASILEIRO, 14, ANO_ATUAL);
    bot.setGolsSofridos(CAMPEONATO_BRASILEIRO, 6, ANO_ATUAL);

    bot.setGolsEfetuados(CAMPEONATO_BRASILEIRO, 41, ANO_ATUAL+1);
    bot.setGolsSofridos(CAMPEONATO_BRASILEIRO, 43, ANO_ATUAL+1);

    bot.setGolsEfetuados(CAMPEONATO_BRASILEIRO, 56, ANO_ATUAL+2);
    bot.setGolsSofridos(CAMPEONATO_BRASILEIRO, 31, ANO_ATUAL+2);

    bot.setGolsEfetuados(CAMPEONATO_BRASILEIRO, 32, ANO_ATUAL+3);
    bot.setGolsSofridos(CAMPEONATO_BRASILEIRO, 62, ANO_ATUAL+3);

    bot.setGolsEfetuados(CAMPEONATO_BRASILEIRO, 31, ANO_ATUAL+4);
    bot.setGolsSofridos(CAMPEONATO_BRASILEIRO, 45, ANO_ATUAL+4);

    bot.setGolsEfetuados(CAMPEONATO_BRASILEIRO, 38, ANO_ATUAL+5);
    bot.setGolsSofridos(CAMPEONATO_BRASILEIRO, 46, ANO_ATUAL+5);

    bot.setGolsEfetuados(CAMPEONATO_BRASILEIRO, 45, ANO_ATUAL+6);
    bot.setGolsSofridos(CAMPEONATO_BRASILEIRO, 42, ANO_ATUAL+6);




//INSERINDO DADOS DO BOTAFOGO NOS ÚLTIMOS 7 ANOS (CONTANDO O ATUAL)
//NA COPA DO BRASIL
    bot.setGolsEfetuados(COPA_DO_BRASIL, 14, ANO_ATUAL);
    bot.setGolsSofridos(COPA_DO_BRASIL, 5, ANO_ATUAL);

    bot.setGolsEfetuados(COPA_DO_BRASIL, 6, ANO_ATUAL+1);
    bot.setGolsSofridos(COPA_DO_BRASIL, 5, ANO_ATUAL+1);

    bot.setGolsEfetuados(COPA_DO_BRASIL, 6, ANO_ATUAL+2);
    bot.setGolsSofridos(COPA_DO_BRASIL, 1, ANO_ATUAL+2);

    bot.setGolsEfetuados(COPA_DO_BRASIL, 6, ANO_ATUAL+3);
    bot.setGolsSofridos(COPA_DO_BRASIL, 4, ANO_ATUAL+3);

    bot.setGolsEfetuados(COPA_DO_BRASIL, 7, ANO_ATUAL+4);
    bot.setGolsSofridos(COPA_DO_BRASIL, 3, ANO_ATUAL+4);

    bot.setGolsEfetuados(COPA_DO_BRASIL, 1, ANO_ATUAL+5);
    bot.setGolsSofridos(COPA_DO_BRASIL, 2, ANO_ATUAL+5);

    bot.setGolsEfetuados(COPA_DO_BRASIL, 6, ANO_ATUAL+6);
    bot.setGolsSofridos(COPA_DO_BRASIL, 4, ANO_ATUAL+6);




//INSERINDO DADOS DO BOTAFOGO NOS ÚLTIMOS 7 ANOS (CONTANDO O ATUAL)
//NO CAMPEONATO ESTADUAL
    bot.setGolsEfetuados(ESTADUAL, 23, ANO_ATUAL);
    bot.setGolsSofridos(ESTADUAL, 10, ANO_ATUAL);

    bot.setGolsEfetuados(ESTADUAL, 26, ANO_ATUAL+1);
    bot.setGolsSofridos(ESTADUAL, 18, ANO_ATUAL+1);

    bot.setGolsEfetuados(ESTADUAL, 16, ANO_ATUAL+2);
    bot.setGolsSofridos(ESTADUAL, 10, ANO_ATUAL+2);

    bot.setGolsEfetuados(ESTADUAL, 15, ANO_ATUAL+3);
    bot.setGolsSofridos(ESTADUAL, 15, ANO_ATUAL+3);

    bot.setGolsEfetuados(ESTADUAL, 15, ANO_ATUAL+4);
    bot.setGolsSofridos(ESTADUAL, 13, ANO_ATUAL+4);

    bot.setGolsEfetuados(ESTADUAL, 20, ANO_ATUAL+5);
    bot.setGolsSofridos(ESTADUAL, 20, ANO_ATUAL+5);

    bot.setGolsEfetuados(ESTADUAL, 23, ANO_ATUAL+6);
    bot.setGolsSofridos(ESTADUAL, 19, ANO_ATUAL+6);





//INSERINDO DADOS DO PALMEIRAS NOS ÚLTIMOS 7 ANOS (CONTANDO O ATUAL)
//NO CAMPEONATO BRASILEIRO
    pal.setGolsEfetuados(CAMPEONATO_BRASILEIRO, 16, ANO_ATUAL);
    pal.setGolsSofridos(CAMPEONATO_BRASILEIRO, 6, ANO_ATUAL);

    pal.setGolsEfetuados(CAMPEONATO_BRASILEIRO, 66, ANO_ATUAL+1);
    pal.setGolsSofridos(CAMPEONATO_BRASILEIRO, 27, ANO_ATUAL+1);

    pal.setGolsEfetuados(CAMPEONATO_BRASILEIRO, 58, ANO_ATUAL+2);
    pal.setGolsSofridos(CAMPEONATO_BRASILEIRO, 43, ANO_ATUAL+2);

    pal.setGolsEfetuados(CAMPEONATO_BRASILEIRO, 51, ANO_ATUAL+3);
    pal.setGolsSofridos(CAMPEONATO_BRASILEIRO, 37, ANO_ATUAL+3);

    pal.setGolsEfetuados(CAMPEONATO_BRASILEIRO, 61, ANO_ATUAL+4);
    pal.setGolsSofridos(CAMPEONATO_BRASILEIRO, 32, ANO_ATUAL+4);

    pal.setGolsEfetuados(CAMPEONATO_BRASILEIRO, 64, ANO_ATUAL+5);
    pal.setGolsSofridos(CAMPEONATO_BRASILEIRO, 26, ANO_ATUAL+5);

    pal.setGolsEfetuados(CAMPEONATO_BRASILEIRO, 61, ANO_ATUAL+6);
    pal.setGolsSofridos(CAMPEONATO_BRASILEIRO, 45, ANO_ATUAL+6);

//NA COPA DO BRASIL
    pal.setGolsEfetuados(COPA_DO_BRASIL, 8, ANO_ATUAL);
    pal.setGolsSofridos(COPA_DO_BRASIL, 3, ANO_ATUAL);

    pal.setGolsEfetuados(COPA_DO_BRASIL, 6, ANO_ATUAL+1);
    pal.setGolsSofridos(COPA_DO_BRASIL, 4, ANO_ATUAL+1);

    pal.setGolsEfetuados(COPA_DO_BRASIL, 1, ANO_ATUAL+2);
    pal.setGolsSofridos(COPA_DO_BRASIL, 1, ANO_ATUAL+2);

    pal.setGolsEfetuados(COPA_DO_BRASIL, 15, ANO_ATUAL+3);
    pal.setGolsSofridos(COPA_DO_BRASIL, 4, ANO_ATUAL+3);

    pal.setGolsEfetuados(COPA_DO_BRASIL, 4, ANO_ATUAL+4);
    pal.setGolsSofridos(COPA_DO_BRASIL, 1, ANO_ATUAL+4);

    pal.setGolsEfetuados(COPA_DO_BRASIL, 5, ANO_ATUAL+5);
    pal.setGolsSofridos(COPA_DO_BRASIL, 4, ANO_ATUAL+5);

    pal.setGolsEfetuados(COPA_DO_BRASIL, 6, ANO_ATUAL+6);
    pal.setGolsSofridos(COPA_DO_BRASIL, 6, ANO_ATUAL+6);


//NO CAMPEONATO ESTADUAL
    pal.setGolsEfetuados(ESTADUAL, 25, ANO_ATUAL);
    pal.setGolsSofridos(ESTADUAL, 7, ANO_ATUAL);

    pal.setGolsEfetuados(ESTADUAL, 26, ANO_ATUAL+1);
    pal.setGolsSofridos(ESTADUAL, 7, ANO_ATUAL+1);

    pal.setGolsEfetuados(ESTADUAL, 21, ANO_ATUAL+2);
    pal.setGolsSofridos(ESTADUAL, 12, ANO_ATUAL+2);

    pal.setGolsEfetuados(ESTADUAL, 21, ANO_ATUAL+3);
    pal.setGolsSofridos(ESTADUAL, 7, ANO_ATUAL+3);

    pal.setGolsEfetuados(ESTADUAL, 19, ANO_ATUAL+4);
    pal.setGolsSofridos(ESTADUAL, 6, ANO_ATUAL+4);

    pal.setGolsEfetuados(ESTADUAL, 30, ANO_ATUAL+5);
    pal.setGolsSofridos(ESTADUAL, 11, ANO_ATUAL+5);

    pal.setGolsEfetuados(ESTADUAL, 30, ANO_ATUAL+6);
    pal.setGolsSofridos(ESTADUAL, 12, ANO_ATUAL+6);




//INSERINDO DADOS DO CORINTHIANS NOS ÚLTIMOS 7 ANOS (CONTANDO O ATUAL)
//NO CAMPEONATO BRASILEIRO
    cor.setGolsEfetuados(CAMPEONATO_BRASILEIRO, 6, ANO_ATUAL);
    cor.setGolsSofridos(CAMPEONATO_BRASILEIRO, 12, ANO_ATUAL);

    cor.setGolsEfetuados(CAMPEONATO_BRASILEIRO, 44, ANO_ATUAL+1);
    cor.setGolsSofridos(CAMPEONATO_BRASILEIRO, 36, ANO_ATUAL+1);

    cor.setGolsEfetuados(CAMPEONATO_BRASILEIRO, 40, ANO_ATUAL+2);
    cor.setGolsSofridos(CAMPEONATO_BRASILEIRO, 36, ANO_ATUAL+2);

    cor.setGolsEfetuados(CAMPEONATO_BRASILEIRO, 45, ANO_ATUAL+3);
    cor.setGolsSofridos(CAMPEONATO_BRASILEIRO, 45, ANO_ATUAL+3);

    cor.setGolsEfetuados(CAMPEONATO_BRASILEIRO, 42, ANO_ATUAL+4);
    cor.setGolsSofridos(CAMPEONATO_BRASILEIRO, 34, ANO_ATUAL+4);

    cor.setGolsEfetuados(CAMPEONATO_BRASILEIRO, 34, ANO_ATUAL+5);
    cor.setGolsSofridos(CAMPEONATO_BRASILEIRO, 35, ANO_ATUAL+5);

    cor.setGolsEfetuados(CAMPEONATO_BRASILEIRO, 50, ANO_ATUAL+6);
    cor.setGolsSofridos(CAMPEONATO_BRASILEIRO, 30, ANO_ATUAL+6);



//NA COPA DO BRASIL
    cor.setGolsEfetuados(COPA_DO_BRASIL, 2, ANO_ATUAL);
    cor.setGolsSofridos(COPA_DO_BRASIL, 4, ANO_ATUAL);

    cor.setGolsEfetuados(COPA_DO_BRASIL, 17, ANO_ATUAL+1);
    cor.setGolsSofridos(COPA_DO_BRASIL, 8, ANO_ATUAL+1);

    cor.setGolsEfetuados(COPA_DO_BRASIL, 4, ANO_ATUAL+2);
    cor.setGolsSofridos(COPA_DO_BRASIL, 3, ANO_ATUAL+2);

    cor.setGolsEfetuados(COPA_DO_BRASIL, 1, ANO_ATUAL+3);
    cor.setGolsSofridos(COPA_DO_BRASIL, 2, ANO_ATUAL+3);

    cor.setGolsEfetuados(COPA_DO_BRASIL, 11, ANO_ATUAL+4);
    cor.setGolsSofridos(COPA_DO_BRASIL, 9, ANO_ATUAL+4);

    cor.setGolsEfetuados(COPA_DO_BRASIL, 8, ANO_ATUAL+5);
    cor.setGolsSofridos(COPA_DO_BRASIL, 5, ANO_ATUAL+5);

    cor.setGolsEfetuados(COPA_DO_BRASIL, 6, ANO_ATUAL+6);
    cor.setGolsSofridos(COPA_DO_BRASIL, 3, ANO_ATUAL+6);




//NO CAMPEONATO ESTADUAL
    cor.setGolsEfetuados(ESTADUAL, 20, ANO_ATUAL);
    cor.setGolsSofridos(ESTADUAL, 11, ANO_ATUAL);

    cor.setGolsEfetuados(ESTADUAL, 21, ANO_ATUAL+1);
    cor.setGolsSofridos(ESTADUAL, 12, ANO_ATUAL+1);

    cor.setGolsEfetuados(ESTADUAL, 21, ANO_ATUAL+2);
    cor.setGolsSofridos(ESTADUAL, 12, ANO_ATUAL+2);

    cor.setGolsEfetuados(ESTADUAL, 19, ANO_ATUAL+3);
    cor.setGolsSofridos(ESTADUAL, 11, ANO_ATUAL+3);

    cor.setGolsEfetuados(ESTADUAL, 16, ANO_ATUAL+4);
    cor.setGolsSofridos(ESTADUAL, 13, ANO_ATUAL+4);

    cor.setGolsEfetuados(ESTADUAL, 23, ANO_ATUAL+5);
    cor.setGolsSofridos(ESTADUAL, 13, ANO_ATUAL+5);

    cor.setGolsEfetuados(ESTADUAL, 22, ANO_ATUAL+6);
    cor.setGolsSofridos(ESTADUAL, 11, ANO_ATUAL+6);

    //INSERINDO OS TIMES NAS COMPETIÇÕES
    camp.inserirTime(fla);
    camp.inserirTime(flu);
    camp.inserirTime(pal);
    camp.inserirTime(bot);
    camp.inserirTime(cor);

    copa.inserirTime(fla);
    copa.inserirTime(flu);
    copa.inserirTime(pal);
    copa.inserirTime(bot);
    copa.inserirTime(cor);

    est.inserirTime(fla);
    est.inserirTime(flu);
    est.inserirTime(pal);
    est.inserirTime(bot);
    est.inserirTime(cor);

    system("clear");

    //COMPUTANDO O DESEMPENHO E DEIXANDO DADOS PRONTOS
    camp.computarDesempenho();
    copa.computarDesempenho();
    est.computarDesempenho();



    while (escolhaMenu != -1) {
        cout << "#######################" << endl;
        cout << "Menu Principal" << endl;
        cout << "Escolha uma das opções listadas:" << endl;
        cout << "1 - Exibir evolução média dos gols realizados e sofridos de cinco times nos últimos anos" << endl;
        cout << "2 - Exibir a evolução do desempenho dos times em determinado campeonato em relação ao ano anterior" << endl;
        cout << "3 - Exibir a evolução dos times em todos os campeonatos em relaçao ao ano anterior" << endl;
        cout << "4 - Exibir o time com o maior saldo de gols em um campeonato" << endl;
        cout << "5 - Mostrar qual time teve a maior evolução de desempenho em relação ao ano anterior" << endl;
        cout << "#######################" << endl;
        cout << "Digite [-1] para fechar o programa" << endl;
        

        cin >> escolhaMenu;
        while(true) {
            if(cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Escolha um valor correto!!!" << endl;
                cin >> escolhaMenu;
            } else {

                break;
            }

        }

        switch (escolhaMenu) {
            case 1:
                system("clear");
                cout << "Escolha o tamanho da média móvel." << endl;
                cout << "(Escolher um número entre 3 e 7)" << endl;
                cin >> escolhaTamanhoMedia;
                while (validarEscolhaMedia(escolhaTamanhoMedia)) {
                    cout << "Impossível usar este valor! Escolha novamente" << endl;
                    cin >> escolhaTamanhoMedia;
                    if(cin.fail()) {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cin >> escolhaTamanhoMedia;
                    }
                }
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                system("clear");
                cout << "\nMedias Moveis no ultimos " << escolhaTamanhoMedia << " anos..." << endl;
                
                camp.listarMediasMoveis(escolhaTamanhoMedia);
                copa.listarMediasMoveis(escolhaTamanhoMedia);
                est.listarMediasMoveis(escolhaTamanhoMedia);

                cout
                    << "\nMédias Móveis Totais do " << fla.getNomeTime() << ":" 
                << endl;
                cout
                    << "Média Total de gols efetuados: "
                    << fla.getMMTotalEfetuados(0, escolhaTamanhoMedia)
                << endl;
                cout
                    << "Média Total de gols sofridos: "
                    << fla.getMMTotalSofridos(0, escolhaTamanhoMedia)
                << endl;

                 cout
                    << "\nMédias Móveis Totais do " << flu.getNomeTime() << ":" 
                << endl;
                cout
                    << "Média Total de gols efetuados: "
                    << flu.getMMTotalEfetuados(0, escolhaTamanhoMedia)
                << endl;
                cout
                    << "Média Total de gols sofridos: "
                    << flu.getMMTotalSofridos(0, escolhaTamanhoMedia)
                << endl;

                 cout
                    << "\nMédias Móveis Totais do " << bot.getNomeTime() << ":" 
                << endl;
                cout
                    << "Média Total de gols efetuados: "
                    << bot.getMMTotalEfetuados(0, escolhaTamanhoMedia)
                << endl;
                cout
                    << "Média Total de gols sofridos: "
                    << bot.getMMTotalSofridos(0, escolhaTamanhoMedia)
                << endl;

                 cout
                    << "\nMédias Móveis Totais do " << pal.getNomeTime() << ":" 
                << endl;
                cout
                    << "Média Total de gols efetuados: "
                    << pal.getMMTotalEfetuados(0, escolhaTamanhoMedia)
                << endl;
                cout
                    << "Média Total de gols sofridos: "
                    << pal.getMMTotalSofridos(0, escolhaTamanhoMedia)
                << endl;

                 cout
                    << "\nMédias Móveis Totais do " << cor.getNomeTime() << ":" 
                << endl;
                cout
                    << "Média Total de gols efetuados: "
                    << cor.getMMTotalEfetuados(0, escolhaTamanhoMedia)
                << endl;
                cout
                    << "Média Total de gols sofridos: "
                    << cor.getMMTotalSofridos(0, escolhaTamanhoMedia)
                << endl;


                cout << "\n\n\nPressione ENTER para voltar ao menu principal..." << endl;
                escolhaEnter = cin.get();
                while (escolhaEnter != '\n') {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    escolhaEnter = cin.get();
                }

                system("clear");
            break;

            case 2:
                system("clear");
                cout 
                    << "Digite o código do campeonato desejado:"
                    << "\n0 - CAMPEONATO BRASILEIRO"
                    << "\n1 - COPA DO BRASIL"
                    << "\n2 - ESTADUAL"
                << endl;

                cin >> escolhaCampeonato;
                while(erroEscolhaCampeonato(escolhaCampeonato)) {
                    cout << "Impossível usar este valor! Escolha novamente" << endl;
                    cin >> escolhaCampeonato;
                    if(cin.fail()) {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cin >> escolhaCampeonato;
                    }
                }
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                switch (escolhaCampeonato) {
                    case 0:
                        system("clear");
                        camp.listarDesempenho();
                    break;

                    case 1:
                        system("clear");
                        copa.listarDesempenho();
                    break;

                    case 2:
                        system("clear");
                        est.listarDesempenho();
                    break;

                    default:
                        cout << "Escolheu errado..." << endl;
                    break;
                }

                cout << "\n\n\nPressione ENTER para voltar ao menu principal..." << endl;
                escolhaEnter = cin.get();
                while (escolhaEnter != '\n') {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    escolhaEnter = cin.get();
                }

                system("clear");
            break;

            case 3:
                system("clear");

                cout << "Listando o desempenho de todos os campeonatos" << endl;

                camp.listarDesempenho();
                copa.listarDesempenho();
                est.listarDesempenho();

                cout << "\n\n\nPressione ENTER para voltar ao menu principal..." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                escolhaEnter = cin.get();
                while (escolhaEnter != '\n') {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    escolhaEnter = cin.get();
                }
                system("clear");
            break;

            case 4:
                system("clear");
                 cout 
                    << "Digite o código do campeonato desejado:"
                    << "\n0 - CAMPEONATO BRASILEIRO"
                    << "\n1 - COPA DO BRASIL"
                    << "\n2 - ESTADUAL"
                << endl;

                cin >> escolhaCampeonato;
                while(erroEscolhaCampeonato(escolhaCampeonato)) {
                    cout << "Impossível usar este valor! Escolha novamente" << endl;
                    cin >> escolhaCampeonato;
                    if(cin.fail()) {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cin >> escolhaCampeonato;
                    }
                }
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                switch (escolhaCampeonato) {
                    case 0:
                        camp.exibirMaiorSaldo();
                    break;

                    case 1:
                        copa.exibirMaiorSaldo();
                    break;

                    case 2:
                        est.exibirMaiorSaldo();
                    break;

                    default:
                        cout <<"escolheu errado hein..." << endl;
                    break;
                } 

                cout << "\n\n\nPressione ENTER para voltar ao menu principal..." << endl;
                escolhaEnter = cin.get();
                while (escolhaEnter != '\n') {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    escolhaEnter = cin.get();
                }
                system("clear");

            break;

            case 5:
                system("clear");
                timeMaiorDesempenhoGF = compararMaiorDesempenhoGolsFeitos(camp, copa, est);
                timeMaiorDesempenhoGS = compararMelhorDesempenhoGolsSofridos(camp, copa, est);
                cout 
                    << "Time com maior evolução em gols feitos: " 
                    << timeMaiorDesempenhoGF.nomeTime 
                << endl;
                cout
                    << "Evolucao do Desempenho em gols efetuados: "
                    << setprecision(2) << timeMaiorDesempenhoGF.desempenhoGolsFeitos
                << endl;
                cout 
                    << "Time com maior evolucao em gols sofridos:"
                    << timeMaiorDesempenhoGS.nomeTime 
                << endl;

                cout
                    << "Evolucao do desempenho em gols sofridos: "
                    << setprecision(2) << timeMaiorDesempenhoGS.desempenhoGolsSofridos
                << endl;

                cout << "\n\n\nPressione ENTER para voltar ao menu principal..." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                escolhaEnter = cin.get();
                while (escolhaEnter != '\n') {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    escolhaEnter = cin.get();
                }
                system("clear");
            break;

            case -1:
                system("clear");
                cout << "fechando..." << endl;
            break;

            default:
                system("clear");
            break;
        }
    }
    



    return 0;
}