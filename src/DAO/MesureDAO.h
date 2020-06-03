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
    // TODO ref pas ref ?
    MesureDAO();

    ~MesureDAO();

    // TODO passer en static ?
    bool add(const Mesure& mesure);

    vector<Mesure *> *list(Coordonnees, double, time_t, time_t, bool = true, bool = true);

    void clean();

private:
    static const string mesurePath;
    static const string capteurPath;
    static const string typePath;
    static const string testPath;
};


#endif //INC_3IF_GL_TP_MESUREDAO_H
