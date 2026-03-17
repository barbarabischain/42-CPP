#include "../include/PmergeMe.hpp"

/* Constructors */
PmergeMe::PmergeMe(void) {}

PmergeMe::PmergeMe(const PmergeMe &other): 
deque(other.deque),
vector(other.vector) {}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
    if (this != &other)
    {
        deque = other.deque;
        vector = other.vector;
    }
    return (*this);
}

PmergeMe::~PmergeMe(void) {}

/* Parsing */




bool PmergeMe::isValidNumber(std::string input){

}

bool PmergeMe::isSorted(std::vector<int> &container){

}