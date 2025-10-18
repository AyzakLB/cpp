# pragma once
# include <iostream>
# include <vector>
# include <deque>

class PmergeMe
{
    public:
        PmergeMe(void);
        PmergeMe(const PmergeMe& other);
        PmergeMe &operator=(const PmergeMe &other);
        ~PmergeMe();
        static void sortVector(std::vector<int> &vec);
        static void sortDeque(std::deque<int> &deq);
        static void fordJohnsonVector(std::vector<int> &vec);
        static void fordJohnsonDeque(std::deque<int> &deq);
        static void insertSortedVector(std::vector<int> &sorted, int value);
        static void insertSortedDeque(std::deque<int> &sorted, int value);
};


