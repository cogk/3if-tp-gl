//
// Created by emman on 03/06/2020.
//

#include "CapteurDAO.h"

const string CapteurDAO::capteurPath = "./Data/sensors.csv";

CapteurDAO::CapteurDAO() {}

CapteurDAO::~CapteurDAO() {}

vector<Capteur *> *CapteurDAO::list() {
    CSVParser parser(capteurPath);

    vector<vector<string*>*> *types = parser.readVec();
    vector<Capteur*> *retour = new vector<Capteur*>();

    for (vector<string*> *linePtr : *types) {
        vector<string*> &line = *linePtr;
        retour->push_back(new Capteur(*line[0], "", Coordonnees(stod(*line[1]), stod(*line[2]))));

        for (string *str: *linePtr) {
            delete str;
        }
        delete linePtr;
    }
    delete types;

    return retour;
}
