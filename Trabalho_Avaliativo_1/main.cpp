#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include "liga.h"
#include "time.h"

#define CAMPEONATO_BRASILEIRO           0
#define COPA_DO_BRASIL                  1
#define ESTADUAL                        2

#define ANO_ATUAL                       0
//Se ano atual = 2023, 2022 = ANO_ATUAL + 1,
// 2021 = ANO_ATUAL + 2
// 2020 = ANO_ATUAL + 3
// e assim sucessivamente...



using namespace std;



bool validarEscolhaMedia(int n) {
    if(n < 3 || n > 7) {
        return true;
    }
    return false;
}


int main() {

    int escolhaMenu = 0;
    int escolhaTamanhoMedia;
    Time fla("Flamengo");
    Time flu("Fluminense"); 
    Time bot("Botafogo");
    Time pal("Palmeiras");
    Time cor("Corinthians");
    Time test("Vai dar erro!");

    Liga camp("Campeonato Brasileiro", CAMPEONATO_BRASILEIRO);
    Liga copa("Copa do Brasil", COPA_DO_BRASIL), est("Estadual", ESTADUAL);


    //INSERINDO DADOS DO FLAMENGO NOS ÚLTIMOS 7 ANOS (CONTANDO O ATUAL)
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


//INSERINDO DADOS DO FLUMINENSE NOS ÚLTIMOS 7 ANOS (CONTANDO O ATUAL)
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


//INSERINDO DADOS DO BOTAFOGO NOS ÚLTIMOS 7 ANOS (CONTANDO O ATUAL)
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


//INSERINDO DADOS DO PALMEIRAS NOS ÚLTIMOS 7 ANOS (CONTANDO O ATUAL)
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

//INSERINDO DADOS DO CORINTHIANS NOS ÚLTIMOS 7 ANOS (CONTANDO O ATUAL)
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



    camp.inserirTime(fla);
    camp.inserirTime(flu);
    camp.inserirTime(pal);
    camp.inserirTime(bot);
    camp.inserirTime(cor);

    camp.listarTimes();





    while (escolhaMenu != -1) {
        cout << "\n#######################" << endl;
        cout << "Menu Principal" << endl;
        cout << "Escolha uma das opções listadas:" << endl;
        cout << "1 - Exibir evoluão média dos gols realizados e sofridos de cinco times nos últimos anos" << endl;
        cout << "2 - Exibir a evolução do desempenho dos times em determinado campeonato" << endl;
        cout << "3 - Exibir a evoliução dos times em todos os campeonatos" << endl;
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
     


        cout << "Você escolheu -> " << escolhaMenu << endl;

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

                camp.listarMediasMoveisGolsEfetuados(escolhaTamanhoMedia);
                camp.listarMediasMoveisGolsSofridos(escolhaTamanhoMedia);

            break;

            case 2:
                system("clear");
                cout << "escolhi a 2" << endl;
            break;

            case 3:
                system("clear");
                cout << "escolhi a 3" << endl;
            break;

            case 4:
                system("clear");
                cout << "escolhi a 4" << endl;
            break;

            case 5:
                system("clear");
                cout << "escolhi a 5" << endl;    
            break;

            case -1:
                system("clear");
                cout << "fechando..." << endl;
            break;

            default:
                system("clear");
                cout << "bobo, escolhe alguma coisa aí" << endl;
            break;
        }
    }
    



    return 0;
}