#include "../include/Animal.hpp"
#include "../include/Dog.hpp"


Dog::Dog(void) : Animal(){
    type = "Dog";
    std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(const Dog &other): Animal(other){
    std::cout << "Dog copy constructor called" << std::endl;
    this->type = other.type;
}

Dog &Dog::operator=(const Dog &other){
    std::cout << "Dog assignment operator called" << std::endl;
    if (this != &other)
        this->type = other.type;
    return (*this);
}

Dog::~Dog(void){
    std::cout << "Dog destructor called" << std::endl;
}

void Dog::makeSound() const{
    std::cout << "Woof! Woof!" << std::endl;
}
