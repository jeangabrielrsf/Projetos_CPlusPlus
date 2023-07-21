#include <iostream>
#include <sstream>
#include "userInput.h"

UserInput::UserInput() {}

UserInput::~UserInput() {}

int UserInput::getMenuChoice() {
    int choice;
    cin >> choice;
    return choice;
}

string UserInput::getInputString(const string& prompt) {
    string input;
    cout << prompt << endl;
    getline(cin, input);
    return input;
}

vector<string> UserInput::getInputList(const vector<string>& columnNames) {
    vector<string> inputList;
    cout << columnNames.size();
    for (unsigned i =0; i < columnNames.size(); i ++) {
        string data = getInputString("Entre com o dado para a coluna " + columnNames.at(i));
        inputList.push_back(data);
    }
    return inputList;
}

string UserInput::getColumnName() {
    return getInputString("Entre com o nome da coluna para ter o dado deletado:");
}

string UserInput::getColumnValue() {
    return getInputString("Entre com o valor do dado a ser deletado:");
}

string UserInput::getSearchCriteria() {
    return getInputString("Entre com o critério de busca (i.e., Nota > '5'):");
}
