
/*************************************************************************
                           Expert  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Expert> (fichier Expert.h) ----------------
#if ! defined ( INC_3IF_GL_TP_EXPERT_H )
#define INC_3IF_GL_TP_EXPERT_H

//--------------------------------------------------- Interfaces utilisées
#include <iostream>
using namespace std;
#include "Utilisateur.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Expert>
//
//
//------------------------------------------------------------------------

class Expert : public Utilisateur
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques



//-------------------------------------------- Constructeurs - destructeur

    Expert() {}
    // Mode d'emploi :
    //
    // Contrat :
    //

    Expert(const string &identifiant, const string &motDePasse, const string &email) : Utilisateur(identifiant,
                                                                                                   motDePasse, email) {}

    virtual ~Expert() {}
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

#endif // INC_3IF_GL_TP_EXPERT_H


