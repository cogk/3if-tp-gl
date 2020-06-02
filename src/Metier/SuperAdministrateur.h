
/*************************************************************************
                           SuperAdministrateur  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <SuperAdministrateur> (fichier SuperAdministrateur.h) ----------------
#if ! defined ( INC_3IF_GL_TP_SUPERADMINISTRATEUR_H )
#define INC_3IF_GL_TP_SUPERADMINISTRATEUR_H

//--------------------------------------------------- Interfaces utilisées
#include <iostream>
using namespace std;
#include "Utilisateur.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <SuperAdministrateur>
//
//
//------------------------------------------------------------------------

class SuperAdministrateur : public Utilisateur
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques

//-------------------------------------------- Constructeurs - destructeur

    SuperAdministrateur();
    // Mode d'emploi :
    //
    // Contrat :
    //

    SuperAdministrateur(const string &identifiant, const string &motDePasse, const string &email);
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~SuperAdministrateur();
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

#endif // INC_3IF_GL_TP_SUPERADMINISTRATEUR_H


