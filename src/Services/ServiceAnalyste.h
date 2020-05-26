//
// Created by emman on 26/05/2020.
//

#ifndef INC_3IF_GL_TP_SERVICEANALYSTE_H
#define INC_3IF_GL_TP_SERVICEANALYSTE_H

#include <map>
#include "../Metier/Coordonnees.h"
#include "../Metier/Type.h"

class ServiceAnalyste {

public:
    map<Type, double> agregerDonnees(Coordonnees centre, double rayon, time_t debut, time_t fin);

};


#endif //INC_3IF_GL_TP_SERVICEANALYSTE_H
