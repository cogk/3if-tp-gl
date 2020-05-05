#include <string>
#include <vector>

#include "UserInterface.hpp"

int main()
{
    std::cout << "Welcome to AirWatcher\n";

    std::vector<std::string> menu1 = {"Alpha", "Beta", "Gamma", "Delta", "Epsilon", "Iota", "Lambda", "Mumu", "Nono", "Wallah", "Poulet braisé", "Cuisine ouzbèke"};
    UserInterface::menu("Menu Principal", menu1);
    return 0;
}
