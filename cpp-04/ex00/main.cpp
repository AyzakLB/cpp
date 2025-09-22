#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
    const Animal* dog = new(std::nothrow) Dog();
    if (!dog)
    {
        std::cerr << "Memory allocation failed for Dog in main!!!!" << std::endl;
        return 1;
    }
    const Animal* cat = new(std::nothrow) Cat();
    if (!cat)
    {
        std::cerr << "Memory allocation failed for Cat in main!!!!" << std::endl;
        delete dog;
        return 1;
    }
    const WrongAnimal* wrongCat = new(std::nothrow) WrongCat();
    if (!wrongCat)
    {
        std::cerr << "Memory allocation failed for WrongCat in main!!!!" << std::endl;
        delete dog;
        delete cat;
        return 1;
    }

    std::cout << cat->getType() << " " << std::endl;
    std::cout << dog->getType() << " " << std::endl;
    std::cout << wrongCat->getType() << " " << std::endl;
    
    cat->makeSound(); 
    dog->makeSound(); 
    wrongCat->makeSound();

    delete dog;
    delete cat;
    delete wrongCat;
    return 0;
}