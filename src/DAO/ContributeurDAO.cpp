#include "ContributeurDAO.h"

#include <utility>
#include <ctime>
#include <map>
#include <math.h>
#include <iomanip>
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

    return retour;
}
