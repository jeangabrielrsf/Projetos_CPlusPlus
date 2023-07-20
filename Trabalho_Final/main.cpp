#include <iostream>
#include <iomanip>
#include <stdio.h>
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

    PyObject * pAdd = PyObject_GetAttrString(pModule, "add");
    PyObject * pMultiply = PyObject_GetAttrString(pModule, "multiply");

    if (!PyCallable_Check(pAdd) || !PyCallable_Check(pMultiply)) {
        cerr << "Python functions are not callable" << endl;
        Py_XDECREF(pAdd);
        Py_XDECREF(pMultiply);
        Py_XDECREF(pModule);
        Py_Finalize();
        return -1;
    }

    int a, b;
    int addResult = 0;
    int multiplyResult = 1;
    PyObject * pArgs;
    PyObject * pAddResult;
    PyObject * pMultiplyResult;

    int menuChoice = 0;


    while (menuChoice != 9) {
        cout << setw(30) << setfill('#') << endl;
        cout << setw(30) << "Menu Gerenciador" << endl;
        cout << "Escolha uma das opções aabixo: " << endl;
        cout << "TESTE: USANDO PYTHON NÚMERO 5" << endl;
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

        case 5:
            cout << "Digite o primeiro número:" << endl;
            cin >> a;
            cout << "Digite o segundo número:" << endl;
            cin >> b;
            pArgs = Py_BuildValue("(ii)", a, b);
            pAddResult = PyObject_CallObject(pAdd, pArgs);
            pMultiplyResult = PyObject_CallObject(pMultiply, pArgs);

            PyArg_Parse(pAddResult, "i", &addResult);
            PyArg_Parse(pMultiplyResult, "i", &multiplyResult);

            Py_XDECREF(pArgs);
            Py_XDECREF(pAddResult);
            Py_XDECREF(pMultiplyResult);
            Py_XDECREF(pAdd);
            Py_XDECREF(pMultiply);
            Py_XDECREF(pModule);
            Py_Finalize();

            cout << "Adição entre " << a << " e " << b << ": " << addResult << endl;
            cout << "Multiplicação entre " << a << " e " << b << ": " << multiplyResult << endl;


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