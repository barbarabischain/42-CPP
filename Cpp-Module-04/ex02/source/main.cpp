#include "../include/AAnimal.hpp"
#include "../include/Cat.hpp"
#include "../include/Dog.hpp"
#include "../include/Brain.hpp"
#include "../include/WrongAnimal.hpp"
#include "../include/WrongCat.hpp"


int main(void){

    AAnimal *animals[2];
    animals[0] = new Dog;
    animals[1] = new Cat;

    std::cout << std::endl;
    animals[0]->makeSound();
    animals[1]->makeSound();

    std::cout << std::endl;

    delete (animals[0]);
    delete (animals[1]);

    return (0);
}
