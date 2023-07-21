// #include <iostream>
// #include <iomanip>
// #include <string>
// #include <vector>
// #include <map>
// #include <python3.8/Python.h>

// #define NOME_ARQUIVO "notas.csv"



// using namespace std;

// int main() {

//     Py_Initialize();
//     PyRun_SimpleString("import sys; sys.path.insert(0, '')");
//     PyObject * pModule = PyImport_ImportModule("mymodule");
//     if (pModule == nullptr) {
//         cerr << "Failed to import the python module" << endl;
//         return -1;
//     }

//     PyObject * py_readCSV = PyObject_GetAttrString(pModule, "read_csv");
//     PyObject * py_listCSVColumns = PyObject_GetAttrString(pModule, "list_csv_columns");
//     PyObject * py_insertIntoCSV = PyObject_GetAttrString(pModule, "insert_into_csv");
//     PyObject * py_searchCSV = PyObject_GetAttrString(pModule, "search_into_csv");
//     PyObject * py_deleteFromCSV = PyObject_GetAttrString(pModule, "delete_from_csv");
//     if (
//         !PyCallable_Check(py_readCSV) || 
//         !PyCallable_Check(py_listCSVColumns) ||
//         !PyCallable_Check(py_insertIntoCSV) ||
//         !PyCallable_Check(py_searchCSV) ||
//         !PyCallable_Check(py_deleteFromCSV)
//         ) {
//         cerr << "Erro! Funçoes Python não podem ser chamadas!" << endl;
//         Py_XDECREF(py_readCSV);
//         Py_XDECREF(py_listCSVColumns);
//         Py_XDECREF(py_insertIntoCSV);
//         Py_XDECREF(py_searchCSV);
//         Py_XDECREF(py_deleteFromCSV);
//         Py_XDECREF(pModule);
//         Py_Finalize();
//         return -1;
//     }

//     int menuChoice = 0;
//     string csvFilePath = NOME_ARQUIVO;
//     string searchCriteria;
//     PyObject * pArgs = Py_BuildValue("(s)", csvFilePath.c_str());
//     PyObject * pArgsSearch;
//     PyObject * CSVData;
//     PyObject * CSVColumns;
//     vector<string> fileColumns;
//     map<string, vector<string>> searchResult;


//     system("clear");
//     while (menuChoice != 9) {
//         cout << setw(15) << setfill('-') << "" << endl;
//         cout << "Menu Gerenciador" << endl;
//         cout << setw(15) << setfill('-') << "" << endl;
//         cout << "Escolha uma das opções abaixo: " << endl;
//         cout << "[1] - Ler dados de um arquivo CSV" << endl;
//         cout << "[2] - Inserir dados em um arquivo CSV" << endl;
//         cout << "[3] - Remover dados de um arquivo CSV" << endl;
//         cout << "[4] - Procurar por algum dado específico no arquivo" << endl;
//         cout << setw(15) << setfill('-') << "" << endl;
//         cout << endl;
//         cout << "Selecionar [9] para fechar o programa" << endl;

//         cin >> menuChoice;

//         switch (menuChoice)
//         {
//         case 1:
//             CSVData = PyObject_CallObject(py_readCSV, pArgs);
//             if (CSVData != nullptr) {
//                 cout << "Arquivo .csv lido com sucesso:" << endl;
//                 cout << setw(15) << setfill('-') << "" << endl;
//                 PyObject * pyStrRepr = PyObject_Repr(CSVData);
//                 string data = PyUnicode_AsUTF8(pyStrRepr);
//                 cout << data << endl;
//                 Py_XDECREF(pyStrRepr);
//             } else {
//                 cerr << "Arquivo inexistente ou vazio! "<< endl;
//             }
//             break;

//         case 2:
//             CSVData = PyObject_CallObject(py_readCSV, pArgs);
//             if (CSVData == nullptr) {
//                 cerr << "Arquivo vazio ou inexistente!" << endl;
//                 break;
//             }
//             CSVColumns = PyObject_CallObject(py_listCSVColumns, pArgs);
//             if (PyList_Check(CSVColumns)) {
//                 for (Py_ssize_t i=0; i < PyList_Size(CSVColumns); i++) {
//                     PyObject * pValue = PyList_GetItem(CSVColumns, i);
//                     if (PyUnicode_Check(pValue)) {
//                         string column = PyUnicode_AsUTF8(pValue);
//                         fileColumns.push_back(column);
//                     }
//                 }
//             } else {
//                 cerr << "Falha ao obter o nome das colunas" << endl;
//                 Py_XDECREF(CSVColumns);
//             }


//             if (!fileColumns.empty()) {
//                 vector<string> insertColumns;
//                 string data;
//                 cout << "Inserindo dados no arquivo .csv:" << endl;
//                 cin.clear();
//                 cin.ignore(__INT_MAX__, '\n');
//                 for (const auto& column : fileColumns) {
//                     cout << "Insira o dado para a coluna " + column << endl;
//                     getline(cin, data);
//                     insertColumns.push_back(data);
//                 }

