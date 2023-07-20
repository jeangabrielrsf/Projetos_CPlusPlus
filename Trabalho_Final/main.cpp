#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <python3.8/Python.h>

#define NOME_ARQUIVO "notas.csv"



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
    PyObject * py_listCSVColumns = PyObject_GetAttrString(pModule, "list_csv_columns");
    if (!PyCallable_Check(py_readCSV) || !PyCallable_Check(py_listCSVColumns)) {
        cerr << "Erro! Funçoes Python não podem ser chamadas!" << endl;
        Py_XDECREF(py_readCSV);
        Py_XDECREF(py_listCSVColumns);
        Py_XDECREF(pModule);
        Py_Finalize();
        return -1;
    }

    int menuChoice = 0;
    string csvFilePath = NOME_ARQUIVO;
    PyObject * pArgs = Py_BuildValue("(s)", csvFilePath.c_str());
    PyObject * CSVData;
    PyObject * CSVColumns;
    vector<string> fileColumns;


    while (menuChoice != 9) {
        cout << setw(30) << setfill('#') << endl;
        cout << setw(30) << "\nMenu Gerenciador\n" << endl;
        cout << setw(30) << setfill('#') << endl;
        cout << "Escolha uma das opções abaixo: " << endl;
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
            CSVData = PyObject_CallObject(py_readCSV, pArgs);
            if (CSVData != nullptr) {
                cout << "Arquivo .csv lido com sucesso:" << endl;
                PyObject * pyStrRepr = PyObject_Repr(CSVData);
                string data = PyUnicode_AsUTF8(pyStrRepr);
                cout << data << endl;
                Py_XDECREF(pyStrRepr);
            } else {
                cerr << "Arquivo inexistente ou vazio! "<< endl;
            }

            break;

        case 2:
            CSVData = PyObject_CallObject(py_readCSV, pArgs);
            if (CSVData == nullptr) {
                cerr << "Arquivo vazio ou inexistente!" << endl;
                break;
            }
            CSVColumns = PyObject_CallObject(py_listCSVColumns, pArgs);
            if (PyList_Check(CSVColumns)) {
                for (Py_ssize_t i=0; i < PyList_Size(CSVColumns); i++) {
                    PyObject * pValue = PyList_GetItem(CSVColumns, i);
                    if (PyUnicode_Check(pValue)) {
                        string column = PyUnicode_AsUTF8(pValue);
                        fileColumns.push_back(column);
                    }
                }
            } else {
                cerr << "Falha ao obter o nome das colunas" << endl;
                Py_XDECREF(CSVColumns);
            }


            if (!fileColumns.empty()) {
                cout << "Colunas no arquivo .csv" << endl;
                for (const auto& column : fileColumns) {
                    cout << column << endl;
                }
            } else {
                cerr << "Nenhuma coluna encontrada no arquivo" << endl;
            }


            break;

        case 3:
            cout << "Opção 3 selecionada" << endl;
            break;
        
        case 4:
            cout << "Opção 4 selecionada" << endl;
            break;


        case 9:
            cout << "Fechando o programa..." << endl;
            Py_XDECREF(CSVData);
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