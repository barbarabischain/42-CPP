#include "../include/Animal.hpp"
#include "../include/Cat.hpp"


Cat::Cat(void) : Animal(){
    type = "Cat";
    std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(const Cat &other): Animal(other){
    std::cout << "Cat copy constructor called" << std::endl;
    this->type = other.type;
}

Cat &Cat::operator=(const Cat &other){
    std::cout << "Cat assignment operator called" << std::endl;
    if (this != &other)
        this->type = other.type;
    return (*this);
}

Cat::~Cat(void){
    std::cout << "Cat destructor called" << std::endl;
}

void Cat::makeSound() const{
    std::cout << "Meeeeoooow!" << std::endl;
}
