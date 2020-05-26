//
// Created by berth on 26/05/2020.
//

#include "CSVParser.h"
#include <assert.h>

using namespace std;

// Constructeurs / destructeurs

CSVParser::CSVParser(string csv) {
    csvFile.open(csv);
    assert(csvFile.is_open());
}

CSVParser::~CSVParser() {
    csvFile.close(csv);
}

// Méthodes publiques

void split(const string& str, const string& delim, vector<string> &result)
{
    size_t prev = 0, pos = 0;
    do {
        pos = str.find(delim, prev);
        if (pos == string::npos) pos = str.length();
        string token = str.substr(prev, pos-prev);
        result.push_back(token);
        prev = pos + delim.length();
    } while (pos < str.length() && prev < str.length());
}

vector<vector<string>> CSVParser::read(map<int, string> params) {
    vector<vector<string>> *result = new vector<vector<string>>;
    while (!csvFile.eof()) {
        string line;
        getline(csvFile, line);

        vector<string> *splittedLine = new vector<string>;
        split(line, ";", *splittedLine);

        result->push_back(splittedLine);
    }
}

bool CSVParser::add(vector<string> line) {
    string unsplittedLine = "";
    for (const string &str : line) {
        unsplittedLine += str + ";";
    }
    csvFile << unsplittedLine;
}

bool CSVParser::deleteLines(map<int, string> params) {
    return false;
}

bool CSVParser::editLines(map<int, string> params, vector<string> newLine) {
    return false;
}