#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void): Name(""), HitPoints(10), EnergyPoints(10), AttackDamage(0){
    std::cout << "Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name): Name(name), HitPoints(10), EnergyPoints(10), AttackDamage(0){
    std::cout << "Parametrized constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other): Name(other.Name), HitPoints(other.HitPoints), EnergyPoints(other.EnergyPoints), AttackDamage(other.AttackDamage){
    std::cout << "Copy constructor called" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other){
    std::cout << "Assignment operator called" << std::endl;
    if (this != &other)
    {
        this->Name = other.Name;
        this->HitPoints = other.HitPoints;
        this->EnergyPoints = other.EnergyPoints;
        this->AttackDamage = other.AttackDamage;
    }
    return (*this);

}

ClapTrap::~ClapTrap(void){
    std::cout << "Destructor called" << std::endl;
}

void ClapTrap::attack(const std::string& target){
    if (this->HitPoints <= 0)
    std::cout << "ClapTrap " << this->Name << " can't attack because it's already dead!" << std::endl;
    else if (this->EnergyPoints <= 0)
        std::cout << "ClapTrap " << this->Name << " can't attack because it's exhausted!" << std::endl;
    else
    {
        this->EnergyPoints--;
        std::cout << "ClapTrap "<< this->Name << " attacks " << target <<", causing "<< this->AttackDamage <<" points of damage!" << std::endl;
    }
}

void ClapTrap::takeDamage(unsigned int amount){
    if (this->HitPoints <= 0)
        std::cout << "ClapTrap " << this->Name << " is already dead and can't take more damage!" << std::endl;
    else
    {
        this->HitPoints = this->HitPoints - amount;
        std::cout << "ClapTrap " << this->Name << " takes " << amount << " points of damage!" << std::endl;
    }
    std::cout << "ClapTrap " << this->Name << " Hit Points: " << this->HitPoints << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount){
    if (this->HitPoints <= 0)
        std::cout << "ClapTrap " << this->Name << " can't be repaired because it's already dead!" << std::endl;
    else if (this->EnergyPoints <= 0)
        std::cout << "ClapTrap " << this->Name << " can't be repaired because it's exhausted!" << std::endl;
    else
    {
        this->HitPoints += amount;
        this->EnergyPoints--;
        std::cout << "ClapTrap " << this->Name << " repairs itself, recovering " << amount << " hit points!" << std::endl;
        std::cout << "ClapTrap " << this->Name << " Hit Points: " << this->HitPoints << std::endl;
    }
}



std::string ClapTrap::getName(void) const{
    return(this->Name);
}

int ClapTrap::getHitPoints(void) const{
    return(this->HitPoints);
}

int ClapTrap::getEnergyPoints(void) const{
    return(this->EnergyPoints);
}

int ClapTrap::getAttackDamage(void) const{
    return(this->AttackDamage);
}

void ClapTrap::setHitPoints(unsigned int points){
    this->HitPoints = points;
}

void ClapTrap::setEnergyPoints(unsigned int points){
    this->EnergyPoints = points;
}

void ClapTrap::setAttackDamage(unsigned int damagePoints){
    this->AttackDamage = damagePoints;
}
