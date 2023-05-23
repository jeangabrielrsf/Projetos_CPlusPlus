#include <iostream>
#include <vector>
#include <string>
#include "liga.h"
#include "time.h"

using namespace std;

int main() {

    int escolhaMenu = 0;
    Time fla("Flamengo");
    Time flu("Fluminense"); 
    Time bot("Botafogo");
    Time vas("Vasco da Gama");
    Time cru("Cruzeiro");

    Liga camp("Campeonato Brasileiro");
    Liga copa("Copa do Brasil"), est("Estadual");

    camp.inserirTime(fla);
    camp.inserirTime(flu);
    camp.inserirTime(vas);
    camp.inserirTime(bot);
    camp.inserirTime(cru);

    copa.inserirTime(fla);
    copa.inserirTime(flu);
    copa.inserirTime(vas);
    copa.inserirTime(bot);
    copa.inserirTime(cru);

    est.inserirTime(fla);
    est.inserirTime(flu);
    est.inserirTime(vas);
    est.inserirTime(bot);

    camp.listarTimes();
    copa.listarTimes();
    est.listarTimes();




    while (escolhaMenu != -1) {
        cout << "\n\nMenu Principal" << endl;
        cout << "Escolha uma das opções listadas:" << endl;
        cout << "1 - Exibir evoluão média dos gols realizados e sofridos de cinco times nos últimos anos" << endl;
        cout << "2 - Exibir a evolução do desempenho dos times em determinado campeonato" << endl;
        cout << "3 - Exibir a evoliução dos times em todos os campeonatos" << endl;
        cout << "4 - Exibir o time com o maior saldo de gols em um campeonato" << endl;
        cout << "5 - Mostrar qual time teve a maior evolução de desempenho em relação ao ano anterior" << endl;
        cout << "Digite [-1] para fechar o programa" << endl;

        cin >> escolhaMenu;

        cout << "Você escolheu -> " << escolhaMenu << endl;

        switch (escolhaMenu) {
            case 1:
                system("clear");
                cout << "escolhi a opção 1" << endl;
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