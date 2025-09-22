#include "Cat.hpp"

// Default constructor
Cat::Cat() : Animal()
{
    std::cout << "Cat's Default constructor called" << std::endl;
    _type = "Cat";
    brain =  new(std::nothrow) Brain();
    if (!brain)
        std::cerr << "Memory allocation failed for Cat's brain in default constructor!!!!" << std::endl;
}

// Copy constructor
Cat::Cat(const Cat &other) : Animal(other)
{
    std::cout << "Cat's Copy constructor called" << std::endl;
    _type = other._type;
    brain = new(std::nothrow) Brain(*other.brain);
    if (!brain)
        std::cerr << "Memory allocation failed for Cat's brain in copy constructor!!!!" << std::endl;
}

// Assignment operator overload
Cat &Cat::operator=(const Cat &other)
{
    std::cout << "Cat's Assignment operator called" << std::endl;
    if (this != &other)
    {
        _type = other._type;
        delete brain;
        brain = new(std::nothrow) Brain(*other.brain);
        if (!brain)
            std::cerr << "Memory allocation failed for Cat's brain in Assignment operator!!!!" << std::endl;
    }
    return (*this);
}

// Destructor
Cat::~Cat(void)
{
    std::cout << "Cat's Destructor called" << std::endl;
    delete brain;
    brain = NULL;
}

void Cat::makeSound(void) const
{
    std::cout << "Meow" << std::endl;
}
