#include "../include/WrongAnimal.hpp"
#include "../include/WrongCat.hpp"


WrongCat::WrongCat(void) : WrongAnimal(){
    type = "WrongCat";
    std::cout << "WrongCat default constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &other) : WrongAnimal(other){
    std::cout << "WrongCat copy constructor called" << std::endl;
    this->type = other.type;
}

WrongCat &WrongCat::operator=(const WrongCat &other){
    std::cout << "WrongCat assignment operator called" << std::endl;
    if (this != &other)
        this->type = other.type;
    return (*this);
}

WrongCat::~WrongCat(void){
    std::cout << "WrongCat destructor called" << std::endl;
}

void WrongCat::makeSound() const{
    std::cout << "Meeeeoooow!" << std::endl;
}
