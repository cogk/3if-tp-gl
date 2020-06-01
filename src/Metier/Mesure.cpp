
/*************************************************************************
                           Mesure  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Mesure> (fichier Mesure.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système

//------------------------------------------------------ Include personnel
#include "Mesure.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

double Mesure::getValeur() const {
    return valeur;
}

void Mesure::setValeur(double valeur) {
    Mesure::valeur = valeur;
}

time_t Mesure::getDate() const {
    return date;
}

void Mesure::setDate(time_t date) {
    Mesure::date = date;
}

const string & Mesure::getDescription() const {
    return description;
}

void Mesure::setDescription(const string &description) {
    Mesure::description = description;
}

const Capteur &Mesure::getCapteur() const {
    return capteur;
}

void Mesure::setCapteur(const Capteur &capteur) {
    Mesure::capteur = capteur;
}

const Type &Mesure::getType() const {
    return type;
}

void Mesure::setType(const Type &type) {
    Mesure::type = type;
}

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur

Mesure::Mesure ( )
{
#ifdef MAP
    cout << "Appel au constructeur de <Mesure>" << endl;
#endif
} //----- Fin de Mesure



Mesure::Mesure(double valeur, time_t date, const string &description, const Capteur &capteur, const Type &type) :
    valeur(valeur),
    date(date),
    description(description),
    capteur(capteur),
    type(type)
{
#ifdef MAP
    cout << "Appel au constructeur de <Mesure>" << endl;
#endif
} //----- Fin de Mesure

Mesure::~Mesure ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Mesure>" << endl;
#endif
} //----- Fin de ~Mesure


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

