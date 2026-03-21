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
        std::vector<int>		        vector;
        std::deque<int>			        deque;

        void sortVector(void);
        void sortDeque(void);

    public:
        PmergeMe(void);
        PmergeMe(const PmergeMe &other);
        PmergeMe &operator=(const PmergeMe &other);
        ~PmergeMe(void);

        std::vector<size_t> generateJacobsthalOrder(size_t n);

        void parseInput(int argc, char **argv);
        void executeSort(void);

        template <typename T_container>
        bool is_sorted(T_container& container){
            typename T_container::iterator it = container.begin();
            typename T_container::iterator next = it;
            next++;
            while (next != container.end())
            {
                if (*next < *it) 
                    return false;
                it++;
                next++;
            }
            return true;
        }


        template <typename T_container>
        void printContainer(const T_container& container) {
            typename T_container::const_iterator it = container.begin();
            while (it != container.end()) {
                std::cout << *it << " ";
                ++it;
            }
            std::cout << std::endl;
        }

        template <typename Container>
        void binaryInsert(Container& container, int value)
        {
            size_t low = 0;
            size_t high = container.size();

            while (low < high)
            {
                size_t mid = low + (high - low) / 2;

                if (container[mid] < value)
                    low = mid + 1;
                else
                    high = mid;
            }
            container.insert(container.begin() + low, value);
        }
};

#endif