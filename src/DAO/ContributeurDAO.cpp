#include "ContributeurDAO.h"
#include "CSVParser.h"

#include <ctime>
#include <map>
#include <sstream>

const string ContributeurDAO::contributeurPath = "./Data/users.csv";
const string ContributeurDAO::capteurPath = "./Data/sensors.csv";

ContributeurDAO::ContributeurDAO() {}

ContributeurDAO::~ContributeurDAO() {}

Contributeur *ContributeurDAO::getContributeur(const string &id) {
    CSVParser parser(contributeurPath);
    CSVParser capteurParser(capteurPath);

    vector<vector<string*>*> *contributeurs = parser.readVec();
    map<string, vector<string*>*> *capteurs = capteurParser.read();
    Contributeur *retour = nullptr;

    for (vector<string*> *ligne : *contributeurs) {
        if (*(*ligne)[0] != id) {
            continue;
        }

        if (retour == nullptr) {
            retour = new Contributeur(*(*ligne)[0], "", "", 0, 0);
        }

        vector<string *> *capteurCsv = capteurs->at(*(*ligne)[1]);
        Capteur capteur(*(*capteurCsv)[0], "", Coordonnees(stod(*(*capteurCsv)[1]), stod(*(*capteurCsv)[2])));

        retour->addCapteur(capteur);
    }

    for (auto i = contributeurs->begin(); i != contributeurs->end(); i++)
    {
        for (auto j = (*i)->begin(); j != (*i)->end(); j++)
        {
            delete *j;
        }
        delete *i;
    }
    delete contributeurs;

    for (auto i = capteurs->begin(); i != capteurs->end(); i++)
    {
        for (auto j = i->second->begin(); j != i->second->end(); j++)
        {
            delete *j;
        }
        delete i->second;
    }
    delete capteurs;

    return retour;
}

vector<string *>* ContributeurDAO::getUsernames() {

    CSVParser parser(contributeurPath);

    vector<vector<string*>*> *contributeurs = parser.readVec();
    vector<string *>* retour = new vector<string*>();

    for (vector<string*> *ligne : *contributeurs) {
        retour->push_back((*ligne)[0]);
    }

    for (auto i = contributeurs->begin(); i != contributeurs->end(); i++)
    {
        for (auto j = (*i)->begin()+1; j != (*i)->end(); j++)
        {
            delete *j;
        }
        delete *i;
    }
    delete contributeurs;

    return retour;
}
