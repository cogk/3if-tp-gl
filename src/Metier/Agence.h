
/*************************************************************************
                           Agence  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Agence> (fichier Agence.h) ----------------
#if ! defined ( INC_3IF_GL_TP_AGENCE_H )
#define INC_3IF_GL_TP_AGENCE_H

//--------------------------------------------------- Interfaces utilisées
#include <iostream>
using namespace std;
#include "Organisation.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Agence>
//
//
//------------------------------------------------------------------------

class Agence : public Organisation
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques

//-------------------------------------------- Constructeurs - destructeur

    Agence();
    // Mode d'emploi :
    //
    // Contrat :
    //

    Agence(const string &nom);
    // Mode d'emploi :
    //
    // Contrat :
    //

    Agence(const string &nom, const vector<Administrateur> &administrateur);
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Agence();
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés

protected:

};

#endif // INC_3IF_GL_TP_AGENCE_H


