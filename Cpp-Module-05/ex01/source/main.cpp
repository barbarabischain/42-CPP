#include "../include/Bureaucrat.hpp"
#include "../include/Form.hpp"


void test_constructions(void)
{
    try
    {
        Form A("Certidao", 50, 100);
        Form B(A);
        std::cout << BCYAN << B << RESET << std::endl;
    }
    catch(std::exception& e)
    {
        std::cout << RED << e.what() << RESET <<std::endl;
    }

    try
    {
        Form C("Atestado", 151, 70);
        std::cout << BCYAN << C << RESET << std::endl;
    }
    catch(std::exception& e)
    {
        std::cout << RED << e.what() << RESET <<std::endl;
    }

    try
    {
        Form D("Document D", 30, 0);
        std::cout << BCYAN << D << RESET << std::endl;
    }
    catch(std::exception& e)
    {
        std::cout << RED << e.what() << RESET <<std::endl;

    }
}

void test_signForm(void)
{
    Form E("Document E", 50, 100);
    Bureaucrat Director("Maria", 15);
    Director.signForm(E);

    Form F("Document F", 50, 100);
    Bureaucrat Officer("Joao", 140);
    Officer.signForm(F);

}


int main(void)
{
    std::cout << GREEN << "=== TEST CONSTRUCTORS ===" <<  RESET << std::endl;
    test_constructions();
    std::cout << std::endl;

    std::cout << GREEN << "=== TEST SIGN FORM ===" <<  RESET << std::endl;
    test_signForm();

    return (0);
}
