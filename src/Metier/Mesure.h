
/*************************************************************************
                           Mesure  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Mesure> (fichier Mesure.h) ----------------
#if ! defined ( INC_3IF_GL_TP_MESURE_H )
#define INC_3IF_GL_TP_MESURE_H

//--------------------------------------------------- Interfaces utilisées
#include <iostream>
#include <ctime>
#include "Capteur.h"
#include "Type.h"

using namespace std;

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Mesure>
//
//
//------------------------------------------------------------------------

class Mesure
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques

    double getValeur() const;

    void setValeur(double valeur);

    time_t getDate() const;

    void setDate(time_t date);

    const string &getDescription() const;

    void setDescription(const string &description);

    const Capteur &getCapteur() const;

    void setCapteur(const Capteur &capteur);

    const Type &getType() const;

    void setType(const Type &type);

//-------------------------------------------- Constructeurs - destructeur

    Mesure();
    // Mode d'emploi :
    //
    // Contrat :
    //

    Mesure(double valeur, time_t date, const string &description, const Capteur &capteur, const Type &type);
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Mesure();
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés

protected:
    double valeur;
    time_t date;
    std::string description;
    Capteur capteur;
    Type type;

};

#endif // INC_3IF_GL_TP_MESURE_H


