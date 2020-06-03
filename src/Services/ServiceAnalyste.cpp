//
// Created by emman on 26/05/2020.
//

#include "ServiceAnalyste.h"
#include "../DAO/MesureDAO.h"
#include "../DAO/TypeDAO.h"

#include <algorithm>
#include <math.h>
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
    for (const Mesure *mes : *res)
    {
        // initialisation de la liste ? -> ptet pas (constr par def appelé)
        valeursParType[mes->getType()].push_back(mes->getValeur());
    }

    // mettre les resultats dans une map par type
    const double infty = std::numeric_limits<double>::infinity();
    auto resultats = new map<Type, ServiceAnalyste::Resultats>();
    for (const auto pair : valeursParType)
    {

        auto v = pair.second;
        size_t count = v.size();

        std::nth_element(v.begin(), v.begin() + v.size() / 2, v.end());
        double mediane = v[v.size() / 2];

        double sum = 0.0;
        double sumSquared = 0.0;
        double max = -infty;
        double min = +infty;

        for (auto it = v.begin(); it != v.end(); it++)
        {
            const double val = *it;

            sum += val;
            sumSquared += val * val;

            if (min > val)
                min = val;

            if (max < val)
                max = val;
        }

        double moyenne = sum / count;
        double ecartType = sqrt(sumSquared / count - moyenne * moyenne);

        (*resultats)[pair.first] = Resultats{moyenne, min, max, mediane, ecartType};
    }

    return resultats;
}

vector<Type*> *ServiceAnalyste::listType() {
    return TypeDAO().list();
}
