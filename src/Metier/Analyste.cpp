
/*************************************************************************
                           Analyste  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Analyste> (fichier Analyste.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système

//------------------------------------------------------ Include personnel
#include "Analyste.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

const Agence & Analyste::getAgence() const {
    return agence;
}

void Analyste::setAgence(const Agence &agence) {
    Analyste::agence = agence;
}

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur

Analyste::Analyste ( )
{
#ifdef MAP
    cout << "Appel au constructeur de <Analyste>" << endl;
#endif
} //----- Fin de Analyste




Analyste::Analyste(const string &identifiant, const string &motDePasse, const string &email, const Agence &agence) :
    Utilisateur(identifiant, motDePasse, email),
    agence(agence)
{
#ifdef MAP
    cout << "Appel au constructeur de <Analyste>" << endl;
#endif
} //----- Fin de Analyste

Analyste::~Analyste ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Analyste>" << endl;
#endif
} //----- Fin de ~Analyste


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

