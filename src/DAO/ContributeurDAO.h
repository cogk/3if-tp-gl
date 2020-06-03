#ifndef INC_3IF_GL_TP_CONTRIBUTEURDAO_H
#define INC_3IF_GL_TP_CONTRIBUTEURDAO_H

#include <vector>
#include <string>
#include "../Metier/Coordonnees.h"
#include "../Metier/Capteur.h"
#include "CSVParser.h"
#include "../Metier/Contributeur.h"

class ContributeurDAO {

public:

    ContributeurDAO();

    virtual ~ContributeurDAO();

    Contributeur *getContributeur(const string &id);

private:
    static const string contributeurPath;
    static const string capteurPath;
};


#endif //INC_3IF_GL_TP_ContributeurDAO_H
