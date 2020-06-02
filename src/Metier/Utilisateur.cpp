
/*************************************************************************
                           Utilisateur  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Utilisateur> (fichier Utilisateur.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système

//------------------------------------------------------ Include personnel
#include "Utilisateur.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

const string & Utilisateur::getIdentifiant() const {
    return identifiant;
}

void Utilisateur::setIdentifiant(const string &identifiant) {
    Utilisateur::identifiant = identifiant;
}

const string & Utilisateur::getMotDePasse() const {
    return motDePasse;
}

void Utilisateur::setMotDePasse(const string &motDePasse) {
    Utilisateur::motDePasse = motDePasse;
}

const string & Utilisateur::getEmail() const {
    return email;
}

void Utilisateur::setEmail(const string &email) {
    Utilisateur::email = email;
}

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur

Utilisateur::Utilisateur ( )
{
#ifdef MAP
    cout << "Appel au constructeur de <Utilisateur>" << endl;
#endif
} //----- Fin de Utilisateur




Utilisateur::Utilisateur(const string &identifiant, const string &motDePasse, const string &email) :
    identifiant(identifiant),
    motDePasse(motDePasse),
    email(email)
{
#ifdef MAP
    cout << "Appel au constructeur de <Utilisateur>" << endl;
#endif
} //----- Fin de Utilisateur

Utilisateur::~Utilisateur ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Utilisateur>" << endl;
#endif
} //----- Fin de ~Utilisateur


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

