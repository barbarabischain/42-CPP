#include "../include/Bureaucrat.hpp"


void test_construction_valid(void)
{
    try
    {
    Bureaucrat A("Ana", 150);
    std::cout << A << std::endl;

    Bureaucrat B(A);
    std::cout << B << std::endl;
    }
    catch (std::exception& e){
        std::cout << "Error: " << e.what() << std::endl;
    }
    std::cout << "------------------------" << std::endl;

    try
    {
    Bureaucrat C("Juliana", 1);
    std::cout << C << std::endl;
    Bureaucrat D(C);
    std::cout << D << std::endl;

    }
    catch (std::exception& e){
        std::cout << "Error: " << e.what() << std::endl;
    }
}


void test_construction_invalid(void)
{
    try
    {
    Bureaucrat E("Viviane", 151);
    std::cout << E << std::endl;

    Bureaucrat F(E);
    std::cout << F << std::endl;
    }
    catch (std::exception& e){
        std::cout << "Error: " << e.what() << std::endl;
    }
    std::cout << "------------------------" << std::endl;
    try
    {
    Bureaucrat G("Gabriel", 0);
    std::cout << G << std::endl;
    Bureaucrat H(G);
    std::cout << H << std::endl;

    }
    catch (std::exception& e){
        std::cout << "Error: " << e.what() << std::endl;
    }
}

void test_decrement(void)
{
    try
    {
    Bureaucrat I("Patricia", 50);
    I.decrementGrade();
    std::cout << I << std::endl;
    }
    catch(std::exception& e){
        std::cout << "Error: " << e.what() << std::endl;
    }
    std::cout << "------------------------" << std::endl;
    try
    {
        Bureaucrat J("Fabricio", 150);
        J.decrementGrade();
        std::cout << J << std::endl;
    }
    catch(std::exception& e){
        std::cout << "Error: " << e.what() << std::endl;
    }
}


void test_increment(void)
{
    try
    {
        Bureaucrat K("Carlos", 10);
        K.incrementGrade();
        std::cout << K << std::endl;
    }
        catch(std::exception& e){
        std::cout << "Error: " << e.what() << std::endl;
    }
    std::cout << "------------------------" << std::endl;
    try
    {
        Bureaucrat L("Lucas", 1);
        L.incrementGrade();
        std::cout << L << std::endl;
    }
    catch(std::exception& e){
        std::cout << "Error: " << e.what() << std::endl;
    }
}

void test_assignement(void)
{
    try
    {
        Bureaucrat M("Leo", 90);
        Bureaucrat N = M;
        std::cout << M << std::endl;
        std::cout << N << std::endl;
    }
    catch(std::exception& e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }
}

int main(void)
{
    std::cout << GREEN <<" ===TEST VALID CONSTRUCTION===" << RESET << std::endl;
    test_construction_valid();
    std::cout << GREEN <<" ===TEST INVALID CONSTRUCTION===" << RESET << std::endl;
    test_construction_invalid();
    std::cout << std::endl;
    std::cout << GREEN <<" ===TEST DECREMENT===" << RESET <<std::endl;
    test_decrement();
    std::cout << std::endl;
    std::cout << GREEN <<" ===TEST INCREMENT==="<< RESET << std::endl;
    test_increment();
    std::cout << std::endl;
    std::cout << GREEN <<" ===TEST ASSIGNEMENT==="<< RESET << std::endl;
    test_assignement();

    return (0);
}
