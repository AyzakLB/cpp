#include "ScalarConverter.hpp"

static std::string floatLiterals[3] = {
    "-inff",
    "+inff",
    "nanf",
    };
    static std::string doubleLiterals[3] = {
        "-inf",
        "+inf",
        "nan",
    };

size_t strIsInArray(const std::string &literal, std::string literalsArray[3])
{
    size_t i = 0;
    for (; i < 3; i++)
    {
        if (literal == literalsArray[i])
            return i;
    }
    return i;
}

std::string getNumber(const std::string &literal)
{
        size_t len = literal.length();
        size_t i = 0;
        bool hasDecimal = false;
        bool hasF = false;
        if (literal[0] == '-' || literal[0] == '+')
            i++;
        for (; i < len; i++)
        {
            if (!isdigit(literal[i]) && literal[i] != '.' && literal[i] != 'f' && literal[i] != 'F')
                return "error";
            if (literal[i] == '.')
            {
                if (hasDecimal)
                    return "error";
                hasDecimal = true;
            }
            if (literal[i] == 'f' || literal[i] == 'F')
            {
                if (i + 1 < len)
                    return "error";
                hasF = true;
            }
        }
        if (hasDecimal && hasF)
            return "float";
        else if (hasDecimal)
            return "double";
        else if (hasF)
            return "error";
        else
        {
            double d = atof(literal.c_str());
            if (d >= INT_MIN && d <= INT_MAX)
                return "int";
            else if (d >= -FLT_MAX - 1 && d <= FLT_MAX)
                return "float";
            return "double";
        }
}

std::string parseLiteral(const std::string &literal)
{
    size_t len = literal.length();
    if (len == 1 && !isdigit(literal[0]))
        return "char";
    else if (strIsInArray(literal, floatLiterals) != 3)
        return "float";
    else if (strIsInArray(literal, doubleLiterals) != 3)
        return "double";
    else if (((literal[0] == '-' || literal[0] == '+') && len > 1) || isdigit(literal[0]))
        return getNumber(literal);
    else
        return "error";
}