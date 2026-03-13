#include "../include/RPN.hpp"

RPN::RPN(){}

RPN::RPN(std::string input): input(input){}


RPN::RPN(const RPN &other): input(other.input), values(other.values) {}

RPN &RPN::operator=(const RPN &other){
    if (this != &other){
    this->input = other.input;
    this->values = other.values;
    }
    return(*this);
}

RPN::~RPN(){}

static int stringToInt(const std::string &str)
{
    std::stringstream ss(str);
    int value;
    ss >> value;
    return value;
}

bool RPN::isOperator(std::string token) {
    return (token == "+" || token == "-" || token == "*" || token == "/");
}

bool RPN::isValidInput(void){
    for (size_t i = 0; i < input.size(); i++) {
        if (!isdigit(input[i]) &&
            input[i] != '+' &&
            input[i] != '-' &&
            input[i] != '*' &&
            input[i] != '/' &&
            input[i] != ' ')
            return false;
    }
    return true;
}

bool RPN::isNumber(std::string &str)
{
    int number;
    std::stringstream ss(str);
    ss >> number;
    if (ss.fail() || number < 0 || number > 9)
        return (false);
    return (true);

}

int RPN::calculate(std::string token, int a, int b){
    int result = 0;

    if (token == "+")
        result = a + b;
    else if (token == "-")
        result = a - b;
    else if (token == "*")
        result = a * b;
    else if (token == "/")
    {
        if (b == 0)
        {   
            std::cout <<  "Error:  Division by zero." << std::endl;
            return(INT_MIN);
        }
        result = a / b;
    }
    return (result);
}

void RPN::load_input(void){
    if(!isValidInput()){
        std::cerr << "Error: Invalid expression." << std::endl;   
        return ; 
    }

    std::istringstream iss(input);
    std::string token;
    // int number;

    while (iss >> token){
        if (isNumber(token))
            values.push(stringToInt(token));
        else if (isOperator(token))
        {
            if(values.size() < 2)
                continue;
            int b = values.top();
            values.pop();

            int a = values.top();
            values.pop();

            int result = calculate(token, a, b);
            if (result == INT_MIN)
                return ;
            values.push(result);
        }
    }
    if (values.size() == 1)
        std::cout << values.top() << std::endl;
    else
        std::cerr << "Error: Invalid expression." << std::endl;   

}


