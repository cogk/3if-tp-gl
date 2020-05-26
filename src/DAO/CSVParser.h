//
// Created by berth on 26/05/2020.
//

#ifndef INC_3IF_GL_TP_CSVPARSER_H
#define INC_3IF_GL_TP_CSVPARSER_H

#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

class CSVParser {
public:
// Méthodes publiques
    vector<vector<string>> read(map<int, string> params);
    bool add(vector<string> line);
    bool deleteLines(map<int, string> params);
    bool editLines(map<int, string> params, vector<string> newLine);

// Constructeurs / destructeurs
    CSVParser(string csv);
    virtual ~CSVParser();

private:
// Attributs privés
    fstream csvFile;
};


#endif //INC_3IF_GL_TP_CSVPARSER_H
