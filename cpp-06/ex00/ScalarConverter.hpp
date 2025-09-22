#pragma once
# include <iostream>
#include <limits>
#include <cfloat>
#include <cmath>
#include <limits.h>


class ScalarConverter
{
        ScalarConverter(void);
        ScalarConverter(const ScalarConverter& other);
        ScalarConverter &operator=(const ScalarConverter &other);
        ~ScalarConverter();
    public:
        static void convert (const std::string &literal);
};


