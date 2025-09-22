#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "MateriaSource.hpp"


int main()
{
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    ICharacter* me = new Character("me");
    AMateria* tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);
    ICharacter* bob = new Character("bob");
    me->use(0, *bob);
    me->use(1, *bob);
    delete bob;
    delete me;
    delete src;

    std::cout << "------------------------" << std::endl;

    IMateriaSource *materias = new(std::nothrow) MateriaSource();
    if (!materias)
    {
        std::cerr << "Memory allocation failed for materias" << std::endl;
        return 1;
    }
    materias->learnMateria(new Ice());
    materias->learnMateria(new Cure());
    ICharacter *Geralt = new(std::nothrow) Character("Geralt");
    if (!Geralt)
    {
        std::cerr << "Memory allocation failed for Geralt" << std::endl;
        delete materias;
        return 1;
    } 
    ICharacter *Morgan = new(std::nothrow) Character("Morgan");
    if (!Morgan)
    {
        std::cerr << "Memory allocation failed for Morgan" << std::endl;
        delete Geralt;
        delete materias;
        return 1;
    }
    AMateria *tmp2 = materias->createMateria("ice");
    if (!tmp2)
    {
        std::cerr << "Memory allocation failed for tmp2" << std::endl;
        delete Geralt;
        delete Morgan;
        delete materias;
        return 1;
    }
    Geralt->equip(tmp2);
    Morgan->equip(tmp2);
    Geralt->use(0, *Morgan);
    Morgan->use(0, *Geralt);
    Geralt->unequip(0);
    Morgan->equip(tmp2);
    Morgan->unequip(0);
    Geralt->use(0, *Morgan);
    Morgan->use(0, *Geralt);
    delete Geralt;
    delete Morgan;
    delete materias;
    Character::clearUnequiped();
    std::cout << "------------------------" << std::endl;
return 0;
}