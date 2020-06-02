#include <iomanip>
#include <iostream>
#include <stdexcept>
#include <string>
#include <time.h>
#include <vector>

#include "App.h"
#include "Metier/Capteur.h"
#include "Metier/Coordonnees.h"
#include "Metier/Mesure.h"
#include "Metier/Type.h"
#include "Services/ServiceContributeur.h"

// Définition des menus
bool App::MenuPrincipal()
{
    this->banner("Bienvenue dans AirWatcher");
    this->userbar("(anonyme)");

    // Tous les menus
    const std::vector<std::string>
        menuPrincipal = {"Contribution…", "Analyse…", "Sources de données…", "Administration…", "Super Admin…", "Quitter AirWatcher"};

    while (true)
    {
        const int choice = this->menu("Menu Principal", menuPrincipal);
        switch (choice)
        {
        case 0:
            this->MenuContributeur();
            break;
        case 1:
            this->MenuAnalyste();
            break;
        case 2:
            this->MenuExpert();
            break;
        case 3:
            this->MenuAdmin();
            break;
        case 4:
            this->MenuSuperAdmin();
            break;
        case 5: // quitter
            return true;
            break;
        default:
            std::cout << "Vous n'avez pas choisi de menu." << std::endl;
            return false;
        }
    }
    return true;
}

bool App::MenuContributeur()
{
    const std::vector<std::string> menuVosDonnees = {"Entrer de nouvelles données", "Votre score global", "Liste de vos données", "Retour au menu principal"};
    const int choice = this->menu("Menu - Vos données", menuVosDonnees);
    switch (choice)
    {
    case 0:
    {
        App::banner("Ajouter une nouvelle entrée");

        std::string sensorId;
        std::cout << "* Nom du capteur : ";
        std::getline(std::cin, sensorId);
        if (sensorId.size() == 0)
        {
            std::cout << "Valeur invalide." << std::endl;
            return false;
        }

        std::cout << "* Coordonnées capteur" << std::endl;
        std::cout << "   - latitude : ";
        const auto resLat = App::readFractional();
        if (!resLat.valid || resLat.value < 0)
        {
            std::cout << "Valeur invalide." << std::endl;
            return false;
        }

        std::cout << "   - longitude : ";
        const auto resLon = App::readFractional();
        if (!resLon.valid || resLon.value < 0)
        {
            std::cout << "Valeur invalide." << std::endl;
            return false;
        }

        std::cout << "* Valeur mesurée : ";
        const auto resVal = App::readFractional();
        if (!resVal.valid || resVal.value < 0)
        {
            std::cout << "Valeur invalide." << std::endl;
            return false;
        }

        time_t timestamp = time(nullptr);
        Coordonnees coords(resLat.value, resLon.value);
        Capteur capteur(sensorId, "description capteur", coords);
        Type type("machin", "unité", "description unité");
        Mesure mes(resVal.value, timestamp, "mesure test", capteur, type);

        ServiceContributeur::envoyerDonnees(mes);

        break;
    }
    case 1:
        std::cout << "> Pas implémenté" << std::endl;
        break;
    case 2:
        std::cout << "> Pas implémenté" << std::endl;
        break;
    case 3:
        return true;
        break;
    default:
        std::cout << "Vous n'avez pas choisi de menu." << std::endl;
        return false;
    }
    return true;
}

