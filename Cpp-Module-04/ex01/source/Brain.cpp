#include "../include/Brain.hpp"

Brain::Brain(void){
    std::cout << "Brain default constructor called" << std::endl;
    for (int i = 0; i < 3; i++)
        this->ideas[i] = "food!";
}

Brain::Brain(const Brain &other){
    std::cout << "Brain copy constructor called" << std::endl;
    for (int i = 0; i < 100; i++)
        this->ideas[i] = other.ideas[i];
}

Brain &Brain::operator=(const Brain &other){
    std::cout << "Brain assignment operator called" << std::endl;
    if (this != &other)
    {
        for (int i = 0; i < 100; i++)
            ideas[i] = other.ideas[i];
    }
    return (*this);
}

Brain::~Brain(void){
    std::cout << "Brain destructor called" << std::endl;
}


void Brain::setIdeas(int index, const std::string &idea){
    if (index >= 0 && index < 100)
        this->ideas[index] = idea;
}

std::string Brain::getIdeas(int index) const{
    if (index >= 0 && index < 100)
        return (ideas[index]);
    return ("");
}
