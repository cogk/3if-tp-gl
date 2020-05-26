
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

    double getValeur() const {
        return valeur;
    }

    void setValeur(double valeur) {
        Mesure::valeur = valeur;
    }

    time_t getDate() const {
        return date;
    }

    void setDate(time_t date) {
        Mesure::date = date;
    }

    const string &getDescription() const {
        return description;
    }

    void setDescription(const string &description) {
        Mesure::description = description;
    }

//-------------------------------------------- Constructeurs - destructeur

    Mesure();
    // Mode d'emploi :
    //
    // Contrat :
    //

    Mesure(double valeur, time_t date, const string &description) : valeur(valeur), date(date),
                                                                    description(description) {}
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

};

#endif // INC_3IF_GL_TP_MESURE_H


