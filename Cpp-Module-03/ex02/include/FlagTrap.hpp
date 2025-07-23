#ifndef FLAGTRAP_HPP
# define FLAGTRAP_HPP

# include "ClapTrap.hpp"

class FlagTrap: public ClapTrap{
    public:
        FlagTrap(void);
        FlagTrap(std::string Name);
        FlagTrap(const FlagTrap &other);
        FlagTrap &operator=(const FlagTrap &other);
        ~FlagTrap(void);
        void attack(const std::string& target);
        void highFivesGuys(void);
};

#endif
