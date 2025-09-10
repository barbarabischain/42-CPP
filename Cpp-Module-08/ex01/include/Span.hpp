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

        template<typename IT>
        void fill(IT begin, IT end){
            unsigned int distance = std::distance(begin, end);
            if (distance > maxSize)
                throw std::overflow_error("The range exceeds the maximum allowed size.");
            else if (distance == 0)
                throw std::invalid_argument("The range must contain at least one element.");
            elements.insert(elements.end(), begin, end);

            // for (unsigned int i = 0; i < distance; i++)
            //     std::cout << elements[i] << " ";
            // std::cout << "\n";
        };
};

#endif
