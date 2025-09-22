#ifndef CHARACTER_HPP
# define CHARACTER_HPP
# include <iostream>
# include "ICharacter.hpp"

class Character : public ICharacter
{
    private:
        std::string _name;
        AMateria *_inventory[4];
        static AMateria **_unequiped;
        static size_t _unequipedSize;
    public:
        Character(void);
        Character(const std::string &name);
        Character(const Character& other);
        Character &operator=(const Character &other);
        ~Character();
        std::string const &getName() const;
        void equip(AMateria* m);
        void unequip(int idx);
        void use(int idx, ICharacter& target);
        static void addUnequiped(AMateria *materia);
        static void removeUnequiped(AMateria *materia);
        static void clearUnequiped();
        static int expandUnequiped();
};

#endif

