#include "Array.hpp"
#include <iostream>
int main() {
    try {
        Array<int> empty;
        std::cout << "Empty array size: " << empty.size() << std::endl;
        
        Array<int> arr(5);
        std::cout << "Array size: " << arr.size() << std::endl;
        
        for (unsigned int i = 0; i < arr.size(); ++i) {
            arr[i] = i;
        }
        
        std::cout << "Array elements: ";
        for (unsigned int i = 0; i < arr.size(); ++i) {
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;
        
        Array<int> copy(arr);
        std::cout << "Copy size: " << copy.size() << std::endl;
        
        arr[0] = 999;
        std::cout << "Original arr[0]: " << arr[0] << std::endl;
        std::cout << "Copy arr[0]: " << copy[0] << std::endl;
        
        Array<int> assigned;
        assigned = arr;
        std::cout << "Assigned size: " << assigned.size() << std::endl;
        
        std::cout << "Testing out of bounds index" << std::endl;
        arr[10]; // throws!
        
    } catch (const std::exception& e) {
        std::cout << "out of bounds access" << std::endl;
    }
    
    return 0;
}