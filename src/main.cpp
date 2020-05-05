#include <string>
#include <vector>

#include "UserInterface.hpp"

int main()
{
    UserInterface::banner("Bienvenue dans AirWatcher", true);
    std::cout << std::endl;

    std::vector<std::string>
        menu1 = {"Alpha", "Beta", "Gamma", "Delta", "Epsilon", "Iota", "Lambda", "Mumu", "Nono", "Wallah", "Poulet braisé", "Cuisine ouzbèke"};
    const int choice = UserInterface::menu("Menu Principal", menu1);

    if (choice == UserInterface::InvalidMenuChoice)
    {
        std::cout << "Vous n'avez pas choisi de menu." << std::endl;
    }
    else
    {
        std::cout << "Vous avez choisi le menu '" << menu1[choice] << "'" << std::endl;
    }

    return 0;
}
