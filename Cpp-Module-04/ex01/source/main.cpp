#include "../include/Animal.hpp"
#include "../include/Cat.hpp"
#include "../include/Dog.hpp"
#include "../include/Brain.hpp"
#include "../include/WrongAnimal.hpp"
#include "../include/WrongCat.hpp"


void    test_polymorphism(void)
{
    std::cout << GREEN << "*** TESTING POLYMORPHISM ***" <<  RESET << std::endl;
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    std::cout << std::endl;


    std::cout << "Types: " << j->getType() << " and " << i->getType() << std::endl;
    i->makeSound();
    j->makeSound();
    meta->makeSound();

    std::cout << std::endl;
    delete meta;
    delete j;
    delete i;

    std::cout << std::endl;
}

void test_deepCopy(void)
{
    std::cout << GREEN <<"*** TESTING DEEP COPY ***" <<  RESET <<std::endl;
    Cat original;
    std::cout << std::endl;

    Cat copy(original);
    std::cout << std::endl;

    std::cout << CYAN <<"Original brain address: " << original.getBrain() << RESET << std::endl;
    std::cout << CYAN <<"Copy brain address: " << copy.getBrain() << RESET << std::endl;
    std::cout << std::endl;


    std::cout << GREEN <<"*** TESTING ASSIGNMENT ***" <<  RESET <<std::endl;
    Cat assigned;
    std::cout << std::endl;

    assigned = original;
    std::cout << std::endl;

    std::cout << BLUE <<"Original brain address: " << original.getBrain() << RESET << std::endl;
    std::cout << BLUE <<"Assigned brain address: " << assigned.getBrain() << RESET << std::endl;

    std::cout << std::endl;
}

void    test_brainIdeas(void)
{
    std::cout << GREEN <<"*** TESTING BRAIN IDEAS ***" <<  RESET <<std::endl;

    Dog kiko;
    kiko.getBrain()->setIdeas(1, "sleep...");

    std::cout << std::endl;
    std::cout << MAGENTA << kiko.getBrain()->getIdeas(0)<< std::endl;
    std::cout << kiko.getBrain()->getIdeas(1)<<  RESET <<std::endl;
    std::cout << std::endl;
}

void    test_animalsArray(void)
{
    std::cout << GREEN <<"*** TESTING ARRAY OF ANIMALS ***" <<  RESET <<std::endl;
    Animal *animals[4];
    for (int i = 0; i < 4; i++)
    {
        if (i < 2)
            animals[i] = new Dog;
        else
            animals[i] = new Cat;
    }
    std::cout << std::endl;

    for (int i = 0; i < 4; i++)
        animals[i]->makeSound();
    std::cout << std::endl;


    for (int i = 0; i < 4; i++)
        delete (animals[i]);
}


int main(void){

    test_polymorphism();
    std::cout << std::endl;

    test_deepCopy();
    std::cout << std::endl;

    test_brainIdeas();
    std::cout << std::endl;

    test_animalsArray();

}
