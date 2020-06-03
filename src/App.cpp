#include <chrono>
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
#include "Services/ServiceAnalyste.h"
#include "Services/ServiceContributeur.h"

using namespace std;

// Définition des menus
bool App::MenuPrincipal()
{
    this->banner("Bienvenue dans AirWatcher");
    this->userbar("(anonyme)");

    // Tous les menus
    const vector<string>
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
            cout << "Vous n'avez pas choisi de menu." << endl;
            return false;
        }
    }
    return true;
}

bool App::MenuContributeur()
{
    const vector<string> menuVosDonnees = {"Entrer de nouvelles données", "Votre score global", "Liste de vos données", "Retour au menu principal"};
    const int choice = this->menu("Menu - Vos données", menuVosDonnees);
    switch (choice)
    {
    case 0:
    {
        App::banner("Ajouter une nouvelle entrée");

        cout << "Choix de l'utilisateur (débug)" << endl;
        const auto users = ServiceContributeur::listUsers();
        for (size_t i = 0; i < users->size(); i++)
        {
            const auto user = users->at(i);
            cout << setw(4) << (i + 1) << ". " << *user << endl;
        }
        cout << endl;
        cout << "Numéro de votre utilisateur : ";
        const auto resUser = App::readInteger();
        const bool validU = (resUser.valid && resUser.value > 0 && (size_t)resUser.value <= users->size());
        if (!validU)
        {
            cout << "Utilisateur invalide." << endl;
            return false;
        }
        const auto username = *users->at(resUser.value - 1);
        const auto contributeur = ServiceContributeur::getContributeur(username);

        cout << "Choix du capteur" << endl;
        const auto capteurs = contributeur->getCapteurs();
        for (size_t i = 0; i < capteurs.size(); i++)
        {
            const auto capteur = capteurs.at(i);
            cout << setw(4) << (i + 1) << ". " << capteur.getSensorId() << " (" << capteur.getCoordonnees().getLattitude() << ", " << capteur.getCoordonnees().getLongitude() << ") -- " << capteur.getDescription() << endl;
        }
        cout << endl;
        cout << "Numéro du capteur : ";
        const auto resCapteur = App::readInteger();
        const bool validC = (resCapteur.valid && resCapteur.value > 0 && (size_t)resCapteur.value <= capteurs.size());
        if (!validC)
        {
            cout << "Capteur invalide." << endl;
            return false;
        }
        const auto capteur = capteurs.at(resCapteur.value - 1);

        cout << "Choix du type" << endl;
        const auto types = ServiceAnalyste::listType();
        for (size_t i = 0; i < types->size(); i++)
        {
            const auto type = types->at(i);
            cout << setw(4) << (i + 1) << ". " << type->getAttributeId() << " (" << type->getUnite() << ") -- " << type->getDescription() << endl;
        }
        cout << endl;
        cout << "Numéro du type : ";
        const auto resType = App::readInteger();
        const bool validT = (resType.valid && resType.value > 0 && (size_t)resType.value <= types->size());
        if (!validT)
        {
            cout << "Type invalide." << endl;
            return false;
        }
        const auto type = *types->at(resType.value - 1);

        cout << endl;
        cout << "Valeur mesurée : ";
        const auto resVal = App::readFractional();
        if (!resVal.valid || resVal.value < 0)
        {
            cout << "Valeur invalide." << endl;
            return false;
        }

        auto start = chrono::steady_clock::now();

        // instanciation des objets nécessaires
        time_t timestamp = time(nullptr);
        Mesure mes(resVal.value, timestamp, "ajout manuel", capteur, type);

        ServiceContributeur::envoyerDonnees(mes);

        auto end = chrono::steady_clock::now();
        auto diff = end - start;

        cout << "Temps d'execution : " << chrono::duration<double, milli>(diff).count() << " ms" << endl;

        for (auto i = types->begin(); i != types->end(); ++i)
            delete *i;
        delete types;
        for (auto i = users->begin(); i != users->end(); ++i)
            delete *i;
        delete users;
        delete contributeur;
        break;
    }
    case 1:
        cout << "> Pas implémenté" << endl;
        break;
    case 2:
        cout << "> Pas implémenté" << endl;
        break;
    case 3:
        return true;
        break;
    default:
        cout << "Vous n'avez pas choisi de menu." << endl;
        return false;
    }
    return true;
}

