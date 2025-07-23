#include "ClapTrap.hpp"
#include "FlagTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
    std::cout << BGREEN << "*** TESTING INHERITANCE CHAIN ***" << RESET << std::endl;
    FlagTrap alien("Orion");

    std::cout << BGREEN <<  "\n*** TESTING FLAGTRAP ABILITIES ***" << RESET << std::endl;
    alien.attack("Enemy");
    alien.takeDamage(30);
    alien.beRepaired(10);
    alien.highFivesGuys();
    std::cout << "FlaTrap Hit Points: " << alien.getEnergyPoints() << std::endl;

    std::cout <<  BGREEN << "\n*** TESTING COPY CONSTRUCTOR ***" << RESET << std::endl;
    FlagTrap copy(alien);

    std::cout <<  BGREEN << "\n*** DESTRUCTION CHAIN ***" << RESET << std::endl;

    return(0);
}
