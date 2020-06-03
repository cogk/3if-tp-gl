// Définition des séquences d'échappement ANSI classiques

#define ANSI_FG_BLACK ""
#define ANSI_FG_RESET ""
#define ANSI_BG_CYAN "* "
#define ANSI_BG_YELLOW "| "
#define ANSI_BG_RESET " "

#include <iostream>
#include <string>
#include <time.h>
#include <vector>

class App
{
private:
    int maxWidth = 28;

    const std::string primaryBg = ANSI_BG_CYAN;
    const std::string secondaryBg = ANSI_BG_YELLOW;
    const std::string primaryFg = ANSI_FG_BLACK;

    template <typename T>
    struct ConsoleReadResult
    {
        T value;
        bool valid;
    };

    void banner(const std::string text, bool thick = false, std::ostream &out = std::cout);
    int menu(const std::string menuName, const std::vector<std::string> &entries, std::ostream &out = std::cout);
    void userbar(std::string username, std::ostream &out = std::cout);

public:
    App();
    ~App();

    static const int InvalidMenuChoice = -1;

    bool MenuPrincipal();
    bool MenuContributeur();
    bool MenuExpert();
    bool MenuAnalyste();
    bool MenuAdmin();
    bool MenuSuperAdmin();

    static ConsoleReadResult<int> readInteger(std::istream &inputStream = std::cin);
    static ConsoleReadResult<double> readFractional(std::istream &inputStream = std::cin);
    static ConsoleReadResult<time_t> readDate(bool endOfDay = false, std::istream &inputStream = std::cin);
};
