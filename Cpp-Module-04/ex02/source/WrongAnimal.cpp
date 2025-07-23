#include "../include/WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void): type("WrongAnimal"){
    std::cout << "WrongAnimal default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &other): type(other.type){
    std::cout << "WrongAnimal copy constructor called" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other){
    std::cout << "WrongAnimal assignment operator called" << std::endl;
    if (this != &other)
        this->type = other.type;
    return (*this);
}

WrongAnimal::~WrongAnimal(void){
    std::cout << "WrongAnimal destructor called" << std::endl;
}

std::string WrongAnimal::getType(void) const{
    return (this->type);
}

void WrongAnimal::makeSound() const{
    std::cout << "Wrong Animal sound" << std::endl;
}
