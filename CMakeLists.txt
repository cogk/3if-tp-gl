cmake_minimum_required(VERSION 3.14)
project(3if_gl-tp)

set(CMAKE_CXX_STANDARD 11)

# Crée des variables avec les fichiers à compiler
set(SRCS src/main.cpp src/App.cpp src/Services/ServiceContributeur.cpp src/Services/ServiceContributeur.h src/Metier/Mesure.h src/Metier/Type.h src/Metier/Coordonnees.h src/Metier/Purificateur.h)

# Notre exécutable
add_executable(main ${SRCS})
