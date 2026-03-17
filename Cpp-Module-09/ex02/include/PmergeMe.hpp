#ifndef PMERGEME_HPP
# define PPMERGEME_HPP

# include <deque>
# include <vector>
# include <iomanip>
# include <algorithm>
# include <ctime>

class PmergeMe{
    private:
        int								size;
        std::vector<int>				input;
        std::vector<int>		        vector;
        std::deque<int>			        deque;

    public:
        PmergeMe(void);
        PmergeMe(const PmergeMe &other);
        PmergeMe &operator=(const PmergeMe &other);
        ~PmergeMe(void);


        bool isValidNumber(std::string input);
        bool isSorted(std::vector<int> &container);
};

#endif