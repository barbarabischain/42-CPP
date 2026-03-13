#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>
#include <string>
#include <stack>
#include <fstream>
#include <sstream>
#include <climits>

class RPN{
    private:
        std::string     input;
        std::stack<int> values;
        RPN();
        bool isValidInput(void);
        bool isOperator(std::string token);
        bool isNumber(std::string &str);
        int calculate(std::string token, int a, int b);

        // static int stringToInt(const std::string &str);


    public:
        RPN(std::string input);
        RPN(const RPN &other);
        RPN &operator=(const RPN &other);
        ~RPN();

        void load_input(void);



};

#endif
