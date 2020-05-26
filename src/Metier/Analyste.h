
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



//-------------------------------------------- Constructeurs - destructeur

    Analyste() {}
    // Mode d'emploi :
    //
    // Contrat :
    //

    Analyste(const string &identifiant, const string &motDePasse, const string &email) : Utilisateur(identifiant,
                                                                                                   motDePasse, email) {}

    virtual ~Analyste() {}
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

#endif // INC_3IF_GL_TP_ANALYSTE_H


