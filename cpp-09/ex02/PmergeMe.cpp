#include "PmergeMe.hpp"

PmergeMe::PmergeMe(void)
{
    return ;
}

PmergeMe::PmergeMe(const PmergeMe &other)
{
    (void) other;
    return ;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
    (void) other;
    return (*this);
}

PmergeMe::~PmergeMe(void)
{
    return ;
}

// ---- Utility insertion for vector ----
void PmergeMe::insertSortedVector(std::vector<int> &sorted, int value) {
    std::vector<int>::iterator pos =
        std::lower_bound(sorted.begin(), sorted.end(), value);
    sorted.insert(pos, value);
}

// ---- Utility insertion for deque ----
// void PmergeMe::insertSortedDeque(std::deque<int> &sorted, int value) {
//     std::deque<int>::iterator pos =
//         std::lower_bound(sorted.begin(), sorted.end(), value);
//     sorted.insert(pos, value);
// }

// ---- Ford-Johnson for vector ----
void PmergeMe::fordJohnsonVector(std::vector<int> &vec) {
    if (vec.size() <= 1)
        return;

    std::vector<int> winners;
    std::vector<int> losers;

    for (size_t i = 0; i < vec.size(); i += 2) {
        if (i + 1 < vec.size()) {
            if (vec[i] < vec[i+1]) {
                losers.push_back(vec[i]);
                winners.push_back(vec[i+1]);
            } else {
                losers.push_back(vec[i+1]);
                winners.push_back(vec[i]);
            }
        } else {
            losers.push_back(vec[i]);
        }
    }

    fordJohnsonVector(winners);

    for (size_t i = 0; i < losers.size(); i++)
        insertSortedVector(winners, losers[i]);

    vec = winners;
}
// ---- Ford-Johnson for deque ----
// void PmergeMe::fordJohnsonDeque(std::deque<int> &deq) {
//     if (deq.size() <= 1)
//         return;

//     std::deque<int> winners;
//     std::deque<int> losers;

//     for (size_t i = 0; i < deq.size(); i += 2) {
//         if (i + 1 < deq.size()) {
//             if (deq[i] < deq[i+1]) {
//                 losers.push_back(deq[i]);
//                 winners.push_back(deq[i+1]);
//             } else {
//                 losers.push_back(deq[i+1]);
//                 winners.push_back(deq[i]);
//             }
//         } else {
//             losers.push_back(deq[i]);
//         }
//     }

//     fordJohnsonDeque(winners);

//     for (size_t i = 0; i < losers.size(); i++)
//         insertSortedDeque(winners, losers[i]);

//     deq = winners;
// }

void PmergeMe::sortVector(std::vector<int> &vec) {
    fordJohnsonVector(vec);
}

// void PmergeMe::sortDeque(std::deque<int> &deq) {
//     fordJohnsonDeque(deq);
// }
