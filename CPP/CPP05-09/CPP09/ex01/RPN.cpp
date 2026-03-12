#include "RPN.hpp"

// Default Constructor
RPN::RPN() {}

// Destructor
RPN::~RPN() {}

// Copy Constructor
RPN::RPN(const RPN& other) {
    st = other.st;
}

// Copy Assignment Operator
RPN& RPN::operator=(const RPN& other) {
    if (this != &other) {
        st = other.st;
    }
    return *this;
}

// Member Function to evaluate RPN expression
int RPN::evaluate(const std::string& expression) {
    std::stringstream ss(expression);
    std::string token;

    while (std::getline(ss, token, ' ')) {
        if (token.length() == 1 && isOperator(token[0])) {
            // Operator: Pop two numbers and perform the operation
            if (st.size() < 2) {
                throw std::runtime_error("Error");
            }
            int b = st.top(); st.pop();
            int a = st.top(); st.pop();
            st.push(performOperation(a, b, token[0]));
        } else if (std::isdigit(token[0])) {
            // Operand: Push the number onto the stack
            std::stringstream numStream(token);
            int num;
            numStream >> num;
            if (numStream.fail() || !numStream.eof()) {
                throw std::runtime_error("Error");
            }
            st.push(num);
        } else {
            throw std::runtime_error("Error");
        }
    }

    if (st.size() != 1) {
        throw std::runtime_error("Error");
    }

    return st.top();
}

// Helper function to check if a string is a valid operator
bool RPN::isOperator(char c) const {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

// Helper function to perform an operation
int RPN::performOperation(int a, int b, char op) const {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/':
        if (b == 0) {
            throw std::runtime_error("Error"); // standard error?
        }
        return a / b;
        default:
            throw std::runtime_error("Error");
    }
}