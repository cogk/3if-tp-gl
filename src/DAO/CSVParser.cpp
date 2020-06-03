//
// Created by berth on 26/05/2020.
//

#include "CSVParser.h"
#include <assert.h>

using namespace std;

// Constructeurs / destructeurs

CSVParser::CSVParser(string csvStr) {
    csv = csvStr;
}

CSVParser::~CSVParser() {
}

// Méthodes publiques

// Fonction nécessaire à CSVParser::read
void split(string& str, string& delim, vector<string*> &result)
{
    size_t prev = 0, pos = 0;
    do {
        pos = str.find(delim, prev);
        if (pos == string::npos) pos = str.length();
        string *token = new string;
        *token = str.substr(prev, pos-prev);
        result.push_back(token);
        prev = pos + delim.length();
    } while (pos < str.length() && prev < str.length());
}

map<string, vector<string*>*>* CSVParser::read(map<int, string> params) {
    ifstream csvFile(csv);
    map<string, vector<string*>*>* result = new map<string, vector<string*>*>;

    if (csvFile) {
        while (!csvFile.eof()) {
            string *line = new string;
            getline(csvFile, *line);
            if (line->empty()) {
                continue;
            }

            vector<string*> *splittedLine = new vector<string*>;
            string delim = ";";
            split(*line, delim, *splittedLine);

            bool ok = true;
            for (auto it = params.cbegin(); it != params.cend(); ++it) {
                if (it->first >= splittedLine->size() || *splittedLine->at(it->first) != it->second) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                result->insert(pair<string, vector<string*>*>(*splittedLine->at(0), splittedLine));
            } else {
                for (int i = 0; i < splittedLine->size(); i++) {
                    delete splittedLine->at(i);
                }
                delete splittedLine;
            }
        }

        csvFile.close();
    } else {
        cerr << "Oupsi : Erreur d'ouverture du fichier " << csv << " dans la methode CSVParser::read." << endl;
    }

    return result;
}

bool CSVParser::add(vector<string> line) {
    ofstream csvFile(csv, ios_base::app);

    if (csvFile) {
        string unsplittedLine = "";
        for (const string &str : line) {
            unsplittedLine = unsplittedLine + str + ";";
        }
        csvFile << unsplittedLine << endl;

        bool state = csvFile.good();
        csvFile.close();
        return state;
    }else{
        cerr << "Oupsi : Erreur d'ouverture du fichier " << csv << " dans la methode CSVParser::add." << endl;
    }

    return false;
}

bool CSVParser::deleteLines(map<int, string> params) {
    cerr << "deleteLines : fonctionnalité non implémentée" << endl;
    return false;
}

bool CSVParser::editLines(map<int, string> params, vector<string> newLine) {
    cerr << "editLines : fonctionnalité non implémentée" << endl;
    return false;
}
