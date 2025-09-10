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


    std::cout << GREEN << "\n=== TEST FILL 15000 ELEMENTS ===" << RESET << std::endl;
    try
    {
        Span sp = Span(15000);

        std::list<int> list_numbers;
        for (int i = 0; i < 15000; i++)
            list_numbers.push_back(i + 1 * 10);

        sp.fill(list_numbers.begin(), list_numbers.end());

        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    std::cout << GREEN << "\n=== TEST EMPTY LIST FILL ===" << RESET << std::endl;
    try
    {
        Span sp = Span(10);
        std::list<int> list_numbers;

        sp.fill(list_numbers.begin(), list_numbers.end());
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    std::cout << GREEN << "\n=== TEST FILL OVERFLOW ===" << RESET << std::endl;
    try
    {
        Span sp = Span(10);
        std::list<int> list_numbers;

        for (int i = 0; i < 11; i++)
            list_numbers.push_back(i);

        sp.fill(list_numbers.begin(), list_numbers.end());
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
}
