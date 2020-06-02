
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

    const string &getIdentifiant() const;

    void setIdentifiant(const string &identifiant);

    const string &getMotDePasse() const;

    void setMotDePasse(const string &motDePasse);

    const string &getEmail() const;

    void setEmail(const string &email);

//-------------------------------------------- Constructeurs - destructeur

    Utilisateur();
    // Mode d'emploi :
    //
    // Contrat :
    //

    Utilisateur(const string &identifiant, const string &motDePasse, const string &email);
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


