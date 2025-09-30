#include "easyfind.hpp"
#include <vector>
#include <list>
#include <deque>
#include <iostream>

int main()
{
    try {

        int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        size_t n = sizeof(arr) / sizeof(arr[0]);
    
        std::vector<int> vector_tmp;
        vector_tmp.insert(vector_tmp.begin(), arr, arr + n );
        const std::vector<int> vector1(vector_tmp);
        std::vector<int>::const_iterator it_vector = easyfind(vector1, 5);
        std::cout << "the vetor iterator value: " << *it_vector << std::endl;
    
        std::list<int> list1;
        list1.insert(list1.begin(), arr, arr + n);
        std::list<int>::iterator it_list = easyfind(list1, 10);
        std::cout << "the list iterator value: " <<  *it_list << std::endl;
    
    
        std::deque<int> deque1;
        deque1.insert(deque1.begin(), arr, arr + n);
        std::deque<int>::iterator it_deque = easyfind(deque1, 19);
        std::cout << "the deque iterator value: " << *it_deque << std::endl;

    } catch (const std::runtime_error &e) {
        std::cout << e.what() << std::endl;
    }
}