bool App::MenuAnalyste()
{
    const std::vector<std::string> menuAnalyse = {"Filtrage géographique…", "Filtrage temporel…", "Statistiques…"};
    // const std::vector<std::string> menuAnalyseStatsCalculsSolo = {"Moyenne", "Médian", "Écart-type"};

    bool filtre_geographique = false;
    double filtre_rayon = 0.0;
    Coordonnees filtre_centre = Coordonnees(0.0, 0.0);

    bool filtre_temporel = false;
    time_t filtre_debut;
    time_t filtre_fin;

    while (true)
    {
        if (filtre_geographique)
        {
            std::cout << ">> Filtre géographique : "
                      << "Cercle de rayon " << filtre_rayon << " et de centre (" << filtre_centre.getLattitude() << ", " << filtre_centre.getLongitude() << ")"
                      << std::endl;
        }
        if (filtre_temporel)
        {
            char *buffer_debut = new char[64];
            char *buffer_fin = new char[64];
            const char *formatTimestamp("%d/%m/%Y");
            strftime(buffer_debut, 63, formatTimestamp, localtime(&filtre_debut));
            strftime(buffer_fin, 63, formatTimestamp, localtime(&filtre_fin));

            std::cout << ">> Filtre temporel : "
                      << "Période du " << buffer_debut << " au " << buffer_fin
                      << std::endl;

            free(buffer_debut);
            free(buffer_fin);
        }

        const int choice = this->menu("Menu - Sources de données", menuAnalyse);

        switch (choice)
        {
        case 0:
        {
            App::banner("Définir une région d'analyse");
            std::cout << "Forme de la région d'analyse : CERCLE" << std::endl;

            std::cout << "* Rayon du cercle (en mètres) : ";
            const auto resR = App::readFractional();
            if (!resR.valid || resR.value < 0)
            {
                std::cout << "Valeur invalide." << std::endl;
                return false;
            }

            std::cout << "* Centre du cercle" << std::endl;
            std::cout << "   - latitude : ";
            const auto resLat = App::readFractional();
            if (!resLat.valid || resLat.value < 0)
            {
                std::cout << "Valeur invalide." << std::endl;
                return false;
            }

            std::cout << "   - longitude : ";
            const auto resLon = App::readFractional();
            if (!resLon.valid || resLon.value < 0)
            {
                std::cout << "Valeur invalide." << std::endl;
                return false;
            }

            std::cout << std::endl;

            filtre_geographique = true;
            filtre_rayon = resR.value;
            filtre_centre = Coordonnees(resLat.value, resLon.value);
            break;
        }
        case 1:
        {
            App::banner("Définir une période d'analyse");
            std::cout << "Date de début (jour/mois/année) : ";
            const auto debut = App::readDate();
            if (!debut.valid)
            {
                std::cout << "Date invalide." << std::endl;
                return false;
            }

            std::cout << "Date de fin   (jour/mois/année) : ";
            const auto fin = App::readDate();
            if (!fin.valid)
            {
                std::cout << "Date invalide." << std::endl;
                return false;
            }

            filtre_temporel = true;
            filtre_debut = debut.value;
            filtre_fin = fin.value;
            break;
        }
        case 2:
        {
            // App::banner("Choisir les séries à analyser :");
            App::banner("Choisir la série à analyser :");

            std::vector<std::string> series = {"Blabla", "Machin", "Truc"};
            const int N = series.size();
            for (int i = 0; i < N; i++)
            {
                const auto serie = series[i];
                std::cout << std::setw(4) << (i + 1) << ". " << serie << std::endl;
            }
            std::cout << std::endl;

            std::cout << "Série : ";
            const auto res = App::readInteger();
            const bool valid = (res.valid && res.value > 0 && res.value <= N);
            if (!valid)
            {
                return false;
            }

            // poursuivre avec le choix de l'analyse

            std::cout << "> Pas implémenté" << std::endl;
            break;
        }
        case 3:
            return true;
            break;
        default:
            std::cout << "Vous n'avez pas choisi de menu." << std::endl;
            return false;
        }
    }
    return true;
}

bool App::MenuExpert()
{
    const std::vector<std::string> menuSources = {"Liste des sources", "Qualité des données", "Données médiocres", "Retour au menu principal"};
    const int choice = this->menu("Menu - Sources de données", menuSources);
    switch (choice)
    {
    case 0:
        std::cout << "> Pas implémenté" << std::endl;
        break;
    case 1:
        std::cout << "> Pas implémenté" << std::endl;
        break;
    case 2:
        std::cout << "> Pas implémenté" << std::endl;
        break;
    case 3:
        return true;
        break;
    default:
        std::cout << "Vous n'avez pas choisi de menu." << std::endl;
        return false;
    }
    return true;
}

