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

void PmergeMe::parseInput(int argc, char **argv){
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


void PmergeMe::executeSort(void){
    if (is_sorted(vector)){
        std::cout << "Already sorted" << std::endl;
    }

    // clock_t start, end;
    // double vectorTime, dequeTime;

    std::cout << "Before: ";
    printContainer(vector);

    // start = clock();
    sortVector();
    // end = clock();
    // vectorTime =  static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000;

    // start = clock();
    // sortDeque();
    // end = clock();
    // dequeTime = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000;

    std::cout << "After: ";
    printContainer(vector);
}


void printpairs(const std::vector<std::pair<int, int> >& pairs)
{
    for (size_t i = 0; i < pairs.size(); i++)
    {
        std::cout << "(" 
                << pairs[i].first << ", " 
                << pairs[i].second << ") ";
    }
    std::cout << std::endl;
}

void PmergeMe::sortVector(void){
    int     leftoverElement = -1;
    bool    hasLeftover = false;

    if (vector.size() % 2 != 0)
    {
        hasLeftover = true;
        leftoverElement = vector.back();
        vector.pop_back();
    }

    //separa em pares e ordena internamente
    std::vector<std::pair<int, int> > pairs;
    for (size_t i = 0; i < vector.size(); i += 2)
    {
        if (vector[i] < vector[i + 1])
            pairs.push_back(std::make_pair(vector[i + 1], vector[i]));
        else
            pairs.push_back(std::make_pair(vector[i], vector[i + 1]));
    }

    //ordena os pares de acordo com o maior numero
    for (size_t i = 0; i < pairs.size(); i++)
    {
        for (size_t j = 0; j < pairs.size() - i - 1; j++)
        {
            if (pairs[j].first > pairs[j + 1].first)
            {
                std::pair<int, int> temp = pairs[j];
                pairs[j] = pairs[j + 1];
                pairs[j + 1] = temp;
            }
        }
    }

    // cria a sequencia com os elementos maiores
    std::vector<int> mainchain;
    for (size_t i = 0; i < pairs.size(); i++)
    {
        mainchain.push_back(pairs[i].first);
    }

    // mainchain.insert(mainchain.begin(), pairs[0].first);
    
    std::cout << "mainchain maiores: " ;
    printContainer(mainchain);

    for (size_t i = 0; i < pairs.size(); i++)
    {
        int value = pairs[i].second;
        int low = 0;
        int high = mainchain.size();
        
        // Binary search to find insertion position
        while (low < high)
        {
            int mid = low + (high - low) / 2;
            if (mainchain[mid] < value)
                low = mid + 1;
            else
                high = mid;
        }
        mainchain.insert(mainchain.begin() + low, value);
    }

        if (hasLeftover)
    {
        int low = 0;
        int high = mainchain.size();
        
        // Binary search to find insertion position for odd element
        while (low < high)
        {
            int mid = low + (high - low) / 2;
            if (mainchain[mid] < leftoverElement)
                low = mid + 1;
            else
                high = mid;
        }
        
        mainchain.insert(mainchain.begin() + low, leftoverElement);
    }

    vector = mainchain;
    printContainer(mainchain);

}


std::vector<size_t> PmergeMe::generateJacobsthalOrder(size_t n)
{
    std::vector<size_t> jacob;
    std::vector<size_t> order;

    jacob.push_back(0);
    jacob.push_back(1);

    while (jacob.back() < n)
    {
        size_t size = jacob.size();
        jacob.push_back(jacob[size - 1] + 2 * jacob[size - 2]);
    }
    
    size_t prev = 1;
    for (size_t i = 2; i < jacob.size(); i++)
    {
        size_t curr = jacob[i];

        for (size_t j = std::min(curr, n); j > prev; j--)
        {
            order.push_back(j - 1); // índice do b_i
        }

        prev = curr;
        if (prev >= n)
            break;
    }
    std::cout << "order: ";
    printContainer(order);

    return order;
}