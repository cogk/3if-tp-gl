
/*************************************************************************
                           Capteur  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Capteur> (fichier Capteur.h) ----------------
#if ! defined ( INC_3IF_GL_TP_CAPTEUR_H )
#define INC_3IF_GL_TP_CAPTEUR_H

//--------------------------------------------------- Interfaces utilisées
#include <iostream>
#include "Coordonnees.h"

using namespace std;

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Capteur>
//
//
//------------------------------------------------------------------------

class Capteur
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques

    const string &getSensorId() const {
        return sensorID;
    }

    void setSensorId(const string &sensorId) {
        sensorID = sensorId;
    }

    const string &getDescription() const {
        return description;
    }

    void setDescription(const string &description) {
        Capteur::description = description;
    }

    const Coordonnees &getCoordonnees() const {
        return coordonnees;
    }

    void setCoordonnees(const Coordonnees &coordonnees) {
        Capteur::coordonnees = coordonnees;
    }

//-------------------------------------------- Constructeurs - destructeur

    Capteur();
    // Mode d'emploi :
    //
    // Contrat :
    //

    Capteur(const string &sensorId, const string &description, const Coordonnees &coordonnees) : sensorID(sensorId),
                                                                                                 description(
                                                                                                         description),
                                                                                                 coordonnees(
                                                                                                         coordonnees) {}
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Capteur();
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés

protected:
    std::string sensorID;
    std::string description;
    Coordonnees coordonnees;

};

#endif // INC_3IF_GL_TP_CAPTEUR_H


