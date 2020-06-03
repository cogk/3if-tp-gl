//
// Created by emman on 26/05/2020.
//

#ifndef INC_3IF_GL_TP_SERVICECONTRIBUTEUR_H
#define INC_3IF_GL_TP_SERVICECONTRIBUTEUR_H

#include "../Metier/Mesure.h"
#include "../Metier/Type.h"

class ServiceContributeur {

public:

    static bool envoyerDonnees(const Mesure& donnees);

};


#endif //INC_3IF_GL_TP_SERVICECONTRIBUTEUR_H
