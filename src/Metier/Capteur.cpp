
/*************************************************************************
                           Capteur  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Capteur> (fichier Capteur.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système

//------------------------------------------------------ Include personnel
#include "Capteur.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

const string & Capteur::getSensorId() const {
    return sensorID;
} //----- Fin de getSensorId

void Capteur::setSensorId(const string &sensorId) {
    sensorID = sensorId;
} //----- Fin de setSensorId

const string & Capteur::getDescription() const {
    return description;
} //----- Fin de getDescription

void Capteur::setDescription(const string &description) {
    Capteur::description = description;
} //----- Fin de setDescription

const Coordonnees & Capteur::getCoordonnees() const {
    return coordonnees;
} //----- Fin de getCoordonnees

void Capteur::setCoordonnees(const Coordonnees &coordonnees) {
    Capteur::coordonnees = coordonnees;
} //----- Fin de setCoordonnees


//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur

Capteur::Capteur ( )
{
#ifdef MAP
    cout << "Appel au constructeur de <Capteur>" << endl;
#endif
} //----- Fin de Capteur


Capteur::Capteur(const string &sensorId, const string &description, const Coordonnees &coordonnees) :
    sensorID(sensorId),
    description(description),
    coordonnees(coordonnees)
{
#ifdef MAP
cout << "Appel au constructeur de <Capteur>" << endl;
#endif
} //----- Fin de Capteur

Capteur::~Capteur ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Capteur>" << endl;
#endif
} //----- Fin de ~Capteur


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

