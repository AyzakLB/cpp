#include "Dog.hpp"

// Default constructor
Dog::Dog(void) : Animal()
{
    std::cout << "Dog's Default constructor called" << std::endl;
    _type = "Dog";
}

// Copy constructor
Dog::Dog(const Dog &other) : Animal(other)
{
    std::cout << "Dog's Copy constructor called" << std::endl;
    _type = other._type;
}

// Assignment operator overload
Dog &Dog::operator=(const Dog &other)
{
    std::cout << "Dog's Assignment operator called" << std::endl;
    if (this != &other)
        _type = other._type;
    return (*this);
}

// Destructor
Dog::~Dog(void)
{
    std::cout << "Dog's Destructor called" << std::endl;
}

void Dog::makeSound(void) const
{
    std::cout << "Woof Woof" << std::endl;
}
