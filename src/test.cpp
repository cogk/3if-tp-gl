//
// Created by emman on 26/05/2020.
//

#include "DAO/MesureDAO.h"

int main() {

    time_t timestamp = time(nullptr);   // marche bien

    Coordonnees coord(42.0, 42.0);
    Capteur capteur("capteurTest", "un test", coord);
    Type type("typeTest", "°C", "temperature test");
    Mesure mes(42.0, timestamp, "mesure test", capteur, type);

    // somehow
    MesureDAO dao("../Data/test.csv");

    dao.add(mes);

    return 0;
}