#include "Dog.hpp"

// Default constructor
Dog::Dog(void) : Animal()
{
    std::cout << "Dog's Default constructor called" << std::endl;
    _type = "Dog";
    brain =  new(std::nothrow) Brain();
    if (!brain)
        std::cerr << "Memory allocation failed for Dog's brain in default constructor!!!!" << std::endl;
}

// Copy constructor
Dog::Dog(const Dog &other) : Animal(other)
{
    std::cout << "Dog's Copy constructor called" << std::endl;
    _type = other._type;
    brain = new(std::nothrow) Brain(*other.brain);
    if (!brain)
        std::cerr << "Memory allocation failed for Dog's brain in copy constructor!!!!" << std::endl;
}

// Assignment operator overload
Dog &Dog::operator=(const Dog &other)
{
    std::cout << "Dog's Assignment operator called" << std::endl;
    if (this != &other)
    {
        _type = other._type;
        delete brain;
        brain = new(std::nothrow) Brain(*other.brain);
        if (!brain)
            std::cerr << "Memory allocation failed for Dog's brain in Assignment operator!!!!" << std::endl;
    }
    return (*this);
}

// Destructor
Dog::~Dog(void)
{
    std::cout << "Dog's Destructor called" << std::endl;
    delete brain;
    brain = NULL;
}

void Dog::makeSound(void) const
{
    std::cout << "Woof Woof" << std::endl;
}
