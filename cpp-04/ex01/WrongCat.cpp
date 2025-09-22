#include "WrongCat.hpp"

// Default constructor
WrongCat::WrongCat(void) : WrongAnimal()
{
    std::cout << "WrongCat's Default constructor called" << std::endl;
    _type = "WrongCat";
}

// Copy constructor
WrongCat::WrongCat(const WrongCat &other) : WrongAnimal(other)
{
    std::cout << "WrongCat's Copy constructor called" << std::endl;
    _type = other._type;
}

// Assignment operator overload
WrongCat &WrongCat::operator=(const WrongCat &other)
{
    std::cout << "WrongCat's Assignment operator called" << std::endl;
    if (this != &other)
        _type = other._type;
    return (*this);
}

// Destructor
WrongCat::~WrongCat(void)
{
    std::cout << "WrongCat's Destructor called" << std::endl;
}

void WrongCat::makeSound(void) const
{
    std::cout << "WrongCat Meow" << std::endl;
}
