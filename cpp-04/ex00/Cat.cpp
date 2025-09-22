#include "Cat.hpp"

// Default constructor
Cat::Cat()
{
    std::cout << "Cat's Default constructor called" << std::endl;
    _type = "Cat";
}

// Copy constructor 
Cat::Cat(const Cat &other) : Animal(other)
{
    std::cout << "Cat's Copy constructor called" << std::endl;
        _type = other._type;
}

// Assignment operator overload
Cat &Cat::operator=(const Cat &other)
{
    std::cout << "Cat's Assignment operator called" << std::endl;
    if (this != &other)
        _type = other._type;
    return (*this);
}

// Destructor
Cat::~Cat(void)
{
    std::cout << "Cat's Destructor called" << std::endl;
}

void Cat::makeSound(void) const
{
    std::cout << "Meow" << std::endl;
}
