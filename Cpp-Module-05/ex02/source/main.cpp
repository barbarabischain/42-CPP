#include "../include/Bureaucrat.hpp"
#include "../include/PresidentialPardonForm.hpp"
#include "../include/RobotomyRequestForm.hpp"
#include "../include/ShrubberyCreationForm.hpp"
#include "../include/AForm.hpp"


void  test_presidentialForm(void)
{
    Bureaucrat President("Mr. President", 1);
    Bureaucrat Secretary("Secretary",10);
    PresidentialPardonForm decree("Terrorist");
    std::cout << std::endl;

    //unsigned form
    President.executeForm(decree);

    //grade too low
    Secretary.signForm(decree); //signed form
    Secretary.executeForm(decree);

    //execute
    President.executeForm(decree);

    std::cout << std::endl;
}


void test_robotomyForm(void)
{
    Bureaucrat neuroSurgeon("Dr. Drillmore", 20);
    RobotomyRequestForm RobotomyProtocol("Alex DeLarge");
    std::cout << std::endl;

    neuroSurgeon.signForm(RobotomyProtocol);
    neuroSurgeon.executeForm(RobotomyProtocol);

    std::cout << std::endl;
}

void test_shrubberyForm(void)
{
    Bureaucrat Gardener("Willian Plantmore", 100);
    ShrubberyCreationForm azaleia("Azaleia");
    std::cout << std::endl;

    Gardener.signForm(azaleia);
    Gardener.executeForm(azaleia);

    std::cout << std::endl;
}

int main(void)
{
    std::cout << BPURPLE << "=== TEST PRESIDENTIAL PARDON FORM ===" << RESET << std::endl;
    test_presidentialForm();
    std::cout << std::endl;

    std::cout << BPURPLE << "=== TEST ROBOTOMY REQUEST FORM ===" << RESET << std::endl;
    test_robotomyForm();
    std::cout << std::endl;

    std::cout << BPURPLE << "=== TEST SHRUBBERY CREATION FORM ===" << RESET << std::endl;
    test_shrubberyForm();

    return (0);

}
