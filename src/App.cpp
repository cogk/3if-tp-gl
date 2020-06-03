#include <chrono>
#include <iomanip>
#include <iostream>
#include <stdexcept>
#include <string>
#include <time.h>
#include <vector>

#include "App.h"
#include "DAO/CapteurDAO.h"
#include "DAO/TypeDAO.h"
#include "Metier/Capteur.h"
#include "Metier/Coordonnees.h"
#include "Metier/Mesure.h"
#include "Metier/Type.h"
#include "Services/ServiceAnalyste.h"
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

        std::cout << "Choix du capteur" << std::endl;
        CapteurDAO daoCapteurs;
        const auto capteurs = daoCapteurs.list();
        for (size_t i = 0; i < capteurs->size(); i++)
        {
            const auto capteur = capteurs->at(i);
            std::cout << std::setw(4) << (i + 1) << ". " << capteur->getSensorId() << " (" << capteur->getCoordonnees().getLattitude() << ", " << capteur->getCoordonnees().getLongitude() << ") -- " << capteur->getDescription() << std::endl;
        }
        std::cout << std::endl;
        std::cout << "Numéro du capteur : ";
        const auto resCapteur = App::readInteger();
        const bool validC = (resCapteur.valid && resCapteur.value > 0 && resCapteur.value <= capteurs->size());
        if (!validC)
        {
            std::cout << "Capteur invalide." << std::endl;
            return false;
        }
        const auto capteur = capteurs->at(resCapteur.value - 1);

        std::cout << "Choix du type" << std::endl;
        TypeDAO daoTypes;
        const auto types = daoTypes.list();
        for (size_t i = 0; i < types->size(); i++)
        {
            const auto type = types->at(i);
            std::cout << std::setw(4) << (i + 1) << ". " << type->getAttributeId() << " (" << type->getUnite() << ") -- " << type->getDescription() << std::endl;
        }
        std::cout << std::endl;
        std::cout << "Numéro du type : ";
        const auto resType = App::readInteger();
        const bool validT = (resType.valid && resType.value > 0 && resType.value <= types->size());
        if (!validT)
        {
            std::cout << "Type invalide." << std::endl;
            return false;
        }
        const auto type = types->at(resType.value - 1);

        std::cout << std::endl;
        std::cout << "Valeur mesurée : ";
        const auto resVal = App::readFractional();
        if (!resVal.valid)
        {
            std::cout << "Valeur invalide." << std::endl;
            return false;
        }

        auto start = chrono::steady_clock::now();

        // instanciation des objets nécessaires
        time_t timestamp = time(nullptr);
        Mesure mes(resVal.value, timestamp, "ajout manuel", *capteur, *type);

        ServiceContributeur::envoyerDonnees(mes);

        auto end = chrono::steady_clock::now();
        auto diff = end - start;

        cout << "Temps d'execution : " << chrono::duration<double, milli>(diff).count() << " ms" << endl;

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
    const std::vector<std::string> menuAnalyse = {"Filtrage géographique…", "Filtrage temporel…", "Lancer le calcul", "Retour au menu principal"};

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

            delete buffer_debut;
            delete buffer_fin;
        }

        const int choice = this->menu("Menu - Sources de données", menuAnalyse);

        switch (choice)
        {
        case 0:
        {
            filtre_geographique = false;

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
            filtre_temporel = false;

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
            /*
            App::banner("Choisir le type de mesure à analyser :");

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
            */

            std::cout << "Calcul..." << std::flush;

            const auto resultat = ServiceAnalyste::agregerDonnees(filtre_centre, filtre_rayon, filtre_debut, filtre_fin, filtre_geographique, filtre_temporel);
            std::cout << " Terminé." << std::endl
                      << std::endl;
            App::banner("Résultats des calculs :");
            std::cout
                << std::setw(9) << "attribut"
                << " | "
                << std::setw(5) << "unité"
                << " | "
                << std::setw(7) << "minimum"
                << " | "
                << std::setw(7) << "moyenne"
                << " | "
                << std::setw(7) << "mediane"
                << " | "
                << std::setw(7) << "maximum"
                << " | "
                << std::setw(10) << "écart-type"
                << std::endl;

            for (auto it = resultat->begin(); it != resultat->end(); it++)
            {
                const auto v = it->second;
                std::cout
                    << std::setw(9) << it->first.getAttributeId() << " | "
                    << std::setw(5) << it->first.getUnite() << " | "
                    << std::setw(7) << v.min << " | "
                    << std::setw(7) << v.moyenne << " | "
                    << std::setw(7) << v.mediane << " | "
                    << std::setw(7) << v.max << " | "
                    << std::setw(10) << v.ecartType
                    << std::endl;
            }

            std::cout << std::endl;

            break;
        }
        case 3:
            return true;
            break;
        case 4:
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
    const std::vector<std::string> menuAdministration = {"Ajouter un analyste / expert", "Supprimer un analyste / expert", "Modifier un analyste / expert", "Réinit. un mot de passe", "Retour au menu principal"};
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
        std::cout << "> Pas implémenté" << std::endl;
        break;
    case 4:
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
    const std::vector<std::string> menuSuperAdmin = {"Ajouter un administrateur", "Modifier un administrateur", "Supprimer un administrateur", "Voir les performances du service", "Retour au menu principal"};
    const int choice = this->menu("Menu - Administration", menuSuperAdmin);
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
        std::cout << "> Pas implémenté" << std::endl;
        break;
    case 4:
        std::cout << "> Pas implémenté" << std::endl;
        break;
    default:
        std::cout << "Vous n'avez pas choisi de menu." << std::endl;
        return false;
    }
    return true;
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
        std::tm tm{};
        in >> std::get_time(&tm, "%d/%m/%Y");
        std::cout << std::endl
                  << tm.tm_year
                  << std::endl;

        if (in.fail())
        {
            res.value = 0;
            res.valid = false;
        }
        else
        {
            in.ignore(10000, '\n'); // skip new line

            time_t time = mktime(&tm);
            res.value = time;
            res.valid = true;
        }
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
        out << std::setw(4) << i << ". " << entry << std::endl;
    }
    const int n = i;

    out << std::endl;
    out << "Entrez ici votre sélection : ";

    auto res = readInteger();
    out << std::endl;

    if (!res.valid || res.value < 1 || res.value > n)
    {
        out << "Entrée invalide, veuillez entrer un entier entre " << 1 << " et " << n << "." << std::endl;
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
