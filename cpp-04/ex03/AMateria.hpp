#ifndef AMATERIA_HPP
# define AMATERIA_HPP
# include <iostream>
# include "ICharacter.hpp"


class ICharacter;
class AMateria
{
    protected:
        std::string _type;
        bool _isEquiped;
    public:
        AMateria(void);
        AMateria(std::string const &type);
        AMateria(const AMateria& other);
        AMateria &operator=(const AMateria &other);
        virtual ~AMateria();
        std::string const & getType() const;
        bool getIsEquiped() const;
        void setIsEquiped(bool isEquiped);
        virtual AMateria* clone() const = 0;
        virtual void use(ICharacter& target);
};

#endif

