//
// Created by emman on 26/05/2020.
//

#ifndef INC_3IF_GL_TP_SERVICECONTRIBUTEUR_H
#define INC_3IF_GL_TP_SERVICECONTRIBUTEUR_H

#include "../Metier/Mesure.h"

class ServiceContributeur {

public:

    bool envoyerDonnees(const Mesure& donnees);

private:

    const string cheminMesuresCSV = "../../Data/test.csv";
};


#endif //INC_3IF_GL_TP_SERVICECONTRIBUTEUR_H
