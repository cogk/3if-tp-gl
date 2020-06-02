
/*************************************************************************
                           Purificateur  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Purificateur> (fichier Purificateur.h) ----------------
#if ! defined ( INC_3IF_GL_TP_PURIFICATEUR_H )
#define INC_3IF_GL_TP_PURIFICATEUR_H

//--------------------------------------------------- Interfaces utilisées
#include <iostream>
#include "Coordonnees.h"

using namespace std;

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Purificateur>
//
//
//------------------------------------------------------------------------

class Purificateur
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques

    void setCoordonnees(const Coordonnees &coordonnees);
    // Mode d'emploi :
    //
    // Contrat :
    //

    const Coordonnees &getCoordonnees() const;
    // Mode d'emploi :
    //
    // Contrat :
    //

//-------------------------------------------- Constructeurs - destructeur

    Purificateur();
    // Mode d'emploi :
    //
    // Contrat :
    //

    Purificateur(const Coordonnees &coordonnees);
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Purificateur();
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés

protected:
    Coordonnees coordonnees;

};

#endif // INC_3IF_GL_TP_PURIFICATEUR_H


