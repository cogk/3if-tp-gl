
/*************************************************************************
                           Entreprise  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Entreprise> (fichier Entreprise.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système

//------------------------------------------------------ Include personnel
#include "Entreprise.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

const vector<Purificateur> & Entreprise::getPurificateurs() const {
    return purificateurs;
}

void Entreprise::setPurificateurs(const vector<Purificateur> &purificateurs) {
    Entreprise::purificateurs = purificateurs;
}

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur

Entreprise::Entreprise ( )
{
#ifdef MAP
    cout << "Appel au constructeur de <Entreprise>" << endl;
#endif
} //----- Fin de Entreprise

Entreprise::Entreprise(const string &nom) :
    Organisation(nom)
{
#ifdef MAP
    cout << "Appel au constructeur de <Entreprise>" << endl;
#endif
} //----- Fin de Entreprise

Entreprise::Entreprise(const string &nom, const vector<Administrateur> &administrateur,
                       const vector<Purificateur> &purificateurs) :
   Organisation(nom, administrateur),
   purificateurs(purificateurs)
{
#ifdef MAP
    cout << "Appel au constructeur de <Entreprise>" << endl;
#endif
} //----- Fin de Entreprise

Entreprise::~Entreprise ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Entreprise>" << endl;
#endif
} //----- Fin de ~Entreprise


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

