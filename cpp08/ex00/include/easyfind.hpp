#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <exception>
# include <vector>
# include <list>
#include <deque>
# include <algorithm>


# define GREEN "\033[1;32m"
# define RED   "\033[1;31m"
# define RESET "\033[0m"

template<typename T>
typename T::iterator easyfind(T &container, int n)
{
    typename T::iterator it = find(container.begin(), container.end(), n);
    if (it != container.end())
        return (it);
    throw std::runtime_error("Value not found!");
}



#endif
