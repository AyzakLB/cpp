#pragma once
#include <exception>

template <typename T>
typename T::iterator easyFind(T &container, int value)
{
    for (typename T::iterator it = container.begin(); it != container.end(); ++it)
    {
        if (*it == value)
            return it;
    }
    throw std::runtime_error("element not found");
}