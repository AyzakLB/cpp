#include <stack>
#include <iostream>

int main()
{
    std::stack<int> s;
    s.push(1);
    s.push(2);
    std::cout << s.empty() << std::endl;
    std::cout << s.top() << std::endl;
    s.pop();
    std::cout << s.top() << std::endl;
    std::cout << s.empty() << std::endl;
    std::cout << s.empty() << std::endl;
    std::cout << s.empty() << std::endl;
}