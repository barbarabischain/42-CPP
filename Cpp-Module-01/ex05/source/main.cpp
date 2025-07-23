#include "../include/Harl.hpp"

void displayMenu() {

    std::cout << LPURPLE <<"------ HELLO, I'M HARL 🤖 ------\n" << RESET << std::endl;
}

int main(void)
{
    displayMenu();

    Harl obj;

    obj.complain("INFO");
    obj.complain("DEBUG");
    obj.complain("WARNING");
    obj.complain("ERROR");
}
