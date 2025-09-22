#include "Brain.hpp"
#include <iostream>
// Default constructor
Brain::Brain(void)
{
    std::cout << "Brain's Default constructor called" << std::endl;
    for (int i = 0; i < 100; i++)
        _ideas[i] = "idea";
}

// Copy constructor
Brain::Brain(const Brain &other)
{
    std::cout << "Brain's Copy constructor called" << std::endl;
    for (int i = 0; i < 100; i++)
        _ideas[i] = other._ideas[i];
}

// Assignment operator overload
Brain &Brain::operator=(const Brain &other)
{
    std::cout << "Brain's Assignment operator called" << std::endl;

    if (this != &other) 
    {
        for (int i = 0; i < 100; i++)
        _ideas[i] = other._ideas[i];
    }
    return (*this);
}

// Destructor
Brain::~Brain(void)
{
    std::cout << "Brain's Destructor called" << std::endl;
}

