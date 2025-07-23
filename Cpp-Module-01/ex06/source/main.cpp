#include "../include/Harl.hpp"

void displayMenu() {
    std::cout << "------ HELLO, I'M HARL 🤖 ------" << std::endl;
}

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cerr << "Usage: [DEBUG] [INFO] [WARNING] [ERROR]";
        return (1);
    }
    displayMenu();


    Harl obj;
    obj.complain(argv[1]);

}
