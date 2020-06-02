
/*************************************************************************
                           SuperAdministrateur  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <SuperAdministrateur> (fichier SuperAdministrateur.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système

//------------------------------------------------------ Include personnel
#include "SuperAdministrateur.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur

SuperAdministrateur::SuperAdministrateur ( )
{
#ifdef MAP
    cout << "Appel au constructeur de <SuperAdministrateur>" << endl;
#endif
} //----- Fin de SuperAdministrateur

SuperAdministrateur::SuperAdministrateur(const string &identifiant, const string &motDePasse, const string &email) :
    Utilisateur(identifiant, motDePasse, email)
{
#ifdef MAP
    cout << "Appel au constructeur de <SuperAdministrateur>" << endl;
#endif
} //----- Fin de SuperAdministrateur

SuperAdministrateur::~SuperAdministrateur ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <SuperAdministrateur>" << endl;
#endif
} //----- Fin de ~SuperAdministrateur


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

