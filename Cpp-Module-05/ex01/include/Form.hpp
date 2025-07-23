#ifndef FORM_HPP
#define FORM_HPP

# include <iostream>
# include <string>
# include <exception>

class Bureaucrat;

class Form{
    private:
        const std::string _name;
        bool _signed;
        const int _gradeToSign;
        const int _gradeToExecute;
    public:

    Form(const std::string name, const int gradeToSign, const int gradeToExecute);
    Form(const Form &other);
    Form &operator=(const Form &other);
    ~Form(void);

    std::string getName(void) const;
    bool getSigned(void) const;
    int getGradeToSign(void) const;
    int getGradeToExecute(void) const;

    void beSigned(Bureaucrat &Bureaucrat);

    class GradeTooHighException: public std::exception
    {
        public:
        const char *what() const throw() {
            return("Error: Grade to High!");
        }
    };
    class GradeTooLowException : public std::exception
    {
        public:
        const char *what() const throw(){
            return("Error: Grade to Low!");
        }
    };
};

std::ostream &operator<<(std::ostream &out, const Form &form);


#endif
