//
// Created by emman on 26/05/2020.
//

#ifndef INC_3IF_GL_TP_SERVICECONTRIBUTEUR_H
#define INC_3IF_GL_TP_SERVICECONTRIBUTEUR_H

#include <list>
#include <vector>
#include "../Metier/Mesure.h"
#include "../Metier/Type.h"
#include "../Metier/Contributeur.h"

class ServiceContributeur {

public:

    static bool envoyerDonnees(const Mesure& donnees);

    static Contributeur* getContributeur(const string& userID);

    static vector<string*>* listUsers();

};


#endif //INC_3IF_GL_TP_SERVICECONTRIBUTEUR_H
