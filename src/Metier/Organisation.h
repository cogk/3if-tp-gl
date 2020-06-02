
/*************************************************************************
                           Organisation  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Organisation> (fichier Organisation.h) ----------------
#if ! defined ( INC_3IF_GL_TP_ORGANISATION_H )
#define INC_3IF_GL_TP_ORGANISATION_H

//--------------------------------------------------- Interfaces utilisées
#include <iostream>
#include <vector>
#include "Administrateur.h"

using namespace std;

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Organisation>
//
//
//------------------------------------------------------------------------

class Organisation
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques

    const string &getNom() const;

    void setNom(const string &nom);

    const vector<Administrateur> &getAdministrateur() const;

    void setAdministrateur(const vector<Administrateur> &administrateur);

//-------------------------------------------- Constructeurs - destructeur

    Organisation();
    // Mode d'emploi :
    //
    // Contrat :
    //


    Organisation(const string &nom);
    // Mode d'emploi :
    //
    // Contrat :
    //

    Organisation(const string &nom, const vector<Administrateur> &administrateur);
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Organisation();
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés

protected:
    std::string nom;
    vector<Administrateur> administrateur;

};

#endif // INC_3IF_GL_TP_ORGANISATION_H
