#include "../include/Bureaucrat.hpp"
#include "../include/PresidentialPardonForm.hpp"
#include "../include/RobotomyRequestForm.hpp"
#include "../include/ShrubberyCreationForm.hpp"
#include "../include/AForm.hpp"
#include "../include/Intern.hpp"


int main(void)
{
    try
    {
        Bureaucrat gardener("Bob", 50);
        Intern student;
        AForm *form = student.makeForm("shrubbery creation", "apple tree");
        gardener.signForm(*form);
        gardener.executeForm(*form);
        delete form;
    }
    catch(std::exception &e)
    {
        std::cout << RED << "Error: " << e.what() << RESET << std::endl;
    }
    std::cout << std::endl;
    try
    {
        Bureaucrat president("Maria", 1);
        Intern student;
        AForm *form = student.makeForm("wrong form", "wrong");
        president.signForm(*form);
        president.executeForm(*form);
        delete form;
    }
    catch(std::exception &e)
    {
        std::cout << RED << "Error: " << e.what() << RESET << std::endl;
    }
    return (0);
}
