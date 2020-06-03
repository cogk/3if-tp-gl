//
// Created by emman on 03/06/2020.
//

#ifndef INC_3IF_GL_TP_TYPEDAO_H
#define INC_3IF_GL_TP_TYPEDAO_H

#include <vector>
#include <string>

#include "../Metier/Type.h"
#include "CSVParser.h"

class TypeDAO {

public:

    TypeDAO();

    virtual ~TypeDAO();

    vector<Type *> *list() const;

private:
    static const string typePath;
};


#endif //INC_3IF_GL_TP_TYPEDAO_H
