#include <iostream>
#include <iomanip>
#include "runApp.h"

#define NOME_ARQUIVO    "notas.csv"


RunApp::RunApp() : csvFilePath(NOME_ARQUIVO), CSVData(nullptr){}

RunApp::~RunApp() {
    Py_XDECREF(CSVData);
}

void RunApp::run() {
    while (true) {
        int menuChoice = 0;

        printMenu();

        cin >> menuChoice;

        switch (menuChoice)
        {
        case 1:
            readCSVFile();
            break;
        
        case 2:
            insertIntoCSV();
            break;
        case 3:
            deleteFromCSV();
            break;

        case 4: 
            searchCSV();
            break;

        case 9:
            cout << "Fechando o programa..." << endl;
            return;

        default:
            cout << "Opção incorreta! Por favor, selecione a opção correta." << endl;
            break;
        }

    }
}

void RunApp::printMenu() {
    cout << setw(15) << setfill('-') << "" << endl;
    cout << "Menu Gerenciador" << endl;
    cout << setw(15) << setfill('-') << "" << endl;
    cout << "Escolha uma das opções abaixo: " << endl;
    cout << "[1] - Ler dados de um arquivo CSV" << endl;
    cout << "[2] - Inserir dados em um arquivo CSV" << endl;
    cout << "[3] - Remover dados de um arquivo CSV" << endl;
    cout << "[4] - Procurar por algum dado específico no arquivo" << endl;
    cout << setw(15) << setfill('-') << "" << endl;
    cout << endl;
    cout << "Selecionar [9] para fechar o programa" << endl;
}

void RunApp::readCSVFile() {
    if (csvTool.readCSV(csvFilePath, CSVData)) {
        cout << "Arquivo CSV lido com sucesso:" << endl;
        cout << endl;
        PyObject* pyStrRepr = PyObject_Repr(CSVData);
        string data = PyUnicode_AsUTF8(pyStrRepr);
        cout << data << endl;
        csvTool.listCSVColumns(csvFilePath, fileColumns);
        Py_XDECREF(pyStrRepr);
    } else {
        cerr << "Arquivo vazio ou não encontrado!" << endl;
    }
}

void RunApp::insertIntoCSV() {
    if (fileColumns.empty()) {
        cerr << "Não foram encontradas colunas no arquivo CSV" << endl;
        return;
    }

    cin.clear();
    cin.ignore(__INT_MAX__, '\n');
    vector<string> insertColumns = userInput.getInputList(fileColumns);
    if (csvTool.insertIntoCSV(csvFilePath, insertColumns)) {
        cout << "Dados inseridos com sucesso!" << endl;
    } else {
        cerr << "Falha na inserção de dados!" << endl;
    }
}


void RunApp::deleteFromCSV() {
    cin.clear();
    cin.ignore(__INT_MAX__, '\n');
    string deleteColumn = userInput.getColumnName();
    string deleteValue = userInput.getColumnValue();
    map<string, string> conditions = {{deleteColumn, deleteValue}};

    if (csvTool.deleteFromCSV(csvFilePath, conditions)) {
        cout << "Dados deletados com sucesso!" << endl;
    } else {
        cerr << "Falha ao deletar dados" << endl;
    }
}


void RunApp::searchCSV() {
    if (fileColumns.empty()) {
        cerr << "Não foram encontradas colunas no arquivo CSV" << endl;
        return;
    }

    cin.clear();
    cin.ignore(__INT_MAX__, '\n');
    string searchCriteria = userInput.getSearchCriteria();
    cout << "\antes do if do search\n" << endl;
    if (csvTool.searchCSV(csvFilePath, searchCriteria, searchResult)) {
        cout << "\nentrei no if do search\n" << endl;
        if (!searchResult.empty()) {
            cout << "Resultados da busca:" << endl;
            for (const auto& row : searchResult) {
                cout << row.first << ": ";
                for (const auto& value : row.second) {
                    cout << value << " ";
                }
                cout << endl;
            }
        }else {
            cout << "Não foram encontrados resultados com esse critério!" << endl;
        }        
    } else {
        cerr << "Falha ao buscar dados!" << endl;
    }
}