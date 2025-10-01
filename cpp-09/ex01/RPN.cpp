#include "RPN.hpp"

// Default constructor
RPN::RPN(void)
{
    std::cout << "Default constructor called" << std::endl;
    return ;
}

// Copy constructor
RPN::RPN(const RPN &other)
{
    std::cout << "Copy constructor called" << std::endl;
    (void) other;
    return ;
}

// Assignment operator overload
RPN &RPN::operator=(const RPN &other)
{
    std::cout << "Assignment operator called" << std::endl;
    (void) other;
    return (*this);
}

// Destructor
RPN::~RPN(void)
{
    std::cout << "Destructor called" << std::endl;
    return ;
}

void RPN::calculate(std::string expression)
{
    std::stack<int> calculator;
    bool foundChar = false;
    
    for (size_t i = 0; i < expression.length(); ++i)
    {
        if (expression[i] == ' ')
        {
            foundChar = false;
            continue; 
        }
        if (foundChar)
            throw std::runtime_error("Error");
        foundChar = true;
        if (std::isdigit(expression[i]))
            calculator.push(expression[i] - '0');   
        else
        {
            if (calculator.size() < 2)
                throw std::runtime_error("Error");
            int operand2 = calculator.top();
            calculator.pop();
            int operand1 = calculator.top();
            calculator.pop();
            switch (expression[i])
            {
                case '+': calculator.push(operand1 + operand2); break;
                case '-': calculator.push(operand1 - operand2); break;
                case '*': calculator.push(operand1 * operand2); break;
                case '/': { if (operand2 != 0) 
                                calculator.push(operand1 / operand2);
                            else 
                                throw std::runtime_error("Error: error 0 devision");
                            } break;
                default: std::cout << expression[i]; throw std::runtime_error("Error not a valid value");
            }
        }
    }
    if (calculator.size() != 1)
        throw std::runtime_error("Error: last");
    std::cout << calculator.top() << std::endl;
}

