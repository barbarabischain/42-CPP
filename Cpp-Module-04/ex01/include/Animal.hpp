#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include <string>

# define GREEN   "\033[92m"
# define RESET   "\033[0m"
# define MAGENTA "\033[95m"
# define CYAN    "\033[36m"
# define YELLOW  "\033[33m"
# define BLUE    "\033[34m"

class Animal{
    protected:
        std::string type;

    public:
        Animal(void);
        Animal(const Animal &other);
        Animal &operator=(const Animal &other);
        virtual ~Animal(void);

        std::string getType(void) const;
        virtual void makeSound(void) const;

};

#endif
