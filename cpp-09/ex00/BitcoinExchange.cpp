#include "BitcoinExchange.hpp"

// Default constructor
BitcoinExchange::BitcoinExchange(void)
{
    std::cout << "Default constructor called" << std::endl;
    return ;
}

// Copy constructor
BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
    std::cout << "Copy constructor called" << std::endl;
    (void) other;
    return ;
}

// Assignment operator overload
BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
    std::cout << "Assignment operator called" << std::endl;
    (void) other;
    return (*this);
}

// Destructor
BitcoinExchange::~BitcoinExchange(void)
{
    std::cout << "Destructor called" << std::endl;
    return ;
}

bool BitcoinExchange::isValidDate(std::string date)
{
    
}
