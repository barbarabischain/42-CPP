#include "../include/HumanA.hpp"
#include "../include/HumanB.hpp"
#include "../include/Weapon.hpp"

int main()
{
    {
        Weapon club = Weapon("crude spiked club");
        HumanA bob("Bob", club);
        bob.attack();
        club.setType("some other type of club");
        bob.attack();
    }
    {
        HumanB jim("Jim");
        jim.attack();
        Weapon club = Weapon("crude spiked club");
        jim.setWeapon(club);
        club.setType("some other type of club");
        jim.attack();
    }
    return 0;
}
