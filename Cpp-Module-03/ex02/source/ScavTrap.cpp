#include "ScavTrap.hpp"
#include "ClapTrap.hpp"


ScavTrap::ScavTrap(void): ClapTrap(){
    this->HitPoints = 100;
    this->EnergyPoints = 50;
    this->AttackDamage = 20;
    std::cout << CYAN << "ScavTrap " << RESET << "default constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string Name): ClapTrap(Name){
    this->HitPoints = 100;
    this->EnergyPoints = 50;
    this->AttackDamage = 20;
    std::cout << CYAN << "ScavTrap " << RESET << "parametrized constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other): ClapTrap(other){
    std::cout << CYAN << "ScavTrap " << RESET << "copy constructor called" << std::endl;

}

ScavTrap &ScavTrap::operator=(const ScavTrap &other){
    std::cout << CYAN << "ScavTrap " << RESET << "assignment operator called" << std::endl;
    if (this != &other)
        ClapTrap::operator=(other);
    return (*this);
}

void ScavTrap::guardGate(){
    std::cout << CYAN << "ScavTrap " << RESET << this->Name << " is now in Gate keeper mode!" << std::endl;
}

void ScavTrap::attack(const std::string& target){
    if (this->HitPoints <= 0)
        std::cout << CYAN << "ScavTrap " << RESET << this->Name << " can't attack because it's already dead!" << std::endl;
    else if (this->EnergyPoints <= 0)
        std::cout << CYAN << "ScavTrap " << RESET << this->Name << " can't attack because it's exhausted!" << std::endl;
    else
    {
        this->EnergyPoints--;
        std::cout << CYAN << "ScavTrap " << RESET << this->Name << " attacks " << target <<", causing "<< this->AttackDamage <<" points of damage!" << std::endl;
    }
}

ScavTrap::~ScavTrap(void){
    std::cout << CYAN << "ScavTrap " << RESET << "destructor called" << std::endl;
}
