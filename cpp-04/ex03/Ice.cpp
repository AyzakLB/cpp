#include "Ice.hpp"
// Default constructor
Ice::Ice(void)
{
    _type = "ice";
}

// Copy constructor
Ice::Ice(const Ice &other) : AMateria(other)
{
    (void) other;
    _type = "ice";
}

// Assignment operator overload
Ice &Ice::operator=(const Ice &other)
{
    (void) other;
    return (*this);
}

// Destructor
Ice::~Ice(void){}


AMateria *Ice::clone() const
{
    AMateria *ice = new(std::nothrow) Ice();
    if (!ice)
        std::cerr << "Memory allocation failed for ice clone!!!!" << std::endl;
    return ice;
}

void Ice::use(ICharacter &target)
{
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
