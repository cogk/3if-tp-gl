//
// Created by emman on 26/05/2020.
//

#include "ServiceContributeur.h"
#include "../../src/DAO/MesureDAO.h"

bool ServiceContributeur::envoyerDonnees(const Mesure& donnees) {

    MesureDAO dao(cheminMesuresCSV);
    return dao.add(donnees);

}