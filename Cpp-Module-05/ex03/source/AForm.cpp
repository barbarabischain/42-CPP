#include "../include/AForm.hpp"
#include "../include/Bureaucrat.hpp"

AForm::AForm(const std::string name, const int gradeToSign, const int gradeToExecute):
_name(name),_signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute){
    if (_gradeToSign > 150 || _gradeToExecute > 150)
        throw (GradeTooLowException());
    else if (_gradeToSign < 1 || _gradeToExecute < 1)
        throw (GradeTooHighException());
    else
        std::cout << "AForm Constructor called" << std::endl;
}


AForm::AForm(const AForm &other):
_name(other._name), _signed(other._signed), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute){
    std::cout << "AForm Copy constructor called" << std::endl;
}

AForm &AForm::operator=(const AForm &other) {
    std::cout << "AForm Assignment operator called" << std::endl;
    if (this != &other)
    {
        _signed = other._signed;
    }
    return (*this);
}

AForm::~AForm(void){
    std::cout << "AForm Destructor called" << std::endl;

}

std::string AForm::getName(void) const{
    return(this->_name);
}

bool AForm::getSigned(void) const{
    return(this->_signed);
}

int AForm::getGradeToSign(void) const{
    return(this->_gradeToSign);
}

int AForm::getGradeToExecute(void) const{
    return(this->_gradeToExecute);
}

void AForm::beSigned(Bureaucrat &Bureaucrat){
    if (Bureaucrat.getGrade() <= this->_gradeToSign)
        this->_signed = true;
    else
        throw AForm::GradeTooLowException();
}

std::ostream &operator<<(std::ostream &out, const AForm &form){
    out << "Form: " << form.getName() << "\nGrade to sign: " << form.getGradeToSign() << "\nGrade to execute: " << form.getGradeToExecute() << "\nis signed: " << form.getSigned() << std::endl;
    return (out);
}
