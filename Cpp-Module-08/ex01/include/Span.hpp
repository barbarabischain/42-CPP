#ifndef SPAN_HPP
# define SPAN_HPP

class Span{
    private:
        

    public:
        Span(unsigned int N);
        Span(const Span &other);
        Span &operator=(const Span &other);
        ~Span(void);

        void addNumber(int number);
        int shortestSpan(void);
        int longestSpan(void);
};

#endif
