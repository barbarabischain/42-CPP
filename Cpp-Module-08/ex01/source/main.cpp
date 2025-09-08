#include "../include/Span.hpp"
#include <deque>
#include <list>

int main(void)
{
    std::cout << GREEN << "=== TEST PDF ===" << RESET << std::endl;
    try
    {
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);

        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    std::cout << GREEN << "\n=== TEST FULL SPAN ===" << RESET << std::endl;
    try
    {
        Span sp = Span(4);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);

        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    std::cout << GREEN << "\n=== TEST ONE ELEMENT ===" << RESET << std::endl;
    try
    {
        Span sp = Span(1);
        sp.addNumber(6);

        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }


    // std::cout << GREEN << "\n=== TEST 15000 ===" << RESET << std::endl;
    // try
    // {
    //     Span sp = Span(15000);
    //     //metodo para preencher

    //     std::cout << sp.shortestSpan() << std::endl;
    //     std::cout << sp.longestSpan() << std::endl;
    // }
    // catch(const std::exception& e)
    // {
    //     std::cerr << e.what() << std::endl;
    // }

    std::cout << GREEN << "\n=== TEST FILL ===" << RESET << std::endl;
    try
    {
        Span sp = Span(10);
        std::list<int> numbers;
        for (int i = 0; i < 10; i++)
            numbers.push_back(i + 1 * 10);

        std::list<int>::iterator it;
        for (it = numbers.begin(); it != numbers.end(); it++)
            std::cout << *it << " ";
        std::cout << "\n";

        sp.fill(numbers.begin(), numbers.end());

    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
}
