#ifndef HARL_HPP
#define HARL_HPP

# include <iostream>

# define RED "\033[0;31m"
# define BCYAN "\033[0;36m"
# define GREEN "\033[0;32m"
# define BLUE "\033[0;34m"
# define YELLOW "\033[0;33m"
# define LPURPLE "\033[1;35m"
# define RESET "\033[0m"

class Harl{
    private:
    void info(void);
    void warning(void);
    void error(void);
    void debug(void);

    public:
        Harl();
        ~Harl();
        void complain(std::string level);
};

#endif
