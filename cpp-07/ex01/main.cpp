#include "iter.hpp"

template <typename Type1>
void isTrue(Type1 arg)
{
    std::cout << arg << std::endl;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 0} ;

    std::cout << "int array" << std::endl;
    iter(arr, 5, isTrue<int>);
    std::cout << "char array" << std::endl;
    char str[] = "hello world!";
    iter(str, 13, isTrue<char>);
    return 0;
}