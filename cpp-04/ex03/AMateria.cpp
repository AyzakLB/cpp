#include "AMateria.hpp"

// Default constructor
AMateria::AMateria(void) : _type("unknown"), _isEquiped(false){}

// Parameterized constructor
AMateria::AMateria(std::string const &type) : _type(type), _isEquiped(false){}

// Copy constructor
AMateria::AMateria(const AMateria &other) : _type(other._type), _isEquiped(other._isEquiped){}

// Assignment operator overload
AMateria &AMateria::operator=(const AMateria &other)
{
    if (this != &other)
    {
        _type = other._type;
        _isEquiped = other._isEquiped;
    }
    return (*this);
}

// Destructor
AMateria::~AMateria(void){}

std::string const &AMateria::getType() const { return (_type); }

bool AMateria::getIsEquiped() const { return _isEquiped;}

void AMateria::setIsEquiped(bool isEquiped) { _isEquiped = isEquiped;}

void AMateria::use(ICharacter &target)
{
    std::cout << "AMateria used on " << target.getName() << std::endl;
}
