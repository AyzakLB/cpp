#include <iostream>
#include "Serializer.hpp"


int main()
{
    Data data;

    data.age = 60;
    data.name = "lhaj";
    Data *dataPtrOG = &data;
    std::cout << "data pointer " << dataPtrOG << std::endl;
    uintptr_t intRep = Serializer::serialize(&data);
    std::cout << "the int representation of the pointer " << intRep << std::endl;
    std::cout << "the byte before the pointer " << intRep - 1 << std::endl;
    std::cout << "the byte after the pointer " << intRep + 1 << std::endl; 
    Data *dataPtrDeserialized = Serializer::deserialize(intRep);
    std::cout << "the int pointer after being deserialized " << dataPtrDeserialized << std::endl;
    std::cout << dataPtrDeserialized->age << std::endl;
    std::cout << dataPtrDeserialized->name << std::endl;
    return 0;
}