#include "ScalarConverter.hpp"

void printFloat(float f, bool isSpecial)
{
    std::cout << "float: ";
    if (isSpecial == false)
    {
        if (f == floor(f))
            std::cout << f << ".0";
        else
            std::cout << std::fixed <<  std::setprecision(std::numeric_limits<float>::digits10) << f;
    } else
        std::cout << f;
    std::cout << "f" << std::endl;
}

void printDouble(double d, bool isSpecial)
{
    std::cout << "double: ";
    if (isSpecial == false)
    {
        if (d == floor(d))
            std::cout << d <<  ".0";
        else
            std::cout << std::fixed << std::setprecision(std::numeric_limits<double>::digits10) << d;
    } else 
        std::cout << d;
    std::cout << std::endl;
        
}

void handleCharIntDouble(double d)
{
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
void handleCharIntFloat(float f)
{
    if (f < CHAR_MIN || f > CHAR_MAX)
        std::cout << "char: Out of char range" << std::endl;
    else if (f < 32 || f > 126)
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: '" << static_cast<char>(f) << "'" << std::endl;
    
    if (f < INT_MIN || f > INT_MAX)
        std::cout << "int: out of range" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(f) << std::endl;
}

void convertChar(char c)
{
    if (c < 32 || c > 126)
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: '" << c << "'" << std::endl;
    std::cout << "int: " << static_cast<int>(c) << std::endl;
    printFloat(static_cast<float>(c), false);
    printDouble(static_cast<double>(c), false);
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
    printFloat(static_cast<float>(i), false);
    printDouble(static_cast<double>(i), false);
}

void convertFloat(std::string literal)
{
    float f = (atof(literal.c_str()));
    bool isSpecial = false;
    if (literal == "nanf" || literal == "+inff" || literal == "-inff")
    {
        isSpecial = true;
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
    }
    else
        handleCharIntFloat(f);
    printFloat(f, isSpecial);
    printDouble(static_cast<double>(f), isSpecial);
}

void convertDouble(std::string literal)
{
    double d = atof(literal.c_str());
    bool isSpecial = false;
    if (literal == "nan" || literal == "+inf" || literal == "-inf")
    {
        isSpecial = true;
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
    }
    else
        handleCharIntDouble(d);
    if (d < -FLT_MAX - 1 || d > FLT_MAX)
        std::cout << "float: out of range" << std::endl;
    else
        printFloat(static_cast<float>(d), isSpecial);
    printDouble(d, isSpecial);
}

