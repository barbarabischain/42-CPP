#include "FlagTrap.hpp"
#include "ClapTrap.hpp"


FlagTrap::FlagTrap(void): ClapTrap(){
    this->HitPoints = 100;
    this->EnergyPoints = 100;
    this->AttackDamage = 30;
    std::cout << MAGENTA << "FlagTrap " << RESET << "default constructor called" << std::endl;
}

FlagTrap::FlagTrap(std::string Name): ClapTrap(Name){
    this->HitPoints = 100;
    this->EnergyPoints = 100;
    this->AttackDamage = 30;
    std::cout << MAGENTA << "FlagTrap " << RESET << "parametrized constructor called" << std::endl;
}

FlagTrap::FlagTrap(const FlagTrap &other): ClapTrap(other){
    std::cout << MAGENTA << "FlagTrap " << RESET << "copy constructor called" << std::endl;

}

FlagTrap &FlagTrap::operator=(const FlagTrap &other){
    std::cout << MAGENTA << "FlagTrap " << RESET << "assignment operator called" << std::endl;
    if (this != &other)
        ClapTrap::operator=(other);
    return (*this);
}



void FlagTrap::attack(const std::string& target){
    if (this->HitPoints <= 0)
    std::cout << MAGENTA  << "FlagTrap " << RESET << this->Name << " can't attack because it's already dead!" << std::endl;
    else if (this->EnergyPoints <= 0)
    std::cout << MAGENTA  << "FlagTrap " << RESET << this->Name << " can't attack because it's exhausted!" << std::endl;
    else
    {
        this->EnergyPoints--;
        std::cout << MAGENTA  << "FlagTrap " << RESET << this->Name << " attacks " << target <<", causing "<< this->AttackDamage <<" points of damage!" << std::endl;
    }
}

void FlagTrap::highFivesGuys(void){
    std::cout << MAGENTA  << "FlagTrap " << RESET << this->Name << " positively requests high fives!" << std::endl;
}

FlagTrap::~FlagTrap(void){
    std::cout << MAGENTA  << "FlagTrap " << RESET << "destructor called" << std::endl;
}
