#ifndef SHRUBBERYCREATION_FORM_HPP
# define SHRUBBERYCREATION_FORM_HPP

# include "AForm.hpp"
# include <fstream>
# include <iostream>
# include <string>

# define SHRUB_SIGN 145
# define SHRUB_EXEC 137

class ShrubberyCreationForm : public AForm{
    private:
        std::string _target;

    public:
        ShrubberyCreationForm(std::string target);
        ShrubberyCreationForm(const ShrubberyCreationForm &other);
        ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other);
        ~ShrubberyCreationForm(void);

        void execute(Bureaucrat const & executor) const;
};



#endif