//                 PyObject * pInsertList = PyList_New(insertColumns.size());
//                 for (size_t i = 0; i < insertColumns.size(); i++) {
//                     PyObject* pValue = PyUnicode_FromString(insertColumns.at(i).c_str());
//                     PyList_SetItem(pInsertList, i, pValue);
//                 }
//                 PyObject * pArgsInsert = Py_BuildValue("(sO)", csvFilePath.c_str(), pInsertList);
//                 PyObject_CallObject(py_insertIntoCSV, pArgsInsert);


//                 Py_XDECREF(pArgsInsert);
//                 Py_XDECREF(py_insertIntoCSV);
//                 Py_XDECREF(pInsertList);
//                 insertColumns.clear();
//                 fileColumns.clear();


//             } else {
//                 cerr << "Nenhuma coluna encontrada no arquivo" << endl;
//             }
//                 cout << "Dados inseridos com sucesso!" << endl;
//             break;

//         case 3: {
//             cout << "Entre com o nome da coluna que deseja deletar um valor:" << endl;
//             string deleteColumn;
//             cin >> deleteColumn;

//             cout << "Entre com o valor dentro de " << deleteColumn << " :" << endl;
//             string deleteValue;
//             cin.clear();
//             cin.ignore(__INT_MAX__, '\n');
//             getline(cin, deleteValue);

//             PyObject *pArgsDelete = Py_BuildValue("(s,{s:s})", csvFilePath.c_str(), deleteColumn.c_str(), deleteValue.c_str());
//             PyObject_CallObject(py_deleteFromCSV, pArgsDelete);
//             Py_XDECREF(pArgsDelete);

//             cout << "Dados deletados com sucesso" << endl;

//             break;
//         }
//         case 4:
//             cout << "Colunas presentes no arquivo .csv:" << endl;
//             CSVColumns = PyObject_CallObject(py_listCSVColumns, pArgs);
//             if (PyList_Check(CSVColumns)) {
//                 for (Py_ssize_t i=0; i < PyList_Size(CSVColumns); i++) {
//                     PyObject * pValue = PyList_GetItem(CSVColumns, i);
//                     if (PyUnicode_Check(pValue)) {
//                         string column = PyUnicode_AsUTF8(pValue);
//                         cout << column << endl;
//                         fileColumns.push_back(column);
//                     }
//                 }

//                 cin.clear();
//                 cin.ignore(__INT_MAX__, '\n');
//                 cout << "Entre com um critério de busca (ex: Nota > '5')" << endl;
//                 getline(cin, searchCriteria);
//                 cout << searchCriteria << endl;
//                 pArgsSearch = Py_BuildValue("(s,s)", csvFilePath.c_str(),searchCriteria);
//                 cout << "teste" << endl;
//                 PyObject * pySearchResult = PyObject_CallObject(py_searchCSV, pArgsSearch);
//                 if (PyDict_Check(pySearchResult)) {
//                     PyObject * pKey, * pValue;
//                     Py_ssize_t pos = 0;

//                     while (PyDict_Next(pySearchResult, &pos, &pKey, &pValue)) {
//                         cout << "entrei no while" << endl;
//                         string key = PyUnicode_AsUTF8(pKey);
//                         vector<string> values;
//                         if (PyList_Check(pValue)) {
//                             for (Py_ssize_t i = 0; i < PyList_Size(pValue); i++) {
//                                 PyObject *pItem = PyList_GetItem(pValue, i);
//                                 if (PyUnicode_Check(pItem)) {
//                                     values.push_back(PyUnicode_AsUTF8(pItem));
//                                 }
//                             }
//                             searchResult[key] = values;
//                         }
//                     }               
//                     //limpando objeto python
//                     Py_XDECREF(pySearchResult);
//                 } else {
//                     cerr << "O resultado da busca não é um dicionário Python válido!" << endl;
//                     Py_XDECREF(pySearchResult);
//                 }

 

//             } else {
//                 cerr << "Falha ao obter o nome das colunas" << endl;
//                 Py_XDECREF(CSVColumns);
//             }
           

//             if(!searchResult.empty()) {
//                 cout << "Matching rows:" << endl;
//                 for (const auto& row: searchResult) {
//                     cout << row.first << ": ";
//                     for (const auto& value: row.second) {
//                         cout << value << " ";
//                     }
//                     cout << endl;
//                 }
//             } else {
//                 cout << "Nenhum resultado retornado do critério de busca" << endl;
//             }

//             break;


//         case 9:
//             cout << "Fechando o programa..." << endl;
//             break;
        
//         default:
//             cout << "Opção indisponível!" << endl;
//             cout << "Por favor, selecione uma opção correta:" << endl;
//             cin >> menuChoice;
//             break;
//         }
//     }
    

//     Py_XDECREF(pArgs);
//     Py_XDECREF(pArgsSearch);
//     Py_XDECREF(CSVData);
//     Py_XDECREF(CSVColumns);
//     Py_XDECREF(py_readCSV);
//     Py_XDECREF(py_listCSVColumns);
//     Py_XDECREF(py_insertIntoCSV);
//     Py_XDECREF(py_searchCSV);
//     Py_XDECREF(py_deleteFromCSV);
//     Py_XDECREF(pModule);
//     Py_Finalize();

//     return 0;
// }


#include "runApp.h"

int main() {
    RunApp app;
    app.run();

    return 0;
}