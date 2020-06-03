//
// Created by emman on 03/06/2020.
//

#include "CapteurDAO.h"

// TODO changer : debug
const string cheminCapteursCSV = "./Data/sensors.csv";

CapteurDAO::CapteurDAO() {}

CapteurDAO::~CapteurDAO() {

}

vector<Capteur *> *CapteurDAO::list() {

    CSVParser parser(cheminCapteursCSV);
//    parser.read();

    // TODO récupérer le résultat et le parser
    
    return nullptr;
}
