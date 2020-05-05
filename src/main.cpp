#include <string>
#include <vector>

#include "App.hpp"

int main()
{
    App app;

    app.banner("Bienvenue dans AirWatcher", true);
    app.userbar("Corentin");
    std::cout << std::endl;

    std::vector<std::string>
        menu1 = {"Alpha", "Beta", "Gamma", "Delta", "Epsilon", "Iota", "Lambda", "Mumu", "Nono", "Wallah", "Poulet braisé", "Cuisine ouzbèke"};
    const int choice = app.menu("Menu Principal", menu1);

    if (choice == App::InvalidMenuChoice)
    {
        std::cout << "Vous n'avez pas choisi de menu." << std::endl;
    }
    else
    {
        std::cout << "Vous avez choisi le menu '" << menu1[choice] << "'" << std::endl;
    }

    return 0;
}
