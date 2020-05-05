#include <iomanip>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

#include "App.hpp"

// fonctions utilitaires
// lire un entier
App::ReadIntegerResult
App::readInteger(std::istream &in)
{
    std::string input;
    std::getline(in, input);

    ReadIntegerResult res;

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

// centrer une chaine de caractères
std::string
App::util_stringCenter(std::string const &str, int targetSize)
{
    int padding = targetSize - str.length();
    if (padding > 0)
    {
        int half = padding / 2;
        return std::string(half, ' ') + str + std::string(padding - half, ' ');
    }
    return str;
}

void App::banner(std::string text, bool thick, std::ostream &out)
{
    const int width = maxWidth;

    if (thick)
        out << primaryBg << primaryFg << std::string(width, ' ') << ANSI_FG_RESET << ANSI_BG_RESET << std::endl;
    out << primaryBg << primaryFg << util_stringCenter(text, width) << ANSI_FG_RESET << ANSI_BG_RESET << std::endl;

    if (thick)
        out << primaryBg << primaryFg << std::string(width, ' ') << ANSI_FG_RESET << ANSI_BG_RESET << std::endl;
}

/**
 * Attention :
 * - renvoie un entier entre 0 et (N - 1) lorsque le choix est valide
 * - renvoie App::InvalidMenuChoice sinon
 */
int App::menu(std::string menuName, std::vector<std::string> entries, std::ostream &out)
{
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

    const std::string preamble = "   Utilisateur: ";
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
