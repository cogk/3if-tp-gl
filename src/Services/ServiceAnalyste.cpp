//
// Created by emman on 26/05/2020.
//

#include "ServiceAnalyste.h"
#include "../DAO/MesureDAO.h"

#include <algorithm>
#include <vector>

map<Type, ServiceAnalyste::Resultats> *ServiceAnalyste::agregerDonnees(
    const Coordonnees &centre, double rayon,
    time_t debut, time_t fin,
    bool filtrerParDistance,
    bool filtrerParDate)
{

    MesureDAO mesureDao;
    vector<Mesure *> *res = mesureDao.list(centre, rayon, debut, fin, filtrerParDistance, filtrerParDate);

    // mapper les valeurs par type
    map<Type, vector<double>> valeursParType;
    for (const Mesure *mes : *res){
        // initialisation de la liste ? -> ptet pas (constr par def appelé)
        valeursParType[mes->getType()].push_back(mes->getValeur());
    }

    // mettre les resultats dans une map par type
    const double infty = std::numeric_limits<double>::infinity();
    auto resultats = new map<Type, ServiceAnalyste::Resultats>();
    for (const auto pair : valeursParType){

        auto v = pair.second;
        size_t count = v.size();
        double sum = 0.0;
        double max = -infty;
        double min = +infty;
        double mediane = 0;

        std::nth_element(v.begin(), v.begin() + v.size() / 2, v.end());
        mediane = v[v.size() / 2];

        for (auto it = v.begin(); it != v.end(); it++)
        {
            const double val = *it;

            sum += val;

            if (min > val)
                min = val;

            if (max < val)
                max = val;
        }

        (*resultats)[pair.first] = Resultats{sum / count, min, max, mediane};
    }

    return resultats;
}
