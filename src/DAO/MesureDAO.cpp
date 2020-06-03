//
// Created by emman on 26/05/2020.
//

#include "MesureDAO.h"

#include <utility>
#include <ctime>
#include <map>
#include <math.h>
#include <iomanip>
#include <sstream>

const string MesureDAO::mesurePath = "../Data/measurements.csv";
const string MesureDAO::capteurPath = "../Data/sensors.csv";
const string MesureDAO::typePath = "../Data/attributes.csv";
const string MesureDAO::testPath = "../Data/tests.csv";

MesureDAO::MesureDAO() {}

bool MesureDAO::add(const Mesure& mesure) {

//    const char * formatTimestamp("%F%T");  // pas supporté on dirait -> rip
    const char * formatTimestamp("%Y-%m-%d %H:%M:%S");

    // formatTimestamp csv : timestamp;SensorID;AttributeID;Value;
    vector<string> ligne;
    stringstream ss;

    // timestamp
    time_t rawtime = mesure.getDate();
    struct tm * timeinfo;
    char buffer [200];
    timeinfo = localtime (&rawtime);

    strftime (buffer, 200, formatTimestamp, timeinfo);
//    std::cerr << "Timestamp ajouté : " << buffer << std::endl;    // debug

    ss << buffer;
    ligne.push_back(ss.str());

    // sensor ID
    ligne.push_back(mesure.getCapteur().getSensorId());

    // attribute ID
    ligne.push_back(mesure.getType().getAttributeId());

    // value
    ligne.push_back(to_string(mesure.getValeur()));

    // TODO changer !!!
//    CSVParser parser (mesurePath);
    CSVParser parser (testPath);
    return parser.add(ligne);

}

double distanceGPS(Coordonnees coo1, Coordonnees coo2)
{
    double lon1 = coo1.getLongitude(), lat1 = coo1.getLattitude();
    double lon2 = coo2.getLongitude(), lat2 = coo2.getLattitude();

    // https://www.movable-type.co.uk/scripts/latlong.html
    const double PI = 3.14159265359;

    // calcul distance entre deux points GPS
    const double R = 6371e3; // rayon de la Terre en mètres

    const double p1 = lat1 * PI / 180; // angles en (radians)
    const double p2 = lat2 * PI / 180;
    const double dp = (lat2 - lat1) * PI / 180;
    const double dl = (lon2 - lon1) * PI / 180;

    const double a = sin(dp / 2) * sin(dp / 2) + cos(p1) * cos(p2) * sin(dl / 2) * sin(dl / 2);
    const double c = 2 * atan2(sqrt(a), sqrt(1 - a));
    const double d = R * c; // distance en mètres

    return d;
}

vector<Mesure *> *MesureDAO::list(Coordonnees centre, double rayon, time_t debut, time_t fin, bool filtrerParDistance, bool filtrerParDate)
{
    CSVParser parserMesure(mesurePath);
    CSVParser parserCapteur(capteurPath);
    CSVParser parserType(typePath);

    // Récupération des mesures
    map<int, string> params;
    vector<vector<string*>*>* mesures = parserMesure.read(params);

    vector<Mesure*>* retour = new vector<Mesure*>();
    int i = 0;
    // Tri des mesures
    for (vector<string*>* line : *mesures) {
        string &dateStr = *line->at(0);
        string &nomCapteur = *line->at(1);
        string &nomType = *line->at(2);
        string &valeur = *line->at(3);
        if (i++ % 100 == 0) {
            cout << "Ligne " << i << "/" << mesures->size() << endl;
        }

        // Récupération du capteur

        map<int, string> paramsCapteur;
        paramsCapteur.insert(pair<int, string>(0, nomCapteur));
        vector<vector<string *> *> *capteurCsv = parserCapteur.read(paramsCapteur);
        auto capteurCsvLine = capteurCsv->at(0);
        Coordonnees coos(stod(*capteurCsvLine->at(1)), stod(*capteurCsvLine->at(2)));
        Capteur capteur(*capteurCsvLine->at(0), "", coos);

        // Nettoyage mémoire
        for (vector<string *> *vec : *capteurCsv) {
            for (string *str : *vec) {
                delete str;
            }
            delete vec;
        }
        delete capteurCsv;

        // récupération du type
        map<int, string> paramsType;
        paramsType.insert(pair<int, string>(0, nomType));
        vector<vector<string *> *> *typeCsv = parserType.read(paramsType);
        auto typeCsvLine = typeCsv->at(0);
        Type type(*typeCsvLine->at(0), *typeCsvLine->at(1), *typeCsvLine->at(2));

        // Nettoyage mémoire
        for (vector<string *> *vec : *typeCsv) {
            for (string *str : *vec) {
                delete str;
            }
            delete vec;
        }
        delete typeCsv;

        // Vérification de la mesure
        tm tm{};
        istringstream str_stream(dateStr);
        str_stream >> get_time(&tm, "%Y-%m-%d %T");
        time_t date = mktime(&tm);
        const bool validDate = filtrerParDate ? (debut < date && date < fin) : true;
        const bool validDistance = filtrerParDistance ? (distanceGPS(centre, capteur.getCoordonnees()) <= rayon) : true;
        const bool valid = validDate && validDistance;
        if (valid)
        {
            Mesure *mesure = new Mesure(stod(valeur), date, "", capteur, type);
            retour->push_back(mesure);
        }

        // Nettoyage mémoire
        for (string *str : *line) {
            delete str;
        }
        delete line;
    }

    return retour;
}

void MesureDAO::clean() {
    // TODO
}

MesureDAO::~MesureDAO() {

}

