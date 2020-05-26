
/*************************************************************************
                           Utilisateur  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Utilisateur> (fichier Utilisateur.h) ----------------
#if ! defined ( INC_3IF_GL_TP_UTILISATEUR_H )
#define INC_3IF_GL_TP_UTILISATEUR_H

//--------------------------------------------------- Interfaces utilisées
#include <iostream>
using namespace std;

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Utilisateur>
//
//
//------------------------------------------------------------------------

class Utilisateur
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques

    const string &getIdentifiant() const {
        return identifiant;
    }

    void setIdentifiant(const string &identifiant) {
        Utilisateur::identifiant = identifiant;
    }

    const string &getMotDePasse() const {
        return motDePasse;
    }

    void setMotDePasse(const string &motDePasse) {
        Utilisateur::motDePasse = motDePasse;
    }

    const string &getEmail() const {
        return email;
    }

    void setEmail(const string &email) {
        Utilisateur::email = email;
    }

//-------------------------------------------- Constructeurs - destructeur

    Utilisateur();
    // Mode d'emploi :
    //
    // Contrat :
    //

    Utilisateur(const string &identifiant, const string &motDePasse, const string &email) : identifiant(identifiant),
                                                                                            motDePasse(motDePasse),
                                                                                            email(email) {}
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Utilisateur();
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés

protected:
    std::string identifiant;
    std::string motDePasse;
    std::string email;

};

#endif // INC_3IF_GL_TP_UTILISATEUR_H


