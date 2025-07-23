#ifndef CAT_HPP
# define CAT_HPP

# include <iostream>
# include "AAnimal.hpp"
# include "Brain.hpp"

class Cat : public AAnimal{
    private:
        Brain * brain;
    public:
        Cat(void);
        Cat(const Cat &other);
        Cat &operator=(const Cat &other);
        ~Cat(void);

        void makeSound(void) const;
        Brain* getBrain(void) const;
};

#endif
