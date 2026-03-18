#ifndef PMERGEME_HPP
# define PPMERGEME_HPP

# include <iostream>
# include <deque>
# include <vector>
# include <set>
# include <iomanip>
# include <algorithm>
# include <ctime>
# include <sstream>

class PmergeMe{
    private:
        // int								size;
        std::vector<int>		        vector;
        std::deque<int>			        deque;

    public:
        PmergeMe(void);
        PmergeMe(const PmergeMe &other);
        PmergeMe &operator=(const PmergeMe &other);
        ~PmergeMe(void);


        void parser(int argc, char **argv);
        // bool isSorted(std::vector<int> &container);
};

#endif