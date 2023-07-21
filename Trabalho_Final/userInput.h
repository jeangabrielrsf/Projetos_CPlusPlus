#ifndef USER_INPUT_H
#define USER_INPUT_H

#include <string>
#include <vector>

using namespace std;

class UserInput {
public:
    UserInput();
    ~UserInput();

    int getMenuChoice();
    string getInputString(const string& prompt);
    vector<string> getInputList(const vector<string>& columnNames);
    string getColumnName();
    string getColumnValue();
    string getSearchCriteria();
};

#endif
