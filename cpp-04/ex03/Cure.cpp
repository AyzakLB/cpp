#include "Cure.hpp"

// Default constructor
Cure::Cure(void)
{
    _type = "cure";
    return ;
}

// Copy constructor
Cure::Cure(const Cure &other) : AMateria(other)
{
    _type = "cure";
    (void) other;
}

// Assignment operator overload
Cure &Cure::operator=(const Cure &other)
{
    (void) other;
    return (*this);
}

// Destructor
Cure::~Cure(void){}


AMateria *Cure::clone() const
{
    AMateria *cure = new(std::nothrow) Cure();
    if (!cure)
        std::cerr << "Memory allocation failed for cure clone!!!!" << std::endl;
    return cure;
}

void Cure::use(ICharacter &target)
{
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
