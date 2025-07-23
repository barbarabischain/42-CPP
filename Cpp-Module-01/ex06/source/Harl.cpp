#include "../include/Harl.hpp"

Harl::Harl(void){}
Harl::~Harl(void){}

void Harl::debug(void){
    std::cout << GREEN << "[DEBUG]\n" << RESET << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!\n" << std::endl;
}

void Harl::info(void){
    std::cout << BLUE << "[INFO]\n" << RESET << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!\n" << std::endl;
}

void Harl::warning(void){
    std::cout << YELLOW << "[WARNING]\n" << RESET <<  "I think I deserve to have some extra bacon for free. I’ve been coming for years, whereas you started working here just last month.\n" << std::endl;
}

void Harl::error(void){
    std::cout << RED << "[ERROR]\n" << RESET << "This is unacceptable! I want to speak to the manager now.\n" << std::endl;
}

void Harl::complain(std::string level){
    std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    int i;
    for (i = 0; i < 4; i++)
    {
        if (level == levels[i])
            break;
    }
    switch(i)
    {
        case 0:
            this->debug();
        case 1:
            this->info();
        case 2:
            this->warning();
        case 3:
            this->error();
            break;
        default:
            std::cout << "[Probably complaining about insignificant problems]" << std::endl;
    }
}
