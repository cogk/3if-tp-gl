
/*************************************************************************
                           Expert  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Expert> (fichier Expert.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système

//------------------------------------------------------ Include personnel
#include "Expert.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

const Entreprise & Expert::getEntreprise() const {
    return entreprise;
}

void Expert::setEntreprise(const Entreprise &entreprise) {
    Expert::entreprise = entreprise;
}

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur

Expert::Expert ( )
{
#ifdef MAP
    cout << "Appel au constructeur de <Expert>" << endl;
#endif
} //----- Fin de Expert

Expert::Expert(const string &identifiant, const string &motDePasse, const string &email, const Entreprise &entreprise) :
    Utilisateur(identifiant, motDePasse, email),
    entreprise(entreprise)
{
#ifdef MAP
    cout << "Appel au constructeur de <Expert>" << endl;
#endif
} //----- Fin de Expert

Expert::~Expert ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Expert>" << endl;
#endif
} //----- Fin de ~Expert


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

