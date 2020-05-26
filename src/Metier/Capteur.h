
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

//-------------------------------------------- Constructeurs - destructeur

    Capteur();
    // Mode d'emploi :
    //
    // Contrat :
    //

    Capteur(const string &sensorId, const string &description) : sensorID(sensorId), description(description) {}
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

};

#endif // INC_3IF_GL_TP_CAPTEUR_H