bool App::MenuAnalyste()
{
    const vector<string> menuAnalyse = {"Filtrage géographique…", "Filtrage temporel…", "Lancer le calcul", "Retour au menu principal"};

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
            cout << ">> Filtre géographique : "
                 << "Cercle de rayon " << filtre_rayon << " et de centre (" << filtre_centre.getLattitude() << ", " << filtre_centre.getLongitude() << ")"
                 << endl;
        }
        if (filtre_temporel)
        {
            char *buffer_debut = new char[64];
            char *buffer_fin = new char[64];
            const char *formatTimestamp("%d/%m/%Y");
            strftime(buffer_debut, 63, formatTimestamp, localtime(&filtre_debut));
            strftime(buffer_fin, 63, formatTimestamp, localtime(&filtre_fin));

            cout << ">> Filtre temporel : "
                 << "Période du " << buffer_debut << " au " << buffer_fin
                 << endl;

            delete[] buffer_debut;
            delete[] buffer_fin;
        }

        const int choice = this->menu("Menu - Analyse", menuAnalyse);

        switch (choice)
        {
        case 0:
        {
            filtre_geographique = false;

            App::banner("Définir une région d'analyse");
            cout << "Forme de la région d'analyse : CERCLE" << endl;

            cout << "* Rayon du cercle (en mètres) : ";
            const auto resR = App::readFractional();
            if (!resR.valid || resR.value < 0)
            {
                cout << "Valeur invalide." << endl;
                return false;
            }

            cout << "* Centre du cercle" << endl;
            cout << "   - latitude : ";
            const auto resLat = App::readFractional();
            if (!resLat.valid || resLat.value < 0)
            {
                cout << "Valeur invalide." << endl;
                return false;
            }

            cout << "   - longitude : ";
            const auto resLon = App::readFractional();
            if (!resLon.valid || resLon.value < 0)
            {
                cout << "Valeur invalide." << endl;
                return false;
            }

            cout << endl;

            filtre_geographique = true;
            filtre_rayon = resR.value;
            filtre_centre = Coordonnees(resLat.value, resLon.value);
            break;
        }
        case 1:
        {
            filtre_temporel = false;

            App::banner("Définir une période d'analyse");
            cout << "Date de début (jj/mm/aaaa) : ";
            const auto debut = App::readDate();
            if (!debut.valid)
            {
                cout << "Date invalide." << endl;
                return false;
            }

            cout << "Date de fin   (jj/mm/aaaa) : ";
            const auto fin = App::readDate(true); // entrée + 23h59m59s
            if (!fin.valid)
            {
                cout << "Date invalide." << endl;
                return false;
            }

            filtre_temporel = true;
            filtre_debut = debut.value;
            filtre_fin = fin.value;
            break;
        }
        case 2:
        {
            cout << "Calcul..." << flush;
            auto start = chrono::steady_clock::now();

            const auto resultat = ServiceAnalyste::agregerDonnees(filtre_centre, filtre_rayon, filtre_debut, filtre_fin, filtre_geographique, filtre_temporel);

            auto end = chrono::steady_clock::now();
            auto diff = end - start;

            cerr << " Terminé en " << chrono::duration<double, milli>(diff).count() << " ms" << endl;

            if (resultat->size() > 0)
            {
                App::banner("Résultats des calculs :");
                cout
                    << setw(9) << "attribut"
                    << " | "
                    << setw(5) << "unité"
                    << " | "
                    << setw(7) << "minimum"
                    << " | "
                    << setw(7) << "moyenne"
                    << " | "
                    << setw(7) << "mediane"
                    << " | "
                    << setw(7) << "maximum"
                    << " | "
                    << setw(10) << "écart-type"
                    << endl;

                for (auto it = resultat->begin(); it != resultat->end(); it++)
                {
                    const auto v = it->second;
                    cout
                        << setw(9) << it->first.getAttributeId() << " | "
                        << setw(5) << it->first.getUnite() << " | "
                        << setw(7) << v.min << " | "
                        << setw(7) << v.moyenne << " | "
                        << setw(7) << v.mediane << " | "
                        << setw(7) << v.max << " | "
                        << setw(10) << v.ecartType
                        << endl;
                }
                cout << endl;
            }
            else
            {
                App::banner("Aucun résultat pour les critères spécifiés");
                cout << endl;
            }

            break;
        }
        case 3:
            return true;
            break;
        default:
            cout << "Vous n'avez pas choisi de menu." << endl;
            return false;
        }
    }
    return true;
}

bool App::MenuExpert()
{
    const vector<string> menuSources = {"Liste des sources", "Qualité des données", "Données médiocres", "Retour au menu principal"};
    const int choice = this->menu("Menu - Sources de données", menuSources);
    switch (choice)
    {
    case 0:
        cout << "> Pas implémenté" << endl;
        break;
    case 1:
        cout << "> Pas implémenté" << endl;
        break;
    case 2:
        cout << "> Pas implémenté" << endl;
        break;
    case 3:
        return true;
        break;
    default:
        cout << "Vous n'avez pas choisi de menu." << endl;
        return false;
    }
    return true;
}

