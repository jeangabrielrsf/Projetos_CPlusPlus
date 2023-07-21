#ifndef CSV_TOOL_H
#define CSV_TOOL_H

#include <string>
#include <vector>
#include <map>
#include <python3.8/Python.h>


using namespace std;

class CsvTool {
    public:
        CsvTool();
        ~CsvTool();
        bool readCSV(string &filePath, PyObject* &csvData);
        bool insertIntoCSV(string& filePath, vector<string>& data);
        bool listCSVColumns(string& filePath, vector<string>& columns);
        bool searchCSV(string& filePath, string& searchCriteria,PyObject * &searchResult);
        bool deleteFromCSV(string& filePath, map<string, string>& conditions);
};


#endif