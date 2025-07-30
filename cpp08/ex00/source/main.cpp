#include "../include/easyfind.hpp"

int main(void)
{
    std::cout << GREEN <<"=== TESTE VECTOR ===" <<  RESET << std::endl;
    try
    {
        std::vector<int> vect;

        for (int i = 0; i < 10; i++)
        vect.push_back(i);

        for (size_t i = 0; i < vect.size(); i++)
            std::cout << vect[i] <<  ' ';
        std::cout << std::endl;

        std::vector<int>::iterator it = easyfind(vect, 5);
        std::cout << "found iterator: " << *it << std::endl;
    }
    catch(std::exception &e)
    {
        std::cout << RED <<"Error: " << e.what() << RESET << std::endl;
    }

    std::cout << GREEN <<"\n=== TESTE LIST ===" <<  RESET << std::endl;
    try
    {
        std::list<int> lst;
        for (int i = 0; i < 5; i++)
            lst.push_back(i * 10);

        for (std::list<int>::iterator it = lst.begin(); it != lst.end(); it++)
            std::cout << *it << ' ';
        std::cout << std::endl;

        std::list<int>::iterator it = easyfind(lst, 40);
        std::cout << "found iterator: " << *it << std::endl;

    }
    catch(const std::exception& e)
    {
        std::cerr << RED << "ERROR: " << e.what() << RESET << std::endl;
    }

        std::cout << GREEN <<"\n=== TESTE DEQUE ===" <<  RESET << std::endl;
    try
    {
        std::deque<int> dq;
        for (int i = 0; i < 6; i++)
            dq.push_back(i * 2);

        for (std::deque<int>::iterator it = dq.begin(); it != dq.end(); it++)
            std::cout << *it << ' ';
        std::cout << std::endl;

        std::deque<int>::iterator it = easyfind(dq, 2);
        std::cout << "found iterator: " << *it << std::endl;

    }
    catch(const std::exception& e)
    {
        std::cerr << RED << "ERROR: " << e.what() << RESET << std::endl;
    }

}
