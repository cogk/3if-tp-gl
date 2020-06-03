//
// Created by emman on 26/05/2020.
//

#ifndef INC_3IF_GL_TP_SERVICECONTRIBUTEUR_H
#define INC_3IF_GL_TP_SERVICECONTRIBUTEUR_H

#include <list>
#include "../Metier/Mesure.h"
#include "../Metier/Type.h"
#include "../DAO/ContributeurDAO.h"

class ServiceContributeur {

public:

    static bool envoyerDonnees(const Mesure& donnees);

    list<Capteur*>* getCapteurParUser(string& userID);

};


#endif //INC_3IF_GL_TP_SERVICECONTRIBUTEUR_H
