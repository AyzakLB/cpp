#include <iostream>

int main()
{
    int *a = new int();
    *a = 89;
    std::cout << *a << std::endl;
    return 0;
}