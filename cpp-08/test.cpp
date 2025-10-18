#include <iostream>


template <typename T = double>
void printvalue( )
{
    std::cout << sizeof(T) << std::endl;
}
int main()
{
    printvalue();
    printvalue<int>();
    printvalue<1>();
}