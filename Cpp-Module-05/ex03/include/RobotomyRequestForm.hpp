#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"

# include <time.h>
# include <stdlib.h>
# include <iostream>
# include <string>

# define ROB_SIGN 72
# define ROB_EXEC 45

class RobotomyRequestForm : public AForm{
    private:
        std::string _target;

    public:
        RobotomyRequestForm(std::string target);
        RobotomyRequestForm(const RobotomyRequestForm &other);
        RobotomyRequestForm &operator=(const RobotomyRequestForm &other);
        ~RobotomyRequestForm(void);

        std::string getTarget(void);
        void execute(Bureaucrat const & executor) const;

        class RobotomyFailed:public std::exception
        {
            public:
            const char *what() const throw(){
                return ("The patient ran away.");
            }
        };
};

#endif
