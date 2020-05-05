// Définition des séquences d'échappement ANSI classiques
#define ANSI_FG_BLACK "\x1b[30m"
#define ANSI_FG_BLUE "\x1b[34m"
#define ANSI_FG_GREEN "\x1b[32m"
#define ANSI_FG_CYAN "\x1b[36m"
#define ANSI_FG_RED "\x1b[31m"
#define ANSI_FG_PURPLE "\x1b[35m"
#define ANSI_FG_BROWN "\x1b[33m"
#define ANSI_FG_GRAY "\x1b[37m"
#define ANSI_FG_RESET "\x1b[39m"

#define ANSI_BG_GRAY "\x1b[40m"
#define ANSI_BG_BLUE "\x1b[44m"
#define ANSI_BG_GREEN "\x1b[42m"
#define ANSI_BG_CYAN "\x1b[46m"
#define ANSI_BG_RED "\x1b[41m"
#define ANSI_BG_PURPLE "\x1b[45m"
#define ANSI_BG_YELLOW "\x1b[43m"
#define ANSI_BG_WHITE "\x1b[47m"
#define ANSI_BG_RESET "\x1b[49m"

#define ANSI_BOLD_ON "\x1b[1m"
#define ANSI_BOLD_OFF "\x1b[22m"

#include <iomanip>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

namespace UserInterface
{
const int InvalidMenuChoice = -1;
int MaxWidth = 32;

// fonctions utilitaires

// lire un entier
struct ReadIntegerResult
{
    int value;
    bool valid;
};
ReadIntegerResult
readInteger(std::istream &inputStream = std::cin)
{
    std::string input;
    std::getline(inputStream, input);

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
util_stringCenter(std::string const &str, int targetSize)
{
    int padding = targetSize - str.length();
    if (padding > 0)
    {
        int half = padding / 2;
        return std::string(half, ' ') + str + std::string(padding - half, ' ');
    }
    return str;
}

void banner(std::string text, bool thick = false, std::ostream &out = std::cout)
{
    const int width = MaxWidth;
    // const int width = text.length() + 2 * 3;

    if (thick)
        out << ANSI_BG_YELLOW << ANSI_FG_BLACK << std::string(width, ' ') << ANSI_FG_RESET << ANSI_BG_RESET << std::endl;

    out << ANSI_BG_YELLOW << ANSI_FG_BLACK << util_stringCenter(text, width) << ANSI_FG_RESET << ANSI_BG_RESET << std::endl;

    if (thick)
        out << ANSI_BG_YELLOW << ANSI_FG_BLACK << std::string(width, ' ') << ANSI_FG_RESET << ANSI_BG_RESET << std::endl;
}

/**
 * Attention :
 * - ne renverra JAMAIS 0
 * - renvoie un entier entre 1 et N lorsque le choix est valide
 * - renvoie UserInterface::InvalidMenuChoice sinon
 */
int menu(std::string menuName, std::vector<std::string> entries, std::ostream &out = std::cout)
{
    UserInterface::banner(menuName, false, out);
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

    if (!res.valid || res.value <= 1 || res.value > n)
    {
        out << ANSI_FG_RED << "Entrée invalide, veuillez entrer un entier entre " << 1 << " et " << n << "." << ANSI_FG_RESET << std::endl;
        return InvalidMenuChoice;
    }
    else
    {
        return res.value - 1;
    }
}
} // namespace UserInterface
