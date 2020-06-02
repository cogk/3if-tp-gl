
/*************************************************************************
                           Agence  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Agence> (fichier Agence.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système

//------------------------------------------------------ Include personnel
#include "Agence.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur

Agence::Agence ( ) :
    Organisation()
{
#ifdef MAP
    cout << "Appel au constructeur de <Agence>" << endl;
#endif
} //----- Fin de Agence


Agence::Agence(const string &nom) :
    Organisation(nom)
{
#ifdef MAP
    cout << "Appel au constructeur de <Agence>" << endl;
#endif
} //----- Fin de Agence


Agence::Agence(const string &nom, const vector<Administrateur> &administrateur) :
    Organisation(nom, administrateur)
{
#ifdef MAP
    cout << "Appel au constructeur de <Agence>" << endl;
#endif
} //----- Fin de Agence

Agence::~Agence ( )
{
#ifdef MAP
    cout << "Appel au destructeur de <Agence>" << endl;
#endif
} //----- Fin de ~Agence


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

