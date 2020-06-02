
/*************************************************************************
                           Entreprise  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Entreprise> (fichier Entreprise.h) ----------------
#if ! defined ( INC_3IF_GL_TP_ENTREPRISE_H )
#define INC_3IF_GL_TP_ENTREPRISE_H

//--------------------------------------------------- Interfaces utilisées
#include <iostream>
#include <vector>
using namespace std;
#include "Organisation.h"
#include "Purificateur.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Entreprise>
//
//
//------------------------------------------------------------------------

class Entreprise : public Organisation
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques

    const vector<Purificateur> &getPurificateurs() const;

    void setPurificateurs(const vector<Purificateur> &purificateurs);

//-------------------------------------------- Constructeurs - destructeur

    Entreprise();
    // Mode d'emploi :
    //
    // Contrat :
    //

    Entreprise(const string &nom);
    // Mode d'emploi :
    //
    // Contrat :
    //

    Entreprise(const string &nom, const vector<Administrateur> &administrateur,
               const vector<Purificateur> &purificateurs);
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Entreprise();
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés

protected:
    vector<Purificateur> purificateurs;

};

#endif // INC_3IF_GL_TP_ENTREPRISE_H


