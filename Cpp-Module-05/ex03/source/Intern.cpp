#include "../include/Intern.hpp"
#include "../include/Bureaucrat.hpp"
#include "../include/PresidentialPardonForm.hpp"
#include "../include/RobotomyRequestForm.hpp"
#include "../include/ShrubberyCreationForm.hpp"
#include "../include/AForm.hpp"


Intern::Intern(void){
    std::cout << "Intern constructor constructed called" << std::endl;
}

Intern::Intern(const Intern &other){
    std::cout << "Intern Copy constructor constructed called" << std::endl;
    *this = other;
}

Intern &Intern::operator=(const Intern &other){
    std::cout << "Intern assignment operator called" << std::endl;
    (void) other;
    return(*this);
}

Intern::~Intern(void){
    std::cout << "Intern destructor constructed" << std::endl;
}

AForm *Intern::makeForm(std::string FormName, std::string target){
    std::string forms[] = {"shrubbery creation", "robotomy request", "presidential pardon"};
    int i;
    for (i = 0; i < 3; i++)
    {
        if(FormName == forms[i])
            break;
    }
    switch (i)
    {
    case 0:
        return new ShrubberyCreationForm(target);
    case 1:
         return new RobotomyRequestForm(target);
    case 2:
        return new PresidentialPardonForm(target);
    default:
        throw std::invalid_argument("Invalid form!");
        return NULL;
    }
}
