#include "ScalarConverter.hpp"

void printFloat(float f)
{
    std::cout << "float: ";
    if (std::isnan(f) || std::isinf(f) || f - floor(f) != 0)
        std::cout << f;
    else
        std::cout << f << ".0";
    std::cout << "f" << std::endl;
}

void printDouble(double d)
{
    std::cout << "double: ";
    if (std::isnan(d) || std::isinf(d) || (d - floor(d) != 0))
        std::cout << d << std::endl;
    else
        std::cout << d << ".0" << std::endl;
}

void handleCharInt(long long d)
{
    if (std::isnan(d) || std::isinf(d))
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
    }
    else {
    if (d < CHAR_MIN || d > CHAR_MAX)
        std::cout << "char: Out of char range" << std::endl;
    else if (d < 32 || d > 126)
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: '" << static_cast<char>(d) << "'" << std::endl;
    
    if (d < INT_MIN || d > INT_MAX)
        std::cout << "int: out of range" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(d) << std::endl;
    }
}

void convertChar(char c)
{
    if (c < 32 || c > 126)
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: '" << c << "'" << std::endl;
    std::cout << "int: " << static_cast<int>(c) << std::endl;
    printFloat(static_cast<float>(c));
    printDouble(static_cast<double>(c));
}

void convertInt(int i)
{
    if (i < CHAR_MIN || i > CHAR_MAX)
        std::cout << "char: Out of char range" << std::endl;
    else if (i < 32 || i > 126)
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: '" << static_cast<char>(i) << "'" << std::endl;
    std::cout << "int: " << i << std::endl;
    printFloat(static_cast<float>(i));
    printDouble(static_cast<double>(i));
}

void convertFloat(std::string literal)
{
    if (literal == "nanf" || literal == "+inff" || literal == "-inff")
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
    }
    else
        handleCharInt(atoll(literal.c_str()));
    float f =  static_cast<float>(atof(literal.c_str()));
    printFloat(f);
    printDouble(static_cast<double>(f));
}

void convertDouble(std::string literal)
{
    if (literal == "nan" || literal == "+inf" || literal == "-inf")
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
    }
    else
        handleCharInt(atoll(literal.c_str()));
    double d = atof(literal.c_str());
    if (d < -FLT_MAX - 1 || d > FLT_MAX)
        std::cout << "float: out of range" << std::endl;
    else
        printFloat(static_cast<float>(d));
    printDouble(d);
}

