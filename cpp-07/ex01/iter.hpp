#pragma once
#include <iostream>

template <typename Type1 ,typename Function>
void iter(Type1 *array, unsigned int size, Function function) 
{
    for (unsigned int i = 0; i < size; ++i)
        function(array[i]);
}