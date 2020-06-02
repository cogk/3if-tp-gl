
/*************************************************************************
                           Administrateur  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Administrateur> (fichier Administrateur.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système

//------------------------------------------------------ Include personnel
#include "Administrateur.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur

Administrateur::Administrateur ( )
{
#ifdef MAP
    cout << "Appel au constructeur de <Administrateur>" << endl;
#endif
} //----- Fin de Administrateur



Administrateur::Administrateur(const string &identifiant, const string &motDePasse, const string &email) :
    Utilisateur(identifiant, motDePasse, email)
{
#ifdef MAP
    cout << "Appel au constructeur de <Administrateur>" << endl;
#endif
} //----- Fin de Administrateur

Administrateur::~Administrateur ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Administrateur>" << endl;
#endif
} //----- Fin de ~Administrateur


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