bool App::MenuAdmin()
{
    const vector<string> menuAdministration = {"Ajouter un analyste / expert", "Supprimer un analyste / expert", "Modifier un analyste / expert", "Réinit. un mot de passe", "Retour au menu principal"};
    const int choice = this->menu("Menu - Administration", menuAdministration);
    switch (choice)
    {
    case 0:
        cout << "> Pas implémenté" << endl;
        break;
    case 1:
        cout << "> Pas implémenté" << endl;
        break;
    case 2:
        cout << "> Pas implémenté" << endl;
        break;
    case 3:
        cout << "> Pas implémenté" << endl;
        break;
    case 4:
        return true;
        break;
    default:
        cout << "Vous n'avez pas choisi de menu." << endl;
        return false;
    }
    return true;
}

bool App::MenuSuperAdmin()
{
    const vector<string> menuSuperAdmin = {"Ajouter un administrateur", "Modifier un administrateur", "Supprimer un administrateur", "Voir les performances du service", "Retour au menu principal"};
    const int choice = this->menu("Menu - Super Administration", menuSuperAdmin);
    switch (choice)
    {
    case 0:
        cout << "> Pas implémenté" << endl;
        break;
    case 1:
        cout << "> Pas implémenté" << endl;
        break;
    case 2:
        cout << "> Pas implémenté" << endl;
        break;
    case 3:
        cout << "> Pas implémenté" << endl;
        break;
    case 4:
        cout << "> Pas implémenté" << endl;
        break;
    default:
        cout << "Vous n'avez pas choisi de menu." << endl;
        return false;
    }
    return true;
}

// fonctions utilitaires
// lire un entier
App::ConsoleReadResult<int>
App::readInteger(istream &in)
{
    string input;
    getline(in, input);

    ConsoleReadResult<int> res;

    try
    {
        const int value = stoi(input);
        res.value = value;
        res.valid = true;
    }
    catch (invalid_argument)
    {
        res.value = 0;
        res.valid = false;
    }

    return res;
}

App::ConsoleReadResult<double>
App::readFractional(istream &in)
{
    string input;
    getline(in, input);

    ConsoleReadResult<double> res;

    try
    {
        const double value = stod(input);
        res.value = value;
        res.valid = true;
    }
    catch (invalid_argument)
    {
        res.value = 0.0;
        res.valid = false;
    }

    return res;
}

/**
 * L'option endOfDay permet de décaler de 23h59m59s dans le temps
 */
App::ConsoleReadResult<time_t>
App::readDate(bool endOfDay, istream &in)
{
    ConsoleReadResult<time_t> res;

    try
    {
        tm tm{};
        in >> get_time(&tm, "%d/%m/%Y");

        if (in.fail())
        {
            res.value = 0;
            res.valid = false;
        }
        else
        {
            in.ignore(10000, '\n'); // skip new line

            if (endOfDay)
            {
                tm.tm_hour = 23;
                tm.tm_min = 59;
                tm.tm_sec = 59;
            }

            time_t time = mktime(&tm);
            res.value = time;
            res.valid = true;
        }
    }
    catch (invalid_argument)
    {
        res.value = 0;
        res.valid = false;
    }

    return res;
}

void App::banner(string text, bool thick, ostream &out)
{
    const int width = maxWidth;

    if (thick)
        out << primaryBg << primaryFg << string(width, ' ') << ANSI_FG_RESET << ANSI_BG_RESET << endl;
    out << primaryBg << primaryFg << text << ANSI_FG_RESET << ANSI_BG_RESET << endl;

    if (thick)
        out << primaryBg << primaryFg << string(width, ' ') << ANSI_FG_RESET << ANSI_BG_RESET << endl;
}

/**
 * Attention :
 * - renvoie un entier entre 0 et (N - 1) lorsque le choix est valide
 * - renvoie App::InvalidMenuChoice sinon
 */
int App::menu(const string menuName, const vector<string> &entries, ostream &out)
{
    // out << endl;
    // out << endl;
    banner(menuName, false, out);
    out << endl;

    int i = 0;
    for (auto const &entry : entries)
    {
        i += 1;
        out << setw(4) << i << ". " << entry << endl;
    }
    const int n = i;

    out << endl;
    out << "Entrez ici votre sélection : ";

    auto res = readInteger();
    out << endl;

    if (!res.valid || res.value < 1 || res.value > n)
    {
        out << "Entrée invalide, veuillez entrer un entier entre " << 1 << " et " << n << "." << endl;
        return InvalidMenuChoice;
    }
    else
    {
        return res.value - 1;
    }
}

void App::userbar(string username, ostream &out)
{
    const int width = maxWidth;

    const string preamble = "Utilisateur: ";
    int space = width - username.length() - preamble.length();
    if (space < 0)
    {
        space = 0;
    }

    out << secondaryBg << primaryFg << preamble << username << string(space, ' ') << ANSI_FG_RESET << ANSI_BG_RESET << endl;
}

App::App()
{
}
App::~App()
{
}
