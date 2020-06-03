//
// Created by emman on 26/05/2020.
//

#ifndef INC_3IF_GL_TP_SERVICEANALYSTE_H
#define INC_3IF_GL_TP_SERVICEANALYSTE_H

#include "../Metier/Coordonnees.h"
#include "../Metier/Type.h"
#include <map>

class ServiceAnalyste
{
public:
    struct Resultats
    {
        double moyenne;
        double min;
        double max;
        double mediane;
    };

    static map<Type, Resultats> *agregerDonnees(const Coordonnees &centre, double rayon, time_t debut, time_t fin, bool = true, bool = true);
};

#endif //INC_3IF_GL_TP_SERVICEANALYSTE_H
