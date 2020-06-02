
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

    friend  bool operator<(const Type& t1, const Type& t2);

    const string &getAttributeId() const;

    void setAttributeId(const string &attributeId);

    const string &getUnite() const;

    void setUnite(const string &unite);

    const string &getDescription() const;

    void setDescription(const string &description);

    bool operator<(const Type& type);

//-------------------------------------------- Constructeurs - destructeur

    Type();
    // Mode d'emploi :
    //
    // Contrat :
    //

    Type(const string &attributeId, const string &unite, const string &description);
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


