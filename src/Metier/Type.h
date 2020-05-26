
/*************************************************************************
                           Type  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Type> (fichier Type.h) ----------------
#if ! defined ( INC_3IF_GL_TP_TYPE_H )
#define INC_3IF_GL_TP_TYPE_H

//--------------------------------------------------- Interfaces utilisées
#include <iostream>
using namespace std;

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Type>
//
//
//------------------------------------------------------------------------

class Type
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques

    const string &getAttributeId() const {
        return attributeID;
    }

    void setAttributeId(const string &attributeId) {
        attributeID = attributeId;
    }

    const string &getUnite() const {
        return unite;
    }

    void setUnite(const string &unite) {
        Type::unite = unite;
    }

    const string &getDescription() const {
        return description;
    }

    void setDescription(const string &description) {
        Type::description = description;
    }

//-------------------------------------------- Constructeurs - destructeur

    Type();
    // Mode d'emploi :
    //
    // Contrat :
    //

    Type(const string &attributeId, const string &unite, const string &description) : attributeID(attributeId),
                                                                                      unite(unite),
                                                                                      description(description) {}
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Type();
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés

protected:
    std::string attributeID;
    std::string unite;
    std::string description;

};

#endif // INC_3IF_GL_TP_TYPE_H


