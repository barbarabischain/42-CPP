#include "ClapTrap.hpp"

int main(void)
{
    ClapTrap Robot("Robot");
    ClapTrap Zombie("Zombie");

    std::cout << std::endl;
    Robot.setAttackDamage(3);
    Zombie.setAttackDamage(2);

    std::cout << BGREEN << "*ROBOT ATTACKS ZOMBIE THREE TIMES*" << RESET << std::endl;
    for (int i = 0; i < 3; i++)
    {
        Robot.attack("Zombie");
        Zombie.takeDamage(3);
    }
    std::cout << std::endl;

    std::cout << BGREEN << "*ZOMBIE ATTACKS ROBOT*" << RESET << std::endl;
    Zombie.attack("Robot");
    Robot.takeDamage(2);
    std::cout << std::endl;

    std::cout << BGREEN << "*ROBOT REPAIRS ITESELF*" << RESET << std::endl;
    Robot.beRepaired(1);
    std::cout << std::endl;

    std::cout << BGREEN << "*ROBOT ATTACKS ZOMBIE TWO TIMES*" << RESET << std::endl;
    for (int i = 0; i < 2; i++)
    {
        Robot.attack("Zombie");
        Zombie.takeDamage(3);
    }
    std::cout << std::endl;

    std::cout << BGREEN << "*ROBOT TRIES TO ATTACK OTHER ENEMY*" << RESET << std::endl;
        Robot.attack("enemy");

    std::cout << std::endl;
    std::cout << std::endl;

    return(0);
}
