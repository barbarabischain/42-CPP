#include "../include/RPN.hpp"

int main(int argc, char **argv){
    if (argc != 2){
        std::cerr << "Error: Usage: ./RPN \"<expression>\"" << std::endl;
        return (1);
    }
    
    RPN rpn(argv[1]);
    rpn.load_input();
    return (0);
}