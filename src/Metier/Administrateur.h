
/*************************************************************************
                           Administrateur  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Administrateur> (fichier Administrateur.h) ----------------
#if ! defined ( INC_3IF_GL_TP_ADMINISTRATEUR_H )
#define INC_3IF_GL_TP_ADMINISTRATEUR_H

//--------------------------------------------------- Interfaces utilisées
#include <iostream>
using namespace std;
#include "Utilisateur.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Administrateur>
//
//
//------------------------------------------------------------------------

class Administrateur : public Utilisateur
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques



//-------------------------------------------- Constructeurs - destructeur

    Administrateur() {}
    // Mode d'emploi :
    //
    // Contrat :
    //

    Administrateur(const string &identifiant, const string &motDePasse, const string &email) : Utilisateur(identifiant,
                                                                                                     motDePasse, email) {}

    virtual ~Administrateur() {}
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

#endif // INC_3IF_GL_TP_ADMINISTRATEUR_H


