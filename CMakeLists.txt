cmake_minimum_required(VERSION 3.14)
project(3if_gl-tp)

set(CMAKE_CXX_STANDARD 11)

# pour le dossier courant
# si tout est cassé, enlever ça
#                               |
#                               v
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}")

# Crée des variables avec les fichiers à compiler
set(SRCS src/main.cpp src/App.cpp)
set(Metier src/Metier/Utilisateur.cpp src/Metier/SuperAdministrateur.cpp src/Metier/Administrateur.cpp src/Metier/Analyste.cpp src/Metier/Expert.cpp src/Metier/Contributeur.cpp src/Metier/Capteur.cpp src/Metier/Mesure.cpp src/Metier/Type.cpp src/Metier/Coordonnees.cpp src/Metier/Purificateur.cpp src/Metier/Organisation.cpp src/Metier/Agence.cpp src/Metier/Entreprise.cpp)
set(Services src/Services/ServiceContributeur.cpp src/Services/ServiceAnalyste.cpp)
set(DAO src/DAO/MesureDAO.cpp src/DAO/CSVParser.cpp src/DAO/CapteurDAO.cpp src/DAO/CapteurDAO.h src/DAO/TypeDAO.cpp src/DAO/ContributeurDAO.cpp)

set(test src/test.cpp src/DAO/MesureDAO.cpp src/DAO/CSVParser.cpp src/Metier/Mesure.h src/Metier/Mesure.cpp src/Metier/Coordonnees.cpp src/Metier/Capteur.cpp src/Metier/Type.cpp src/Metier/Administrateur.cpp src/Metier/Agence.cpp src/Metier/Organisation.cpp src/Metier/Utilisateur.cpp src/Metier/Analyste.cpp src/Metier/Contributeur.cpp src/Metier/Entreprise.cpp src/Metier/Expert.cpp src/Metier/SuperAdministrateur.cpp src/Metier/Purificateur.cpp src/DAO/CapteurDAO.cpp src/DAO/CapteurDAO.h src/DAO/TypeDAO.cpp src/DAO/ContributeurDAO.cpp src/Services/ServiceContributeur.cpp)

# Notre exécutable
add_executable(main ${SRCS} ${DAO} ${Services} ${Metier})
# ihm only
add_executable(app ${SRCS})
# tests
add_executable(test ${test})
