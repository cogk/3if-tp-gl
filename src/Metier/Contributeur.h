
/*************************************************************************
                           Contributeur  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Contributeur> (fichier Contributeur.h) ----------------
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
// Rôle de la classe <Contributeur>
//
//
//------------------------------------------------------------------------

class Contributeur : public Utilisateur
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques

    const vector<Capteur> &getCapteurs() const;

    void addCapteur(Capteur capteur);

//-------------------------------------------- Constructeurs - destructeur

    Contributeur();
    // Mode d'emploi :
    //
    // Contrat :
    //

    Contributeur(const string &identifiant, const string &motDePasse, const string &email, int points, int fiabilite);
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Contributeur();
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
