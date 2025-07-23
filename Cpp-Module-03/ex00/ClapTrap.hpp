#ifndef CLAPTRAP
# define CLAPTRAP

# include <string>
# include <iostream>

# define BGREEN "\033[1;32m"
# define RESET  "\033[0m"

class ClapTrap{
    private:
        std::string Name;
        int HitPoints;
        int EnergyPoints;
        int AttackDamage;
    public:
        ClapTrap(void);
        ClapTrap(std::string Name);
        ClapTrap(const ClapTrap &other);
        ClapTrap &operator=(const ClapTrap &other);
        ~ClapTrap(void);
        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);

        std::string getName(void) const;
        int getHitPoints(void) const;
        int getEnergyPoints(void) const;
        int getAttackDamage(void) const;

        void setHitPoints(unsigned int points);
        void setEnergyPoints(unsigned int points);
        void setAttackDamage(unsigned int damagePoints);
};

#endif
