#include "MateriaSource.hpp"

// Default constructor
MateriaSource::MateriaSource(void)
{
    for (int i = 0; i < 4; i++)
        _materias[i] = NULL;
    _count = 0;
}

// Copy constructor
MateriaSource::MateriaSource(const MateriaSource &other)
{
    for (int i = 0; i < 4; i++)
    {
        if (other._materias[i])
            _materias[i] = other._materias[i]->clone();
        else
            _materias[i] = NULL;
        _count = other._count;
    }
}

// Assignment operator overload
MateriaSource &MateriaSource::operator=(const MateriaSource &other)
{
    if (this != &other)
    {
        for (int i = 0; i < 4; i++)
        {
            if (_materias[i])
                delete _materias[i];
            if (other._materias[i])
                _materias[i] = other._materias[i]->clone();
            else
                _materias[i] = NULL;
        }
        _count = other._count;
    }
    return (*this);
}

// Destructor
MateriaSource::~MateriaSource(void)
{
    for (int i = 0; i < 4; i++)
    {
        if (_materias[i])
            delete _materias[i];
    }
}

void MateriaSource::learnMateria(AMateria* materia)
{
    if (_count >= 4)
    {
        std::cerr << "MateriaSource's Materias is full" << std::endl;
        return ;
    } else if (!materia)
    {
        std::cerr << "Materia is NULL" << std::endl;
        return ;
    }
    _materias[_count] = materia;
    _count++;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
    for (int i = 0; i < _count; i++)
    {
        if (_materias[i]->getType() == type)
            return (_materias[i]->clone());
    }
    std::cerr << "Materia type is unkown" << std::endl;
    return (0);
}
