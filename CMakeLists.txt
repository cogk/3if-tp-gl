cmake_minimum_required(VERSION 3.14)
project(3if_gl-tp)

set(CMAKE_CXX_STANDARD 11)

# Crée des variables avec les fichiers à compiler
set(SRCS src/main.cpp src/App.cpp)
set(Metier src/Metier/Mesure.h src/Metier/Type.h src/Metier/Coordonnees.h src/Metier/Purificateur.h)
set(Services src/Services/ServiceContributeur.cpp src/Services/ServiceContributeur.h src/Services/ServiceAnalyste.cpp src/Services/ServiceAnalyste.h)
set(DAO src/DAO/MesureDAO.cpp src/DAO/MesureDAO.h)

# Notre exécutable
add_executable(main ${SRCS} ${DAO} ${Services} ${Metier})
