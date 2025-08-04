#include "../include/Span.hpp"

Span::Span(unsigned int N): maxSize(N){}

Span::Span(const Span &other): maxSize(other.maxSize), elements(other.elements){}

Span &Span::operator=(const Span &other){
    if (this != &other)
    {
        this->elements = other.elements;
        this->maxSize = other.maxSize;
    }
    return (*this);
}

Span::~Span(void){}


void Span::addNumber(int number){
    if (elements.size() < maxSize)
        elements.push_back(number);
    else
        throw std::length_error("Span is full");
}

int Span::shortestSpan(void){
    if (elements.size() < 2)
        throw std::logic_error("Not enough elements to find a span");
    int shorter = std::numeric_limits<int>::max();
    std::vector<int>sortedElements = elements;
    std::sort(sortedElements.begin(), sortedElements.end());
    for (size_t i = 0; i < sortedElements.size() - 1; i++)
    {
        if (sortedElements[i + 1] - sortedElements[i] < shorter)
            shorter = sortedElements[i + 1] - sortedElements[i];
    }
    return(shorter);
}

int Span::longestSpan(void){
    if (elements.size() < 2)
        throw std::logic_error("Not enough elements to find a span");
    std::vector<int>sortedElements = elements;
    std::sort(sortedElements.begin(), sortedElements.end());
    return(sortedElements[sortedElements.size() -1] - sortedElements[0]);
}

void Span::fill(void){
    
}
