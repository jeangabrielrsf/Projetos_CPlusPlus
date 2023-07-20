#include <iostream>
#include <iomanip>
#include <string>
#include <python3.8/Python.h>


using namespace std;

int main() {

    Py_Initialize();

    PyRun_SimpleString("import sys; sys.path.insert(0, '')");

    PyObject * pModule = PyImport_ImportModule("mymodule");
    if (pModule == nullptr) {
        cerr << "Failed to import the python module" << endl;
        return -1;
    }

    PyObject * py_readCSV = PyObject_GetAttrString(pModule, "read_csv");
    if (!PyCallable_Check(py_readCSV)) {
        cerr << "Erro! Funçoes Python não podem ser chamadas!" << endl;
        Py_XDECREF(py_readCSV);
        Py_XDECREF(pModule);
        Py_Finalize();
        return -1;
    }

    PyObject * pArgs;
    PyObject * CSVData;
    int menuChoice = 0;
    string csvFilePath = "notas.csv";


    while (menuChoice != 9) {
        cout << setw(30) << setfill('#') << endl;
        cout << setw(30) << "Menu Gerenciador" << endl;
        cout << "Escolha uma das opções aabixo: " << endl;
        cout << "[1] - Ler dados de um arquivo CSV" << endl;
        cout << "[2] - Inserir dados em um arquivo CSV" << endl;
        cout << "[3] - Remover dados de um arquivo CSV" << endl;
        cout << "[4] - Procurar por algum dado específico no arquivo" << endl;
        cout << endl;
        cout << "Selecionar [9] para fechar o programa" << endl;

        cin >> menuChoice;

        switch (menuChoice)
        {
        case 1:
            cout << "Opção 1 selecionada" << endl;
            pArgs = Py_BuildValue("(s)", csvFilePath.c_str());
            CSVData = PyObject_CallObject(py_readCSV, pArgs);
            if (CSVData != nullptr) {
                cout << "Arquivo .csv lido com sucesso:" << endl;
                PyObject * pyStrRepr = PyObject_Repr(CSVData);
                string data = PyUnicode_AsUTF8(pyStrRepr);
                cout << data << endl;
                Py_XDECREF(pyStrRepr);
                Py_XDECREF(CSVData);
            } else {
                cerr << "Falha na leitura do arquivo .csv" << endl;
                return -1;
            }

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


        case 9:
            cout << "Fechando o programa..." << endl;
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