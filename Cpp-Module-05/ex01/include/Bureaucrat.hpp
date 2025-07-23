#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include <exception>

# define GREEN			"\033[32m"
# define CYAN			"\033[36m"
# define BCYAN			"\033[1;36m"
# define RESET			"\033[0m"
# define RED            "\33[1;31m"
# define BPURPLE         "\033[1;35m"
class Form;

class Bureaucrat{
    private:
        const std::string _name;
        int _grade;
    public:
        Bureaucrat(void);
        Bureaucrat(const std::string name, int grade);
        Bureaucrat(const Bureaucrat &other);
        Bureaucrat &operator=(const Bureaucrat &other);
        ~Bureaucrat(void);

        const std::string getName(void) const;
        int getGrade(void)const;
        void incrementGrade(void);
        void decrementGrade(void);

        void signForm(Form &form);

        class GradeTooHighException:public std::exception
        {
            public:
            const char *what() const throw(){
                return ("Bureaucrat grade cannot be higher than 1");
            }
        };
        class GradeTooLowException:public std::exception
        {
            public:
            const char *what() const throw(){
                return ("Bureaucrat grade cannot be lower than 150");
            }
        };
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat);

#endif
