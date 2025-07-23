#include "../include/Animal.hpp"

Animal::Animal(void): type("Animal"){
    std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(const Animal &other): type(other.type){
    std::cout << "Animal copy constructor called" << std::endl;
}

Animal &Animal::operator=(const Animal &other){
    std::cout << "Animal assignment operator called" << std::endl;
    if (this != &other)
        this->type = other.type;
    return (*this);
}

Animal::~Animal(void){
    std::cout << "Animal destructor called" << std::endl;
}

std::string Animal::getType(void) const{
    return (this->type);
}

void Animal::makeSound() const{
    std::cout << "Generic animal sound" << std::endl;
}
