#include "ScalarConverter.hpp"

////////////////////////// prototypes //////////////////////////
std::string parseLiteral(const std::string &literal);
void convertDouble(std::string literal);
void convertChar(char c);
void convertInt(int i);
void convertFloat(std::string literal);
//////////////////////////

ScalarConverter::ScalarConverter(void){}

ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
    (void) other;
    return ;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
    (void) other;
    return (*this);
}

ScalarConverter::~ScalarConverter(void){}

void printError()
{
    std::cout << "Input Error: The literal must belong to one of the following a scalar types:" << std::endl;
    std::cout << "char" << std::endl;
    std::cout << "int" << std::endl;
    std::cout << "float" << std::endl;
    std::cout << "double" << std::endl;
}

void ScalarConverter::convert(const std::string &literal) {
    std::string type = parseLiteral(literal);
    if (type == "char")
        convertChar(literal[0]);
    else if (type == "int")
        convertInt(atoi(literal.c_str()));
    else if (type == "float")
        convertFloat(literal);
    else if (type == "double")
        convertDouble(literal);
    else
        printError();
}
