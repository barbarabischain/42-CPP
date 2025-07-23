#include "../include/AForm.hpp"
#include "../include/Bureaucrat.hpp"
#include "../include/RobotomyRequestForm.hpp"


RobotomyRequestForm::RobotomyRequestForm(std::string target)
: AForm("Robotomy Request Form", ROB_SIGN, ROB_EXEC), _target(target){
    std::cout << "Robotomy constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other)
: AForm(other), _target(other._target)
{
    std::cout << "Robotomy Copy constructor called" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other){
    std::cout << "Robotomy assignment operator called" << std::endl;
    if (this != &other)
        this->_target = other._target;
    return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm(void){
    std::cout << "Robotomy Copy destructor called" << std::endl;

}

std::string RobotomyRequestForm::getTarget(void){
    return(this->_target);
}


void RobotomyRequestForm::execute(Bureaucrat const & executor) const{
    if (!this->getSigned())
        throw(AForm::FormNotSignedException());
    else if (executor.getGrade() > ROB_EXEC)
        throw(AForm::GradeTooLowException());
    else if ((rand() + clock()) % 2 == 0)
        std::cout << BYELLOW <<"Brrr-zzz-zzzt!\n" << this->_target << "  has been successfully robotomized!" <<  RESET <<std::endl;
    else
    {
        std::cout << BYELLOW <<"The drill overheated and " << this->_target << " ran away screaming!\nRobotomization failed!" <<  RESET <<std::endl;
        throw(RobotomyRequestForm::RobotomyFailed());
    }
}