bool App::MenuAdmin()
{
    const std::vector<std::string> menuAdministration = {"Supprimer un utilisateur", "Modifier un utilisateur", "Réinit. un mot de passe", "Retour au menu principal"};
    const int choice = this->menu("Menu - Administration", menuAdministration);
    switch (choice)
    {
    case 0:
        std::cout << "> Pas implémenté" << std::endl;
        break;
    case 1:
        std::cout << "> Pas implémenté" << std::endl;
        break;
    case 2:
        std::cout << "> Pas implémenté" << std::endl;
        break;
    case 3:
        return true;
        break;
    default:
        std::cout << "Vous n'avez pas choisi de menu." << std::endl;
        return false;
    }
    return true;
}

bool App::MenuSuperAdmin()
{
    return this->MenuAdmin();
}

// fonctions utilitaires
// lire un entier
App::ConsoleReadResult<int>
App::readInteger(std::istream &in)
{
    std::string input;
    std::getline(in, input);

    ConsoleReadResult<int> res;

    try
    {
        const int value = std::stoi(input);
        res.value = value;
        res.valid = true;
    }
    catch (std::invalid_argument)
    {
        res.value = 0;
        res.valid = false;
    }

    return res;
}

App::ConsoleReadResult<double>
App::readFractional(std::istream &in)
{
    std::string input;
    std::getline(in, input);

    ConsoleReadResult<double> res;

    try
    {
        const double value = std::stod(input);
        res.value = value;
        res.valid = true;
    }
    catch (std::invalid_argument)
    {
        res.value = 0.0;
        res.valid = false;
    }

    return res;
}

App::ConsoleReadResult<time_t>
App::readDate(std::istream &in)
{
    ConsoleReadResult<time_t> res;

    try
    {
        struct std::tm tm;
        in >> std::get_time(&tm, "%d/%m/%Y");
        time_t time = mktime(&tm);
        res.value = time;
        res.valid = true;
    }
    catch (std::invalid_argument)
    {
        res.value = 0;
        res.valid = false;
    }

    return res;
}

void App::banner(std::string text, bool thick, std::ostream &out)
{
    const int width = maxWidth;

    if (thick)
        out << primaryBg << primaryFg << std::string(width, ' ') << ANSI_FG_RESET << ANSI_BG_RESET << std::endl;
    out << primaryBg << primaryFg << text << ANSI_FG_RESET << ANSI_BG_RESET << std::endl;

    if (thick)
        out << primaryBg << primaryFg << std::string(width, ' ') << ANSI_FG_RESET << ANSI_BG_RESET << std::endl;
}

/**
 * Attention :
 * - renvoie un entier entre 0 et (N - 1) lorsque le choix est valide
 * - renvoie App::InvalidMenuChoice sinon
 */
int App::menu(const std::string menuName, const std::vector<std::string> &entries, std::ostream &out)
{
    // out << std::endl;
    // out << std::endl;
    banner(menuName, false, out);
    out << std::endl;

    int i = 0;
    for (auto const &entry : entries)
    {
        i += 1;
        out << ANSI_FG_BLUE << std::setw(4) << i << ". " << ANSI_FG_RESET << ANSI_BOLD_ON << entry << ANSI_BOLD_OFF << std::endl;
    }
    const int n = i;

    out << std::endl;
    out << "Entrez ici votre sélection : " << ANSI_FG_BLUE;

    auto res = readInteger();
    out << ANSI_FG_RESET;
    out << std::endl;

    if (!res.valid || res.value < 1 || res.value > n)
    {
        out << ANSI_FG_RED << "Entrée invalide, veuillez entrer un entier entre " << 1 << " et " << n << "." << ANSI_FG_RESET << std::endl;
        return InvalidMenuChoice;
    }
    else
    {
        return res.value - 1;
    }
}

void App::userbar(std::string username, std::ostream &out)
{
    const int width = maxWidth;

    const std::string preamble = "Utilisateur: ";
    int space = width - username.length() - preamble.length();
    if (space < 0)
    {
        space = 0;
    }

    out << secondaryBg << primaryFg << preamble << username << std::string(space, ' ') << ANSI_FG_RESET << ANSI_BG_RESET << std::endl;
}

App::App()
{
}
App::~App()
{
}
