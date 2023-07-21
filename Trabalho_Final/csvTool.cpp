#include <iostream>
#include "csvTool.h"

CsvTool::CsvTool() {
    Py_Initialize();
    PyRun_SimpleString("import sys; sys.path.insert(0, '')");
}

CsvTool::~CsvTool() {
    Py_Finalize();
}

bool CsvTool::readCSV(string & filePath, PyObject*& csvData) {
    PyObject* pModule = PyImport_ImportModule("mymodule");
    if (pModule == nullptr) {
        cerr << "Falha na importação do módulo Python." << endl;
        return false;
    }

    PyObject* py_readCSV = PyObject_GetAttrString(pModule, "read_csv");
    if (!PyCallable_Check(py_readCSV)) {
        cerr << "Erro! Função 'read_csv' não pôde ser chamada!" << endl;
        Py_XDECREF(py_readCSV);
        Py_XDECREF(pModule);
        return false;
    }

    PyObject* pArgs = Py_BuildValue("(s)", filePath.c_str());
    csvData = PyObject_CallObject(py_readCSV, pArgs);
    Py_XDECREF(pArgs);
    Py_XDECREF(py_readCSV);
    Py_XDECREF(pModule);

    return csvData != nullptr;

}

bool CsvTool::insertIntoCSV(string& filePath, vector<string>& data) {
    PyObject* pModule = PyImport_ImportModule("mymodule");
    if (pModule == nullptr) {
        cerr << "Falha na importação do módulo Python." << endl;
        return false;
    }

    PyObject* py_insertIntoCSV = PyObject_GetAttrString(pModule, "insert_into_csv");
    if (!PyCallable_Check(py_insertIntoCSV)) {
        cerr << "Erro! Função 'insert_into_csv' não pôde ser chamada!" << endl;
        Py_XDECREF(py_insertIntoCSV);
        Py_XDECREF(pModule);
        return false;
    }

    PyObject* pInsertList = PyList_New(data.size());
    for (size_t i = 0; i < data.size(); i++) {
        PyObject* pValue = PyUnicode_FromString(data.at(i).c_str());
        PyList_SetItem(pInsertList, i, pValue);
    }

    PyObject* pArgsInsert = Py_BuildValue("(sO)", filePath.c_str(), pInsertList);
    PyObject_CallObject(py_insertIntoCSV, pArgsInsert);

    Py_XDECREF(pArgsInsert);
    Py_XDECREF(py_insertIntoCSV);
    Py_XDECREF(pInsertList);
    Py_XDECREF(pModule);

    return true;
}

bool CsvTool::listCSVColumns(string& filePath, vector<string>& columns) {
    PyObject* pModule = PyImport_ImportModule("mymodule");
    if (pModule == nullptr) {
        cerr << "Falha na importação do módulo Python." << endl;
        return false;
    }

    PyObject* py_listCSVColumns = PyObject_GetAttrString(pModule, "list_csv_columns");
    if (!PyCallable_Check(py_listCSVColumns)) {
        cerr << "Erro! Função 'list_csv_columns' não pôde ser chamada!" << endl;
        Py_XDECREF(py_listCSVColumns);
        Py_XDECREF(pModule);
        return false;
    }

    PyObject* pArgs = Py_BuildValue("(s)", filePath.c_str());
    PyObject* CSVColumns = PyObject_CallObject(py_listCSVColumns, pArgs);
    if (PyList_Check(CSVColumns)) {
        for (Py_ssize_t i = 0; i < PyList_Size(CSVColumns); i++) {
            PyObject* pValue = PyList_GetItem(CSVColumns, i);
            if (PyUnicode_Check(pValue)) {
                string column = PyUnicode_AsUTF8(pValue);
                columns.push_back(column);
            }
        }
    } else {
        cerr << "Falha ao obter o nome das colunas do arquivo .csv" << endl;
        Py_XDECREF(CSVColumns);
        Py_XDECREF(pArgs);
        Py_XDECREF(py_listCSVColumns);
        Py_XDECREF(pModule);
        return false;
    }

    Py_XDECREF(CSVColumns);
    Py_XDECREF(pArgs);
    Py_XDECREF(py_listCSVColumns);
    Py_XDECREF(pModule);

    return true;
}

bool CsvTool::searchCSV(string& filePath, string& criteria, PyObject* &searchResult) {
    PyObject* pModule = PyImport_ImportModule("mymodule");
    if (pModule == nullptr) {
        cerr << "Falha na importação do módulo Python." << endl;
        return false;
    }
    PyObject* py_searchCSV = PyObject_GetAttrString(pModule, "search_into_csv");
    if (!PyCallable_Check(py_searchCSV)) {
        cerr << "Erro! Função 'search_into_csv' não pôde ser chamada" << endl;
        Py_XDECREF(py_searchCSV);
        Py_XDECREF(pModule);
        return false;
    }

    PyObject* pArgsSearch = Py_BuildValue("(s,s)", filePath.c_str(), criteria.c_str());
    searchResult = PyObject_CallObject(py_searchCSV, pArgsSearch);

    Py_XDECREF(pArgsSearch);
    Py_XDECREF(py_searchCSV);
    Py_XDECREF(pModule);
    return true;
}

bool CsvTool::deleteFromCSV(string& filePath, map<string, string>& conditions) {
    PyObject* pModule = PyImport_ImportModule("mymodule");
    if (pModule == nullptr) {
        cerr << "Falha na importação do módulo Python." << endl;
        return false;
    }

    PyObject* py_deleteFromCSV = PyObject_GetAttrString(pModule, "delete_from_csv");
    if (!PyCallable_Check(py_deleteFromCSV)) {
        cerr << "Erro! Função 'delete_from_csv' não pôde ser chamada!" << endl;
        Py_XDECREF(py_deleteFromCSV);
        Py_XDECREF(pModule);
        return false;
    }

    PyObject* pArgsDelete = Py_BuildValue("(s,{s:s})", filePath.c_str(), conditions.begin()->first.c_str(), conditions.begin()->second.c_str());
    PyObject_CallObject(py_deleteFromCSV, pArgsDelete);

    Py_XDECREF(pArgsDelete);
    Py_XDECREF(py_deleteFromCSV);
    Py_XDECREF(pModule);

    return true;
}

