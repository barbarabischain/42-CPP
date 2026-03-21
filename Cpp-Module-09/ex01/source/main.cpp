#include "../include/RPN.hpp"

int main(int argc, char **argv){
    if (argc != 2){
        std::cerr << "Error: Usage: ./RPN \"<expression>\"" << std::endl;
        return (1);
    }

    try{
    RPN rpn(argv[1]);
    rpn.load_input();
    } catch (std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return (0);
}