#include "../include/AAnimal.hpp"
#include "../include/Cat.hpp"


Cat::Cat(void) : AAnimal(){
    std::cout << "Cat default constructor called" << std::endl;
    type = "Cat";
    this->brain = new Brain(); //chama o construtor padrão de brain
}

Cat::Cat(const Cat &other): AAnimal(other){
    std::cout << "Cat copy constructor called" << std::endl;
    this->brain = new Brain(*other.brain);
}

Cat &Cat::operator=(const Cat &other){
    std::cout << "Cat assignment operator called" << std::endl;
    if (this != &other)
    {
        delete (this->brain);
        this->brain = new Brain(*other.brain);
        this->type = other.type;
    }
    return (*this);
}

Cat::~Cat(void){
    delete (this->brain);
    std::cout << "Cat destructor called" << std::endl;
}

void Cat::makeSound() const{
    std::cout << CYAN <<"Meeeeoooow!" << RESET <<std::endl;
}

Brain* Cat::getBrain(void) const{
    return(this->brain);
}
