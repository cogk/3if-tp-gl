//
// Created by emman on 26/05/2020.
//

#include "DAO/MesureDAO.h"

#include <utility>
#include <ctime>
#include <map>
#include <math.h>
#include <iomanip>
#include <sstream>

int main() {

    time_t timestamp = time(nullptr);   // marche bien

    Coordonnees coord(42.0, 42.0);
    Capteur capteur("capteurTest", "un test", coord);
    Type type("typeTest", "°C", "temperature test");
    Mesure mes(42.0, timestamp, "mesure test", capteur, type);

    // somehow
    MesureDAO dao;

    dao.add(mes);

    tm tm1{};
    istringstream str_stream("2019-01-01 12:00:00");
    str_stream >> get_time(&tm1, "%Y-%m-%d %T");
    time_t debut = mktime(&tm1);

    tm tm2{};
    istringstream str_stream2("2019-01-08 12:00:10");
    str_stream >> get_time(&tm2, "%Y-%m-%d %T");
    time_t fin = mktime(&tm2);

    vector<Mesure*>* res = dao.list(Coordonnees(44.8, 1.1), 1000.0, debut, fin);
    for (Mesure *m : *res) {
        cout << m->getDate() << " / " << m->getCapteur().getSensorId() << " / " << m->getType().getAttributeId() << endl;
        delete m;
    }
    delete res;

    return 0;
}