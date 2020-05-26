
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
#include "Entreprise.h"

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

    const Entreprise &getEntreprise() const {
        return entreprise;
    }

    void setEntreprise(const Entreprise &entreprise) {
        Expert::entreprise = entreprise;
    }

//-------------------------------------------- Constructeurs - destructeur

    Expert() {}
    // Mode d'emploi :
    //
    // Contrat :
    //

    Expert(const string &identifiant, const string &motDePasse, const string &email, const Entreprise &entreprise)
            : Utilisateur(identifiant, motDePasse, email), entreprise(entreprise) {}
    // Mode d'emploi :
    //
    // Contrat :
    //

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
    Entreprise entreprise;

};

#endif // INC_3IF_GL_TP_EXPERT_H


