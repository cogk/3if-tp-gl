
/*************************************************************************
                           Coordonnees  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Coordonnees> (fichier Coordonnees.h) ----------------
#if ! defined ( INC_3IF_GL_TP_COORDONNEES_H )
#define INC_3IF_GL_TP_COORDONNEES_H

//--------------------------------------------------- Interfaces utilisées
#include <iostream>
using namespace std;

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Coordonnees>
//
//
//------------------------------------------------------------------------

class Coordonnees
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques

    double getLattitude() const {
        return lattitude;
    }

    void setLattitude(double lattitude) {
        Coordonnees::lattitude = lattitude;
    }

    double getLongitude() const {
        return longitude;
    }

    void setLongitude(double longitude) {
        Coordonnees::longitude = longitude;
    }

//-------------------------------------------- Constructeurs - destructeur

    Coordonnees();
    // Mode d'emploi :
    //
    // Contrat :
    //

    Coordonnees(double lattitude, double longitude) : lattitude(lattitude), longitude(longitude) {}
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Coordonnees();
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés

protected:
    double lattitude;
    double longitude;

};

#endif // INC_3IF_GL_TP_COORDONNEES_H


