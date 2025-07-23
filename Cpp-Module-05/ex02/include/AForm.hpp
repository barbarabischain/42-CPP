#ifndef AFORM_HPP
#define AFORM_HPP

# include <iostream>
# include <string>
# include <exception>

class Bureaucrat;

class AForm{
    private:
        const std::string _name;
        bool _signed;
        const int _gradeToSign;
        const int _gradeToExecute;

    // protected:
    //     bool isFormExecutable(const Bureaucrat &executor)const;

    public:
    AForm(const std::string name, const int gradeToSign, const int gradeToExecute);
    AForm(const AForm &other);
    AForm &operator=(const AForm &other);
    virtual ~AForm(void);

    std::string getName(void) const;
    bool getSigned(void) const;
    int getGradeToSign(void) const;
    int getGradeToExecute(void) const;

    void beSigned(Bureaucrat &Bureaucrat);

    virtual void execute(Bureaucrat const & executor) const = 0;


    class GradeTooHighException: public std::exception
    {
        public:
        const char *what() const throw() {
            return("Grade too High!");
        }
    };
    class GradeTooLowException : public std::exception
    {
        public:
        const char *what() const throw(){
            return("Grade too Low!");
        }
    };
    class FormNotSignedException : public std::exception
    {
        public:
        const char *what() const throw(){
            return("Form is not signed!");
        }
    };
};

std::ostream &operator<<(std::ostream &out, const AForm &form);


#endif
