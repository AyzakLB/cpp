#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"


void freeAnimals(Animal **animals, int count)
{
    for (int i = 0; i < count; i++)
    {
        if (animals[i])
            delete animals[i];
    }
}

int main()
{
    Animal *animals[100];

    for (int i = 0; i < 50; i++)
    {
        animals[i] = new(std::nothrow) Dog();
        if (!animals[i])
        {
            std::cout << "Memory allocation failed for Dog in main!!!!" << std::endl;
            freeAnimals(animals, i);
            return 1;
        }
    }
    for (int i = 50; i < 100; i++)
    {
        animals[i] = new(std::nothrow) Cat();
        if (!animals[i])
        {
            std::cout << "Memory allocation failed for Cat in main!!!!" << std::endl;
            freeAnimals(animals, i);
            return 1;
        }
    }
    for (int i = 0; i < 100; i++)
        delete animals[i];
    std::cout << "-----------------------------------------------------------" << std::endl;
    Animal *dog1 = new(std::nothrow) Dog();
    Animal *dog2 = new(std::nothrow) Dog();

    if (!dog1)
    {
        std::cout << "Memory allocation failed for Dog in main!!!!" << std::endl;
        return 1;
    }
    if (!dog2)
    {
        std::cout << "Memory allocation failed for Dog in main!!!!" << std::endl;
        delete dog1;
        return 1;
    }
    dog1->makeSound();
    *dog2 = *dog1;
    dog2->makeSound();
    delete dog1;
    delete dog2;
}