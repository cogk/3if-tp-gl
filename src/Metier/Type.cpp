
/*************************************************************************
                           Type  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Type> (fichier Type.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système

//------------------------------------------------------ Include personnel
#include "Type.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

const string & Type::getAttributeId() const {
    return attributeID;
}

void Type::setAttributeId(const string &attributeId) {
    attributeID = attributeId;
}

const string & Type::getUnite() const {
    return unite;
}

void Type::setUnite(const string &unite) {
    Type::unite = unite;
}

const string & Type::getDescription() const {
    return description;
}

void Type::setDescription(const string &description) {
    Type::description = description;
}

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur

Type::Type ( )
{
#ifdef MAP
    cout << "Appel au constructeur de <Type>" << endl;
#endif
} //----- Fin de Type


Type::Type(const string &attributeId, const string &unite, const string &description) :
    attributeID(attributeId),
    unite(unite),
    description(description)
{
#ifdef MAP
    cout << "Appel au constructeur de <Type>" << endl;
#endif
} //----- Fin de Type

Type::~Type ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Type>" << endl;
#endif
}

bool Type::operator<(const Type &type) {
    return (attributeID < type.getAttributeId());
}

bool operator<(const Type &t1, const Type &t2) {
    return t1.getAttributeId() < t2.getAttributeId();
}
//----- Fin de ~Type


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

