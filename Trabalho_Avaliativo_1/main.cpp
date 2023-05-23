#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {

    int escolhaMenu = 0;


    system("clear");
    while (escolhaMenu != -1) {
        cout << "Menu Principal" << endl;
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