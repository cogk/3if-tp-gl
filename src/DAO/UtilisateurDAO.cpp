//
// Created by emman on 03/06/2020.
//

#include "UtilisateurDAO.h"

const string UtilisateurDAO::utilisateurPath = "./Data/users.csv";

UtilisateurDAO::UtilisateurDAO() {}

UtilisateurDAO::~UtilisateurDAO() {}

vector<Utilisateur *> *UtilisateurDAO::list() {
    CSVParser parser(UtilisateurPath);

    vector<vector<string*>*> *types = parser.readVec();
    vector<Utilisateur*> *retour = new vector<Utilisateur*>();

    for (vector<string*> *linePtr : *types) {
        vector<string*> &line = *linePtr;
        retour->push_back(new Utilisateur(*line[0], "", Coordonnees(stod(*line[1]), stod(*line[2]))));

        for (string *str: *linePtr) {
            delete str;
        }
        delete linePtr;
    }
    delete types;

    return retour;
}
