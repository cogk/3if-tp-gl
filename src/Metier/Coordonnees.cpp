
/*************************************************************************
                           Coordonnees  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Coordonnees> (fichier Coordonnees.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système

//------------------------------------------------------ Include personnel
#include "Coordonnees.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

double Coordonnees::getLattitude() const {
    return lattitude;
}

void Coordonnees::setLattitude(double lattitude) {
    Coordonnees::lattitude = lattitude;
}

double Coordonnees::getLongitude() const {
    return longitude;
}

void Coordonnees::setLongitude(double longitude) {
    Coordonnees::longitude = longitude;
}

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur

Coordonnees::Coordonnees ( )
{
#ifdef MAP
    cout << "Appel au constructeur de <Coordonnees>" << endl;
#endif
} //----- Fin de Coordonnees


Coordonnees::Coordonnees(double lattitude, double longitude) :
lattitude(lattitude),
longitude(longitude)
{
#ifdef MAP
    cout << "Appel au constructeur de <Coordonnees>" << endl;
#endif
} //----- Fin de Coordonnees

Coordonnees::~Coordonnees ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Coordonnees>" << endl;
#endif
} //----- Fin de ~Coordonnees


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

