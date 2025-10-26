#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}
PmergeMe::PmergeMe(const PmergeMe &other) { (void) other; return ; }
PmergeMe &PmergeMe::operator=(const PmergeMe &other) { (void) other; return (*this); }
PmergeMe::~PmergeMe(void) { return ; }

static int isValidNumber(std::string str)
{
    for (size_t i = 0; i < str.length(); ++i)
    {
        if (str[i] < '0' || str[i] > '9')
            throw std::runtime_error( "[" + str + "]" + " is not a valid input!");
    }
    std::stringstream ss(str);
    long long n;
    ss >> n;
    if (n < 0)
            throw std::runtime_error( "[" + str + "]" + " negative numbers are not allowed!");
    if (n > INT_MAX)
        throw std::runtime_error("[" + str + "]" + " is not an int!");
    return n;

}

std::deque<int> PmergeMe::sortDeque(std::deque<int> input, int level)
{
    std::deque<int> bigBoyz;
    std::deque<int> smallBoyz;
    std::deque<int> sortedBigBoyz;
    int              chyata = -1;

    if (input.size() == 1)
        return input;
    if (input.size() % 2 != 0)
    {
        chyata = input.back();
        input.pop_back();
    }
    for (size_t i = 0; i + 1 < input.size(); i += 2)
    {
        if (input[i] > input[i + 1])
        {
            bigBoyz.push_back(input[i]);
            smallBoyz.push_back(input[i + 1]);
        } else
        {
            smallBoyz.push_back(input[i]);
            bigBoyz.push_back(input[i + 1]);
        }
    }
    sortedBigBoyz = sortDeque(bigBoyz, level + 1);
    for (size_t i = 0; i < smallBoyz.size(); ++i)
    {
        int curr = smallBoyz[i];
        std::deque<int>::iterator max;
        max = std::find(sortedBigBoyz.begin(), sortedBigBoyz.end(), bigBoyz[i]);
        sortedBigBoyz.insert(std::lower_bound(sortedBigBoyz.begin(), max, curr), curr);
    }
    if (chyata != -1)
        sortedBigBoyz.insert(std::lower_bound(sortedBigBoyz.begin(), sortedBigBoyz.end(), chyata), chyata);
    return sortedBigBoyz;

}
std::vector<int> PmergeMe::sortVector(std::vector<int> input, int level)
{
    std::vector<int> bigBoyz;
    std::vector<int> smallBoyz;
    std::vector<int> sortedBigBoyz;
    int              chyata = -1;

    if (input.size() == 1)
        return input;
    if (input.size() % 2 != 0)
    {
        chyata = input.back();
        input.pop_back();
    }
    for (size_t i = 0; i + 1 < input.size(); i += 2)
    {
        if (input[i] > input[i + 1])
        {
            bigBoyz.push_back(input[i]);
            smallBoyz.push_back(input[i + 1]);
        } else
        {
            smallBoyz.push_back(input[i]);
            bigBoyz.push_back(input[i + 1]);
        }
    }
    sortedBigBoyz = sortVector(bigBoyz, level + 1);
    for (size_t i = 0; i < smallBoyz.size(); ++i)
    {
        int curr = smallBoyz[i];
        std::vector<int>::iterator max; 
        max = std::find(sortedBigBoyz.begin(), sortedBigBoyz.end(), bigBoyz[i]);
        sortedBigBoyz.insert(std::lower_bound(sortedBigBoyz.begin(), max, curr), curr);
    }
    if (chyata != -1)
        sortedBigBoyz.insert(std::lower_bound(sortedBigBoyz.begin(), sortedBigBoyz.end(), chyata), chyata);
    return sortedBigBoyz;
}

void printVector(std::vector<int> v)
{
    std::vector<int>::iterator it = v.begin();
    for (; it != v.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;
}

void PmergeMe::start(int ac, char **av)
{
    for (int i = 1; i < ac; ++i)
    {
        int n = isValidNumber(av[i]);
        if (std::find(_numbers.begin(), _numbers.end(), n) != _numbers.end())
            throw std::runtime_error("[" + std::string(av[i]) + "]" + " duplicates not allowed");
        _numbers.push_back(n);
    }
    clock_t start = clock();
    _numberDeque = std::deque<int>(_numbers.begin(), _numbers.end());
    _numberDeque = sortDeque(_numberDeque, 0);
    clock_t end = clock();
    double dequeTime = (double)((end - start) * 1000000) / CLOCKS_PER_SEC;
    start = clock();
    _numberVector = std::vector<int>(_numbers.begin(), _numbers.end());
    _numberVector = sortVector(_numberVector, 0);
    end = clock();
    double vectorTime = (double)(end - start) * 1000000 / CLOCKS_PER_SEC;
    std::cout << "before sorting: "; printVector(_numbers);
    std::cout << "after sorting: "; printVector(_numberVector);
    std::cout << "vector is sorted in ==> " << std::is_sorted(_numberVector.begin(), _numberVector.end()) << " " << vectorTime << " us" << std::endl;
    std::cout << "deque is sorted in  ==> " << std::is_sorted(_numberDeque.begin(), _numberDeque.end())  << " " << dequeTime << " us" << std::endl;
    return ;
}