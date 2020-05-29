cmake_minimum_required(VERSION 3.14)
project(3if_gl-tp)

set(CMAKE_CXX_STANDARD 11)

# Crée des variables avec les fichiers à compiler
set(SRCS src/main.cpp src/App.cpp)
set(Metier src/Metier/Utilisateur.h src/Metier/SuperAdministrateur.h src/Metier/Administrateur.h src/Metier/Analyste.h src/Metier/Expert.h src/Metier/Contributeur.h src/Metier/Capteur.h src/Metier/Mesure.h src/Metier/Type.h src/Metier/Coordonnees.h src/Metier/Purificateur.h src/Metier/Organisation.h src/Metier/Agence.h src/Metier/Entreprise.h)
set(Services src/Services/ServiceContributeur.cpp src/Services/ServiceContributeur.h src/Services/ServiceAnalyste.cpp src/Services/ServiceAnalyste.h)
set(DAO src/DAO/MesureDAO.cpp src/DAO/MesureDAO.h)

set(test src/test.cpp src/DAO/MesureDAO.cpp src/DAO/CSVParser.cpp src/Metier/Mesure.h src/Metier/Mesure.cpp src/Metier/Coordonnees.cpp src/Metier/Capteur.cpp src/Metier/Type.cpp)

# Notre exécutable
add_executable(main ${SRCS} ${DAO} ${Services} ${Metier})
# ihm only
add_executable(app ${SRCS})
# tests
add_executable(test ${test})
