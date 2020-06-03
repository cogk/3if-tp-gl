#ifndef INC_3IF_GL_TP_CONTRIBUTEURDAO_H
#define INC_3IF_GL_TP_CONTRIBUTEURDAO_H

#include <vector>
#include "../Metier/Contributeur.h"

class ContributeurDAO {
public:

    ContributeurDAO();

    virtual ~ContributeurDAO();

//    vector<Contributeur*> *list();

    Contributeur *getContributeur(const string &id);

    vector<string*>* getUsernames();

private:
    static const string contributeurPath;
    static const string capteurPath;
};


#endif //INC_3IF_GL_TP_ContributeurDAO_H
