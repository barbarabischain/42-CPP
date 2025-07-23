#include "../include/HumanB.hpp"

HumanB::HumanB(const std::string name): name(name), weapon(NULL){}

HumanB::~HumanB(){}

void HumanB::attack() const{
    if (weapon != NULL)
        std::cout << this->name << " attacks with their " << this->weapon->getType() << std::endl;
    else
        std::cout << this->name << " attacks with their hand" << std::endl;
}

void  HumanB::setWeapon(Weapon &weapon){
    this->weapon = &weapon;
}
