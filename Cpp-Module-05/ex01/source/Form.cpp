#include "../include/Form.hpp"
#include "../include/Bureaucrat.hpp"

Form::Form(const std::string name, const int gradeToSign, const int gradeToExecute):
_name(name),_signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute){
    if (_gradeToSign > 150 || _gradeToExecute > 150)
        throw (GradeTooLowException());
    else if (_gradeToSign < 1 || _gradeToExecute < 1)
        throw (GradeTooHighException());
    else
        std::cout << "Constructor called" << std::endl;
}


Form::Form(const Form &other):
_name(other._name), _signed(other._signed), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute){
    std::cout << "Copy constructor called" << std::endl;
}

Form &Form::operator=(const Form &other) {
    std::cout << " Assignment operator called" << std::endl;
    if (this != &other)
    {
        _signed = other._signed;
    }
    return (*this);
}

Form::~Form(void){
    std::cout << "Destructor called" << std::endl;

}


std::string Form::getName(void) const{
    return(this->_name);
}

bool Form::getSigned(void) const{
    return(this->_signed);
}

int Form::getGradeToSign(void) const{
    return(this->_gradeToSign);
}

int Form::getGradeToExecute(void) const{
    return(this->_gradeToExecute);
}

void Form::beSigned(Bureaucrat &Bureaucrat){
    if (Bureaucrat.getGrade() <= this->_gradeToSign)
        this->_signed = true;
    else
        throw Form::GradeTooLowException();
}


std::ostream &operator<<(std::ostream &out, const Form &form){
    out << "Form: " << form.getName() << "\nGrade to sign: " << form.getGradeToSign() << "\nGrade to execute: " << form.getGradeToExecute() << "\nis signed: " << form.getSigned() << std::endl;
    return (out);
}
