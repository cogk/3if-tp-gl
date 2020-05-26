
/*************************************************************************
                           Contributeur  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Contibuteur> (fichier Contibuteur.h) ----------------
#if ! defined ( INC_3IF_GL_TP_CONTRIBUTEUR_H )
#define INC_3IF_GL_TP_CONTRIBUTEUR_H

//--------------------------------------------------- Interfaces utilisées
#include <iostream>
using namespace std;
#include "Utilisateur.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Contibuteur>
//
//
//------------------------------------------------------------------------

class Contibuteur : public Utilisateur
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques



//-------------------------------------------- Constructeurs - destructeur

    Contibuteur() {}
    // Mode d'emploi :
    //
    // Contrat :
    //

    Contibuteur(const string &identifiant, const string &motDePasse, const string &email, int points, int fiabilite)
            : Utilisateur(identifiant, motDePasse, email), points(points), fiabilite(fiabilite) {}
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Contibuteur() {}
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés

protected:
    int points;
    int fiabilite;

};

#endif // INC_3IF_GL_TP_CONTRIBUTEUR_H


