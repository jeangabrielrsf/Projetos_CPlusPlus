#ifndef RUN_APP_H
#define RUN_APP_H

#include <string>
#include <vector>
#include <map>
#include "csvTool.h"
#include "userInput.h"

class RunApp {
public:
    RunApp();
    ~RunApp();

    void run();

private:
    CsvTool csvTool;
    UserInput userInput;
    string csvFilePath;
    PyObject* CSVData;
    PyObject* CSVColumns;
    vector<string> fileColumns;
    map<string, vector<string>> searchResult;

    void printMenu();
    void populateColumns();
    void readCSVFile();
    void insertIntoCSV();
    void deleteFromCSV();
    void searchCSV();
};

#endif
