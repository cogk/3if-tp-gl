//
// Created by emman on 26/05/2020.
//

#include "MesureDAO.h"

MesureDAO::MesureDAO(){}

bool MesureDAO::add(Mesure mesure) {

    // format csv : timestamp;SensorID;AttributeID;Value;
    vector<string> ligne;
    stringstream ss;

    // timestamp
    ss << mesure.getDate();
    ligne.push_back(ss.str());

    // sensor ID
    ligne.push_back("SENSOR ID PLZ");

    // attribute ID
    ligne.push_back("ATTRIBUTE ID PLZ");

    // value
    ligne.push_back(to_string(mesure.getValeur()));

    CSVParser parser ("Data/measurements.csv");
    return parser.add(ligne);

}

vector<Mesure> MesureDAO::list(Capteur, Coordonnees, Type, time_t, time_t) {
    return nullptr;
}

void MesureDAO::clean() {

}

