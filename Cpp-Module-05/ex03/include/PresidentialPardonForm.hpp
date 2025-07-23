#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"
# include <iostream>
# include <string>

# define PRES_SIGN 25
# define PRES_EXEC 5

class PresidentialPardonForm : public AForm{
    private:
        std::string _target;

    public:
        PresidentialPardonForm(std::string target);
        PresidentialPardonForm(const PresidentialPardonForm &other);
        PresidentialPardonForm &operator=(const PresidentialPardonForm &other);
        ~PresidentialPardonForm(void);

        void execute(Bureaucrat const & executor) const;
};



#endif
