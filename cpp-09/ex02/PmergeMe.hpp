# pragma once
# include <iostream>
# include <vector>
# include <deque>
# include <sstream>
# include <algorithm>
# include <ctime>
# include <limits.h>
#include <cstdlib>

class PmergeMe
{
    std::vector<int> _numberVector;
    std::deque<int> _numberDeque;
    std::vector<int> _numbers;
    public:
        PmergeMe();
        PmergeMe(const PmergeMe& other);
        PmergeMe &operator=(const PmergeMe &other);
        ~PmergeMe();
        void start(int ac, char **av);
        std::vector<int> sortVector(std::vector<int> input, int level);
        std::deque<int> sortDeque(std::deque<int> input, int level);
};


