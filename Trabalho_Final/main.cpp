#include <iostream>
#include <iomanip>

using namespace std;

int main() {

    int menuChoice = 0;

    while (menuChoice != -1) {
        cout << setw(30) << setfill('#') << endl;
        cout << setw(30) << "Menu Gerenciador" << endl;
        cout << "Escolha uma das opções aabixo: " << endl;
        cout << "[1] - Ler dados de um arquivo CSV" << endl;
        cout << "[2] - Inserir dados em um arquivo CSV" << endl;
        cout << "[3] - Remover dados de um arquivo CSV" << endl;
        cout << "[4] - Procurar por algum dado específico no arquivo" << endl;
        cout << endl;
        cout << "Selecionar [-1] para fechar o programa" << endl;

        cin >> menuChoice;

        switch (menuChoice)
        {
        case 1:
            cout << "Opção 1 selecionada" << endl;
            break;

        case 2:
            cout << "Opção 2 selecionada" << endl;
            break;

        case 3:
            cout << "Opção 3 selecionada" << endl;
            break;
        
        case 4:
            cout << "Opção 4 selecionada" << endl;
            break;

        
        default:
            cout << "Opção indisponível!" << endl;
            cout << "Por favor, selecione uma opção correta:" << endl;
            cin >> menuChoice;
            break;
        }
    }
    


    return 0;
}