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
#include <string>
#include <vector>

std::string
stringCenter(std::string const &str, int targetSize)
{
    assert(targetSize >= 0);
    int padding = targetSize - str.length();
    if (padding > 0)
    {
        int half = padding / 2;
        return std::string(half, ' ') + str + std::string(half, ' ');
    }
    return str;
}

namespace UserInterface
{
int menu(std::string menuName, std::vector<std::string> entries)
{
    std::cout << std::endl;
    std::cout << ANSI_BOLD_ON << ANSI_BG_YELLOW << ANSI_FG_BLACK << stringCenter(menuName, menuName.length() + 6) << ANSI_FG_RESET << ANSI_BG_RESET << ANSI_BOLD_OFF << std::endl;
    std::cout << std::endl;

    size_t i = 0;
    for (auto const &entry : entries)
    {
        i += 1;
        std::cout << ANSI_FG_BLUE << std::setw(4) << i << ". " << ANSI_FG_RESET << ANSI_BOLD_ON << entry << ANSI_BOLD_OFF << std::endl;
    }

    std::cout << std::endl;
    std::cout << "Entrez ici votre sélection : " << ANSI_FG_BLUE;

    std::cout << 4;

    std::cout << ANSI_FG_RESET;
    std::cout << std::endl;
    return 0;
}
} // namespace UserInterface
