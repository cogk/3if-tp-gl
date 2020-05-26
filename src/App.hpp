// Définition des séquences d'échappement ANSI classiques

// #define ANSI
#ifdef ANSI

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

#else

#define ANSI_FG_BLACK ""
#define ANSI_FG_BLUE ""
#define ANSI_FG_GREEN ""
#define ANSI_FG_CYAN ""
#define ANSI_FG_RED ""
#define ANSI_FG_PURPLE ""
#define ANSI_FG_BROWN ""
#define ANSI_FG_GRAY ""
#define ANSI_FG_RESET ""

#define ANSI_BG_GRAY "["
#define ANSI_BG_BLUE "["
#define ANSI_BG_GREEN "["
#define ANSI_BG_CYAN "["
#define ANSI_BG_RED "["
#define ANSI_BG_PURPLE "["
#define ANSI_BG_YELLOW "["
#define ANSI_BG_WHITE "["
#define ANSI_BG_RESET "]"

#define ANSI_BOLD_ON ""
#define ANSI_BOLD_OFF ""

#endif

#include <iostream>
#include <string>

class App
{
private:
    int maxWidth = 32;

    const std::string primaryBg = ANSI_BG_YELLOW;
    const std::string secondaryBg = ANSI_BG_CYAN;
    const std::string primaryFg = ANSI_FG_BLACK;

    struct ReadIntegerResult
    {
        int value;
        bool valid;
    };

    std::string util_stringCenter(std::string const &str, int targetSize);

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

    static ReadIntegerResult readInteger(std::istream &inputStream = std::cin);
};
