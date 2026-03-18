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
        void printContainer(T_container& container) {
            typename T_container::iterator it = container.begin();
            while (it != container.end()) {
                std::cout << *it << " ";
                it++;
            }
            std::cout << std::endl;
        }
};

#endif