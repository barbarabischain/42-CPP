#include "../include/PmergeMe.hpp"

/* Constructors */
PmergeMe::PmergeMe(void) {}

PmergeMe::PmergeMe(const PmergeMe &other): 
vector(other.vector),
deque(other.deque) {}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
    if (this != &other)
    {
        vector = other.vector;
        deque = other.deque;
    }
    return (*this);
}

PmergeMe::~PmergeMe(void) {}

/* Parsing */

void PmergeMe::parser(int argc, char **argv){
    if (argc < 2)
        throw std::invalid_argument("Usage: ./PmergeMe <arguments>");

    std::set<int>  duplicate_checker_set;
    for (int i = 1; i < argc; i++)
    {
        std::string value_str(argv[i]);
        if (value_str.empty())
            throw std::invalid_argument("empty value");
        for (size_t j = 0; j < value_str.size(); j++)
        {
            if (!isdigit(value_str[j]))
                throw std::invalid_argument("value is not a digit");
        }
        std::istringstream iss(value_str);
        int num;
        iss >> num;
        
        if (duplicate_checker_set.find(num) != duplicate_checker_set.end())
            throw std::invalid_argument("Duplicate value");
        duplicate_checker_set.insert(num);

        vector.push_back(num);
        deque.push_back(num);
    }
}
