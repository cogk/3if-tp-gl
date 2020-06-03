//
// Created by emman on 03/06/2020.
//

#ifndef INC_3IF_GL_TP_CAPTEURDAO_H
#define INC_3IF_GL_TP_CAPTEURDAO_H

#include <vector>

#include "../Metier/Capteur.h"
#include "CSVParser.h"

class CapteurDAO {

public:

    CapteurDAO();

    virtual ~CapteurDAO();

    vector<Capteur *> *list();

};


#endif //INC_3IF_GL_TP_CAPTEURDAO_H
