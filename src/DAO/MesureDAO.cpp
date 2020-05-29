//
// Created by emman on 26/05/2020.
//

#include "MesureDAO.h"

#include <utility>
#include <ctime>

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

vector<Mesure> MesureDAO::list(Capteur, Coordonnees, Type, time_t, time_t) {
    // TODO
    return vector<Mesure>();
}

void MesureDAO::clean() {
    // TODO
}

MesureDAO::~MesureDAO() {

}

