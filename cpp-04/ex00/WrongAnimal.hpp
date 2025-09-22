#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP
# include <iostream>

class WrongAnimal
{
    protected:
        std::string _type;
    public:
        WrongAnimal(void);
        WrongAnimal(const WrongAnimal& other);
        WrongAnimal &operator=(const WrongAnimal &other);
        ~WrongAnimal();
        void makeSound(void) const;
        const std::string &getType(void) const;
};

#endif

