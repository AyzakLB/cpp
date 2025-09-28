#include "iter.hpp"

template <typename Type1>
void isTrue(Type1 arg)
{
    if (arg)
        std::cout << "true";
    else
        std::cout << "false";
    std::cout << std::endl;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 0} ;
    iter(arr, 5, isTrue<int>); 
    return 0;
}