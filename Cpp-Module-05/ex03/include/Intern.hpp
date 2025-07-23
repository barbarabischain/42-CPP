#include "../include/Bureaucrat.hpp"
#include "../include/PresidentialPardonForm.hpp"
#include "../include/RobotomyRequestForm.hpp"
#include "../include/ShrubberyCreationForm.hpp"
#include "../include/AForm.hpp"

class Intern{
    public:
        Intern(void);
        Intern(const Intern &other);
        Intern &operator=(const Intern &other);
        ~Intern(void);

        AForm *makeForm(std::string FormName, std::string target);
};
