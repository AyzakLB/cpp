#include <iostream>
#include "iter.hpp"

template<typename T>
void print(const T &x) {
    std::cout << x << " ";
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    size_t size = sizeof(arr) / sizeof(arr[0]);
    iter(arr, size, print<int>);
    std::cout << std::endl;
    char arr2[] = {'a', 'b', 'c', 'd', 'e'};
    size_t size2 = sizeof(arr2) / sizeof(arr2[0]);
    iter(arr2, size2, print<char>);
    std::cout << std::endl;
    const char* arr3[] = {"hello", "world", "!"};
    size_t size3 = sizeof(arr3) / sizeof(arr3[0]);
    iter(arr3, size3, print<const char*>);
    return 0;
}