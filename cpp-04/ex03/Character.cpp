#include "Character.hpp"


AMateria **Character::_unequiped = NULL;
size_t Character::_unequipedSize = 0;
// Default constructor
Character::Character(void) : _name("unnamed")
{
    for (int i = 0; i < 4; i++)
        _inventory[i] = NULL;
}

// Parameterized constructor
Character::Character(const std::string &name) : _name(name)
{
    for (int i = 0; i < 4; i++)
        _inventory[i] = NULL;
}

// Copy constructor
Character::Character(const Character &other)
{
    _name = other._name;
    for (int i = 0; i < 4; i++)
    {
        if (other._inventory[i])
            _inventory[i] = other._inventory[i]->clone();
        else
            _inventory[i] = NULL;
    }
}

// Assignment operator overload
Character &Character::operator=(const Character &other)
{
    if (this != &other)
    {
        _name = other._name;
        for (int i = 0; i < 4; i++)
        {
            if (_inventory[i])
                delete _inventory[i];
            if (other._inventory[i])
                _inventory[i] = other._inventory[i]->clone();
            else
                _inventory[i] = NULL;
        }
    }
    return (*this);
}


// Destructor
Character::~Character(void)
{
    for (int i = 0; i < 4; i++)
    {
        if (_inventory[i])
            delete _inventory[i];
    }
}

std::string const &Character::getName() const { return _name; }

void Character::equip(AMateria* m)
{
    int i = 0;
    while (i < 4 && _inventory[i])
        i++;
    if (i == 4)
    { 
        std::cerr << "inventory full!" << std::endl;
        return ;
    } else if (!m)
    {
        std::cerr << "Materia doesn't exist" << std::endl;
        return ;
    } else if (m->getIsEquiped() == true)
    {
        std::cerr << "Materia already equiped by another character" << std::endl;
        return ;
    }
    removeUnequiped(m);
    m->setIsEquiped(true);
    _inventory[i] = m;
}

void Character::unequip(int idx)
{
    if (idx > 3 || _inventory[idx] == NULL)
    {
        std::cerr << "Materia doesn't exist" << std::endl;
        return ;
    }
    _inventory[idx]->setIsEquiped(false);
    addUnequiped(_inventory[idx]);
    _inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter& target)
{
    if (idx > 3 || _inventory[idx] == NULL)
    {
        std::cerr << "Materia doesn't exist" << std::endl;
        return ;
    }
    _inventory[idx]->use(target);
}

void Character::addUnequiped(AMateria *materia)
{
    size_t i = 0;
    while (i < _unequipedSize)
    {
        if (_unequiped[i] == NULL)
        {
            _unequiped[i] = materia;
            return ;
        }
        i++;
    }
    if (expandUnequiped() == 1)
    {
        std::cerr << "Memory allocation failed" << std::endl;
        return ;
    }
    _unequiped[i] = materia;
}

void Character::removeUnequiped(AMateria *materia)
{
    for (size_t i = 0; i < _unequipedSize; i++)
    {
        if (_unequiped[i] == materia)
        {
            _unequiped[i] = NULL;
            return ;
        }
    }
}

int Character::expandUnequiped()
{
    if (_unequipedSize == 0)
    {
        _unequiped = new(std::nothrow) AMateria*[100];
        if (!_unequiped)
        {
            std::cerr << "Memory allocation failed" << std::endl;
            return 1;
        }
        for (size_t i = 0; i < 100; i++)
            _unequiped[i] = NULL;
        _unequipedSize = 100;
    }
    else
    {
        AMateria **temp = new AMateria*[_unequipedSize + 100];
        if (!temp)
        {
            std::cerr << "Memory allocation failed" << std::endl;
            return 1;
        }
        for (size_t i = 0; i < _unequipedSize; i++)
            temp[i] = _unequiped[i];
        delete[] _unequiped;
        _unequiped = temp;
        _unequipedSize += 100;
    }
    return 0;
}
void Character::clearUnequiped()
{
    for (size_t i = 0; i < _unequipedSize; i++)
    {
        if (_unequiped[i])
        {
            delete _unequiped[i];
            _unequiped[i] = NULL;
        }
    }
    delete[] _unequiped;
}

