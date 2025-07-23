#include "../include/AAnimal.hpp"
#include "../include/Dog.hpp"

Dog::Dog(void) : AAnimal(){
    std::cout << "Dog default constructor called" << std::endl;
    type = "Dog";
    this->brain = new Brain();
}

Dog::Dog(const Dog &other): AAnimal(other){
    std::cout << "Dog copy constructor called" << std::endl;
    this->brain = new Brain(*other.brain);
}

Dog &Dog::operator=(const Dog &other){
    std::cout << "Dog assignment operator called" << std::endl;
    if (this != &other)
    {
        delete (this->brain);
        this->brain = new Brain(*other.brain);
        this->type = other.type;
    }
    return (*this);
}

Dog::~Dog(void){
    delete (this->brain);
    std::cout << "Dog destructor called" << std::endl;
}


void Dog::makeSound() const{
    std::cout << YELLOW << "Woof! Woof!" <<  RESET<< std::endl;
}

Brain* Dog::getBrain(void) const{
    return(this->brain);
}
