#include "ClapTrap.hpp"
#include "ScavTrap.hpp"


int main(void)
{
    std::cout << BGREEN << "*** TESTING INHERITANCE CHAIN ***" << RESET << std::endl;
    ScavTrap robot("Guardian");

    std::cout << BGREEN <<  "\n*** TESTING SCAVTRAP ABILITIES ***" << RESET << std::endl;
    robot.attack("Enemy");
    robot.takeDamage(30);
    robot.beRepaired(10);
    robot.guardGate();

    std::cout <<  BGREEN << "\n*** TESTING COPY CONSTRUCTOR ***" << RESET << std::endl;
    ScavTrap copy(robot);

    std::cout <<  BGREEN << "\n*** DESTRUCTION CHAIN ***" << RESET << std::endl;

    return(0);
}
