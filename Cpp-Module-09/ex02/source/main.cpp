#include "../include/PmergeMe.hpp"

int main(int argc, char **argv)
{
    try {
        PmergeMe sorter;
        sorter.parser(argc, argv);
        // sorter.sortVector(argc, argv);
        // sorter.sortDeque(argc, argv);
    } catch (std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    return (0);
}