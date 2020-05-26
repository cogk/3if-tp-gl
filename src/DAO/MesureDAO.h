//
// Created by emman on 26/05/2020.
//

#ifndef INC_3IF_GL_TP_MESUREDAO_H
#define INC_3IF_GL_TP_MESUREDAO_H

#include <vector>


class MesureDAO {


public:
    MesureDAO();

    bool add(Mesure mesure);

    vector<Mesure> list(Capteur, Coordonnees, Type, Date, Date);

    void clean();

private:

    vector<Mesure> objetsRencontres;

};


#endif //INC_3IF_GL_TP_MESUREDAO_H
