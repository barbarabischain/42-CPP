#include "../include/PmergeMe.hpp"

int main(int argc, char **argv)
{
    try {
        PmergeMe sorter;
        sorter.parseInput(argc, argv);
        sorter.executeSort();

    } catch (std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    return (0);
}