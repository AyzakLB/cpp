#include "MutantStack.hpp"
#include <iostream>
#include <list>
#include <vector>

template <typename begin, typename end>
void printStack(begin itbegin, end itend)
{
    if (itbegin == itend)
        return ;
    begin temp = itbegin;
    printStack(++itbegin, itend);
    std::cout <<  *temp << std::endl;
}

int main()
{
int arr[] = {23, 4, -1, 242, 123234, 89, 0, 9, 8};
int n = sizeof(arr) / sizeof(arr[0]);

std::cout << "the MutantStack (with the container default, basically a deque) version!" << std::endl;
MutantStack<int> stack;
for (int i = 0; i < n; ++i)
    stack.push(arr[i]);
std::cout << "stack size: " << stack.size() << std::endl;
printStack(stack.begin(), stack.end());

std::cout << "popping the top element of the stack" << std::endl;
stack.pop();
printStack(stack.begin(), stack.end());
std::cout << "stack size: " << stack.size() << std::endl;
MutantStack<int>::iterator it = stack.begin();
it += 5;
std::cout << "printing the 5th element of the stack" << *it<<  std::endl;
*it = 50;
std::cout << "printing the 5th element of the stack" << *it<<  std::endl;
std::stack<int> stackCopy(stack);
std::cout << "printing the stackCopy: " << std::endl;
while (stackCopy.size() > 0)
{
    std::cout << stackCopy.top() << std::endl;
    stackCopy.pop();
}

std::cout << "the MutantStack with a vector version!" << std::endl;
MutantStack<int, std::vector<int> > stackVector;
for (int i = 0; i < n; ++i)
    stackVector.push(arr[i]);
std::cout << "stackVector size: " << stackVector.size() << std::endl;
printStack(stackVector.begin(), stackVector.end());

std::cout << "popping the top element of the stackVector" << std::endl;
stackVector.pop();
printStack(stackVector.begin(), stackVector.end());
std::cout << "stackVector size: " << stackVector.size() << std::endl;
MutantStack<int, std::vector<int> >::iterator it_vector = stackVector.begin();
it_vector += 5;
std::cout << "printing the 5th element of the stackVector" << *it_vector<<  std::endl;
*it_vector = 50;
std::cout << "printing the 5th element of the stackVector" << *it_vector<<  std::endl;
std::stack<int, std::vector<int> > stackCopyVector(stackVector);
std::cout << "printing the stackCopy: " << std::endl;
while (stackCopyVector.size() > 0)
{
    std::cout << stackCopyVector.top() << std::endl;
    stackCopyVector.pop();
}

std::cout << "the list version!" << std::endl;
std::list<int> list;
for (int i = 0; i < n; ++i)
    list.push_back(arr[i]);
std::cout << "list size: " << list.size() << std::endl;
printStack(list.begin(), list.end());
std::cout << "popping the top element of the list" << std::endl;
list.pop_back();
printStack(list.begin(), list.end());
std::cout << "list size: " << list.size() << std::endl;
std::list<int>::iterator it_list = list.begin();
for (int i = 0; i < 5; ++i)
    it_list++;
std::cout << "printing the 5th element of the list" << *it_list<<  std::endl;
*it_list = 50;
std::cout << "printing the 5th element of the list" << *it_list<<  std::endl;
std::stack<int, std::list<int> > stackCopyList(list);
std::cout << "printing the stackCopy: " << std::endl;
while (stackCopyList.size() > 0)
{
    std::cout << stackCopyList.top() << std::endl;
    stackCopyList.pop();
}
return 0;
}