#ifndef RPN_HPP
#define RPN_HPP

#include <string>
#include <stack>
#include <stdexcept>
#include <iostream>
#include <sstream>
#include <cctype>

class RPN {
    private:
        std::stack<int> st;
    public:
        RPN();
        RPN(const RPN& other);
        RPN& operator=(const RPN& other);
        ~RPN();

        int evaluate(const std::string& expression);
    private:
        bool isOperator(char c) const;
        int performOperation(int a, int b, char op) const;
};

#endif