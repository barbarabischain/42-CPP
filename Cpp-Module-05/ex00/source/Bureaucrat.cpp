#include "../include/Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): _name("default name"), _grade(150){
    std::cout << "Default constructor called" << std::endl;
}


Bureaucrat::Bureaucrat(const std::string name, int grade): _name(name){
    std::cout << "Parameterized constructor called" << std::endl;
    if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
    else if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    this->_grade = grade;
}


Bureaucrat::Bureaucrat(const Bureaucrat &other): _name(other._name), _grade(other._grade){
    std::cout << "Copy constructor called" << std::endl;
}


Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other){
    std::cout << "Assignment operator called" << std::endl;
    if (this != &other)
        this->_grade = other._grade;
    return(*this);
}

Bureaucrat::~Bureaucrat(void){
    std::cout << "Destructor called" << std::endl;
}


const std::string Bureaucrat::getName(void) const{
    return(this->_name);
}

int Bureaucrat::getGrade(void) const{
    return(this->_grade);
}

void Bureaucrat::incrementGrade(void){
    if (this->_grade <= 1)
        throw Bureaucrat::GradeTooHighException();
    else
        this->_grade--;
}

void Bureaucrat::decrementGrade(void){
    if (this->_grade >= 150)
       throw Bureaucrat::GradeTooLowException();
    else
        this->_grade++;
}


std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat){
    out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
    return out;
}
