#include "../include/PresidentialPardonForm.hpp"
#include "../include/Bureaucrat.hpp"


PresidentialPardonForm::PresidentialPardonForm(std::string target)
: AForm("Presidential Pardon Form", PRES_SIGN, PRES_EXEC), _target(target){
    std::cout << "Presidential constructor called"  << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other)
: AForm(other), _target(other._target)
{
    std::cout << "Presidential Copy constructor called" << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other){
    std::cout << "Presidential assignment operator called" << std::endl;
    if (this != &other)
        this->_target = other._target;
    return(*this);
}

PresidentialPardonForm::~PresidentialPardonForm(void){
    std::cout << "Presidential Copy destructor called" << std::endl;
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const{
    if (!this->getSigned())
        throw(AForm::FormNotSignedException());
    else if (executor.getGrade() > PRES_EXEC)
        throw(AForm::GradeTooLowException());
    else
        std::cout << BCYAN << "Informs that "<< this->_target  <<" has been pardoned by Zaphod Beeblebrox."<< RESET << std::endl;
}
