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
    PyObject * py_insertIntoCSV = PyObject_GetAttrString(pModule, "insert_into_csv");
    if (
        !PyCallable_Check(py_readCSV) || 
        !PyCallable_Check(py_listCSVColumns) ||
        !PyCallable_Check(py_insertIntoCSV)
        ) {
        cerr << "Erro! Funçoes Python não podem ser chamadas!" << endl;
        Py_XDECREF(py_readCSV);
        Py_XDECREF(py_listCSVColumns);
        Py_XDECREF(py_insertIntoCSV);
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
                vector<string> insertColumns;
                string data;
                cout << "Inserindo dados no arquivo .csv:" << endl;
                cin.clear();
                cin.ignore(__INT_MAX__, '\n');
                for (const auto& column : fileColumns) {
                    cout << "Insira o dado para a coluna " + column << endl;
                    getline(cin, data);
                    insertColumns.push_back(data);
                }

                PyObject * pInsertList = PyList_New(insertColumns.size());
                for (size_t i = 0; i < insertColumns.size(); i++) {
                    PyObject* pValue = PyUnicode_FromString(insertColumns.at(i).c_str());
                    PyList_SetItem(pInsertList, i, pValue);
                }
                PyObject * pArgsInsert = Py_BuildValue("(sO)", csvFilePath.c_str(), pInsertList);
                PyObject_CallObject(py_insertIntoCSV, pArgsInsert);


                Py_XDECREF(pArgsInsert);
                Py_XDECREF(py_insertIntoCSV);
                Py_XDECREF(pInsertList);
                insertColumns.clear();
                fileColumns.clear();


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