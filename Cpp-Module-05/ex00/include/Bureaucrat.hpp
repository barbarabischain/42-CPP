#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include <exception>

# define GREEN			"\033[32m"
# define CYAN			"\033[36m"
# define RESET			"\033[0m"

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
