
/*************************************************************************
                           Analyste  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Analyste> (fichier Analyste.h) ----------------
#if ! defined ( INC_3IF_GL_TP_ANALYSTE_H )
#define INC_3IF_GL_TP_ANALYSTE_H

//--------------------------------------------------- Interfaces utilisées
#include <iostream>
using namespace std;
#include "Utilisateur.h"
#include "Agence.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Analyste>
//
//
//------------------------------------------------------------------------

class Analyste : public Utilisateur
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques

    const Agence &getAgence() const;

    void setAgence(const Agence &agence);

//-------------------------------------------- Constructeurs - destructeur

    Analyste();
    // Mode d'emploi :
    //
    // Contrat :
    //

    Analyste(const string &identifiant, const string &motDePasse, const string &email, const Agence &agence);
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Analyste();
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés

protected:
    Agence agence;

};

#endif // INC_3IF_GL_TP_ANALYSTE_H


