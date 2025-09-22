#include "Animal.hpp"

// Default constructor
Animal::Animal()
{
    std::cout << "Animal's Default constructor called" << std::endl;
    _type = "unknown";
}

// Copy constructor
Animal::Animal(const Animal &other)
{
    std::cout << "Animal's Copy constructor called" << std::endl;
    _type = other._type;
    return ;
}

// Assignment operator overload
Animal &Animal::operator=(const Animal &other)
{
    std::cout << "Animal's Assignment operator called" << std::endl;
    if (this != &other)
        _type = other._type;
    return (*this);
}

// Destructor
Animal::~Animal(void)
{
    std::cout << "Animal's Destructor called" << std::endl;
}

void Animal::makeSound(void) const
{
    std::cout << "Animal sound" << std::endl;
}

const std::string &Animal::getType(void) const
{
    return _type;
}
