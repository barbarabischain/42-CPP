#ifndef SPAN_HPP
# define SPAN_HPP

# define GREEN "\033[1;32m"
# define RED   "\033[1;31m"
# define RESET "\033[0m"

# include <vector>
# include <iostream>
# include <algorithm>
# include <limits>
# include <stdexcept>

class Span{
    private:
        unsigned int        maxSize;
        std::vector<int>    elements;

    public:
        Span(unsigned int N);
        Span(const Span &other);
        Span &operator=(const Span &other);
        ~Span(void);

        void addNumber(int number);
        int shortestSpan(void);
        int longestSpan(void);
        void fill(void); //implementar
};

#endif
