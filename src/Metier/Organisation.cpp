
/*************************************************************************
                           Organisation  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Organisation> (fichier Organisation.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système

//------------------------------------------------------ Include personnel
#include "Organisation.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

const string & Organisation::getNom() const {
    return nom;
}

void Organisation::setNom(const string &nom) {
    Organisation::nom = nom;
}

const vector<Administrateur> & Organisation::getAdministrateur() const {
    return administrateur;
}

void Organisation::setAdministrateur(const vector<Administrateur> &administrateur) {
    Organisation::administrateur = administrateur;
}

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur

Organisation::Organisation ( )
{
#ifdef MAP
    cout << "Appel au constructeur de <Organisation>" << endl;
#endif
} //----- Fin de Organisation

Organisation::Organisation(const string &nom) :
        nom(nom)
{
#ifdef MAP
    cout << "Appel au constructeur de <Organisation>" << endl;
#endif
} //----- Fin de Organisation

Organisation::Organisation(const string &nom, const vector<Administrateur> &administrateur) :
    nom(nom),
    administrateur(administrateur)
{
#ifdef MAP
    cout << "Appel au constructeur de <Organisation>" << endl;
#endif
} //----- Fin de Organisation

Organisation::~Organisation ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Organisation>" << endl;
#endif
} //----- Fin de ~Organisation


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

