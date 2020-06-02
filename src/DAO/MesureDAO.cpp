//
// Created by emman on 26/05/2020.
//

#include "MesureDAO.h"

#include <utility>
#include <ctime>
#include <map>

const string MesureDAO::mesurePath = "Data/measurements.csv";
const string MesureDAO::capteurPath = "Data/sensors.csv";

MesureDAO::MesureDAO(string filePath){
    this->path = std::move(filePath);   // askip c'est mieux
}

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

    CSVParser parser (path);
    return parser.add(ligne);

}

vector<Mesure> MesureDAO::list(Coordonnees centre, double rayon, time_t debut, time_t fin) {
    CSVParser parser(mesurePath);
    map<int, string> params;
    vector<vector<string*>*>* mesures = parser.read(params);

    for (vector<string*>* line : *mesures) {
        string &date = *line->at(0);
        string &nomCapteur = *line->at(1);
        string &nomType = *line->at(2);
        string &valeur = *line->at(3);

        map<int, string> paramsCapteur;
        paramsCapteur.insert(pair<int, string>(0, nomCapteur));
        vector<vector<string*>*>* capteurCsv = parser.read(paramsCapteur);
        Capteur capteur()

        map<int, string> paramsType;
        paramsCapteur.insert(pair<int, string>(0, nomType));
        vector<vector<string*>*>* type = parser.read(paramsCapteur);


    }

    return vector<Mesure>();
}

void MesureDAO::clean() {
    // TODO
}

MesureDAO::~MesureDAO() {

}

