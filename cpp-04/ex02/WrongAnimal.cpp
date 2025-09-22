#include "WrongAnimal.hpp"

// Default constructor
WrongAnimal::WrongAnimal(void)
{
    std::cout << "WrongAnimal's Default constructor called" << std::endl;
    _type = "wrongAnimal";
}

// Copy constructor
WrongAnimal::WrongAnimal(const WrongAnimal &other)
{
    std::cout << "WrongAnimal's Copy constructor called" << std::endl;
    _type = other._type;
}

// Assignment operator overload
WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other)
{
    std::cout << "WrongAnimal's Assignment operator called" << std::endl;
    if (this != &other)
        _type = other._type;
    return (*this);
}

// Destructor
WrongAnimal::~WrongAnimal(void)
{
    std::cout << "WrongAnimal's Destructor called" << std::endl;
}

void WrongAnimal::makeSound(void) const
{
    std::cout << "WrongAnimal sound" << std::endl;
}

const std::string &WrongAnimal::getType(void) const
{
    return _type;
}