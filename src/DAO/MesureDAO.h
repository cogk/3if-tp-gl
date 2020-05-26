//
// Created by emman on 26/05/2020.
//

#ifndef INC_3IF_GL_TP_MESUREDAO_H
#define INC_3IF_GL_TP_MESUREDAO_H

#include <vector>
#include <ctime>
#include <sstream>
#include "../Metier/Mesure.h"
#include "../Metier/Coordonnees.h"
#include "../Metier/Type.h"
#include "../Metier/Capteur.h"
#include "CSVParser.h"


class MesureDAO {

public:
    MesureDAO();

    // TODO peut-être changer time_t en classe qui l'encapsule pour avoir le bon format en string

    bool add(Mesure mesure);

    vector<Mesure> list(Capteur, Coordonnees, Type, time_t, time_t);

    void clean();

private:

    vector<Mesure> objetsRencontres;

};


#endif //INC_3IF_GL_TP_MESUREDAO_H
