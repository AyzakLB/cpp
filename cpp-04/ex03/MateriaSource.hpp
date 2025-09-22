#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include <iostream>
# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
    private:
        AMateria *_materias[4];
        int _count;
    public:
        MateriaSource(void);
        MateriaSource(const MateriaSource& other);
        MateriaSource &operator=(const MateriaSource &other);
        ~MateriaSource();
        void learnMateria(AMateria*);
        AMateria* createMateria(std::string const & type);
};

#endif

