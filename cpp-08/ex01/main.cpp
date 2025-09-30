#include "Span.hpp"
#include <iostream>
#include <list>
#include <deque>

int main()
{
std::cout << "school tests: " << std::endl;
Span sp = Span(5);
sp.addNumber(6);
sp.addNumber(3);
sp.addNumber(17);
sp.addNumber(9);
sp.addNumber(11);
std::cout << sp.shortestSpan() << std::endl;
std::cout << sp.longestSpan() << std::endl;

// my tests
std::cout << "my tests: " << std::endl;
std::vector<int> vector;
std::list<int> list;
int arr[100000];

for (int i = 0; i < 100000; i++)
{
    vector.push_back(i);
    list.push_back(i * 2);
    arr[i] = i * 3;
}

Span sp_vec(100002);
Span sp_list(100000);
Span sp_array(100000);

sp_array.addNumbers(arr, arr + 100000);
sp_vec.addNumbers(vector.begin(), vector.end());
sp_list.addNumbers(list.begin(), list.end());

std::cout << "longest span of vector : " << sp_vec.longestSpan() << std::endl;
std::cout << "longest span of list : " << sp_list.longestSpan() << std::endl;
std::cout << "logest span of array: " << sp_array.longestSpan() << std::endl;

std::cout << "shortest span of vector : " << sp_vec.shortestSpan() << std::endl;
std::cout << "shortest span of list : " << sp_list.shortestSpan() << std::endl;
std::cout << "shortest span of array: " << sp_array.shortestSpan() << std::endl;

sp_vec.addNumber(100000090);
std::cout << "longest span of vector : " << sp_vec.longestSpan() << std::endl;

sp_vec.addNumber(100000090);
std::cout << "shortest span of vector : " << sp_vec.shortestSpan() << std::endl;
try {
    sp_vec.addNumber(100000090);
} catch (const std::exception& e) {
    std::cerr << "Error: " << e.what() << std::endl;
}

return 0;
}