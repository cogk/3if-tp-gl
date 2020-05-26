
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
#include <vector>
using namespace std;
#include "Utilisateur.h"
#include "Capteur.h"

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

    const vector<Capteur> &getCapteurs() const {
        return capteurs;
    }

    void setCapteurs(const vector<Capteur> &capteurs) {
        Contibuteur::capteurs = capteurs;
    }

//-------------------------------------------- Constructeurs - destructeur

    Contibuteur() {}
    // Mode d'emploi :
    //
    // Contrat :
    //

    Contibuteur(const string &identifiant, const string &motDePasse, const string &email, int points, int fiabilite,
                const vector<Capteur> &capteurs) : Utilisateur(identifiant, motDePasse, email), points(points),
                                                   fiabilite(fiabilite), capteurs(capteurs) {}
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
    vector<Capteur> capteurs;

};

#endif // INC_3IF_GL_TP_CONTRIBUTEUR_H


