#ifndef AANIMAL_HPP
# define AANIMAL_HPP

# include <iostream>
# include <string>

# define GREEN   "\033[92m"
# define RESET   "\033[0m"
# define MAGENTA "\033[95m"
# define CYAN    "\033[36m"
# define YELLOW  "\033[33m"
# define BLUE    "\033[34m"

class AAnimal{
    protected:
        std::string type;

    public:
        AAnimal(void);
        AAnimal(const AAnimal &other);
        AAnimal &operator=(const AAnimal &other);
        virtual ~AAnimal(void);

        std::string getType(void) const;
        virtual void makeSound(void) const = 0;

};

#endif
