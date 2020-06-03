#include "TypeDAO.h"

const string TypeDAO::typePath = "./Data/attributes.csv";

TypeDAO::TypeDAO() {}

TypeDAO::~TypeDAO() {}

vector<Type*> *TypeDAO::list() const {
    CSVParser parser(typePath);

    vector<vector<string*>*> *types = parser.readVec();
    vector<Type*> *retour = new vector<Type*>();

    for (vector<string*> *linePtr : *types) {
        vector<string*> &line = *linePtr;
        retour->push_back(new Type(*line[0], *line[1], *line[2]));

        // for (string *str: *linePtr) {
        //     delete str;
        // }
        // delete linePtr;
    }
    
    for (auto i = types->begin(); i != types->end(); i++)
    {
        for (auto j = (*i)->begin(); j != (*i)->end(); j++)
        {
            delete *j;
        }
        delete *i;
    }
    delete types;

    return retour;
}
