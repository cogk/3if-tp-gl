#ifndef INC_3IF_GL_TP_UTILISATEURDAO_H
#define INC_3IF_GL_TP_UTILISATEURDAO_H

#include <vector>
#include "../Metier/Utilisateur.h"

class UtilisateurDAO {
public:

    UtilisateurDAO();

    virtual ~UtilisateurDAO();

    vector<Utilisateur*> *list();

private:
    static const string utilisateurPath;
};


#endif //INC_3IF_GL_TP_UTILISATEURDAO_H
