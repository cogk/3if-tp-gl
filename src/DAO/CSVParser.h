//
// Created by berth on 26/05/2020.
//

#ifndef INC_3IF_GL_TP_CSVPARSER_H
#define INC_3IF_GL_TP_CSVPARSER_H

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>

using namespace std;

class CSVParser {
public:
// Méthodes publiques
    // Contrat : le retour devra être delete par l'utilisateur
    map<string, vector<string*>*>* read(map<size_t, string> params = map<size_t, string>());
    vector<vector<string*>*>* readVec(map<size_t, string> params = map<size_t, string>());

    bool add(vector<string> line);
    bool deleteLines(map<size_t, string> params = map<size_t, string>());
    bool editLines(map<size_t, string> params = map<size_t, string>(), vector<string> newLine = vector<string>());

    // Constructeurs / destructeurs
    CSVParser(string csvStr);
    virtual ~CSVParser();

protected:
// Attributs privés
    string csv;
};


#endif //INC_3IF_GL_TP_CSVPARSER_H
