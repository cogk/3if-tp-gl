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
    map<string, vector<string*>*>* read(map<int, string> params = map<int, string>());
    bool add(vector<string> line);
    bool deleteLines(map<int, string> params = map<int, string>());
    bool editLines(map<int, string> params = map<int, string>(), vector<string> newLine);

// Constructeurs / destructeurs
    CSVParser(string csvStr);
    virtual ~CSVParser();

protected:
// Attributs privés
    string csv;
};


#endif //INC_3IF_GL_TP_CSVPARSER_H
