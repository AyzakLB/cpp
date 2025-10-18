#include "PmergeMe.hpp"
#include <sstream>

template <typename Container>
void printContainer(const Container &c) {
    typename Container::const_iterator it;
    for (it = c.begin(); it != c.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;
}

int main(int argc, char **argv) {
    if (argc < 2) {
        std::cerr << "Error: provide integers as arguments" << std::endl;
        return 1;
    }

    std::vector<int> vec;
    // std::deque<int> deq;

    for (int i = 1; i < argc; i++) {
        std::istringstream iss(argv[i]);
        int num;
        if (!(iss >> num) || num < 0) {
            std::cerr << "Error" << std::endl;
            return 1;
        }
        vec.push_back(num);
        // deq.push_back(num);
    }

    std::cout << "Before: ";
    printContainer(vec);

    // Vector timing
    clock_t start = clock();
    PmergeMe::sortVector(vec);
    clock_t end = clock();
    double vecTime = (double)(end - start) / CLOCKS_PER_SEC * 1e6;

    // Deque timing
    start = clock();
    // // PmergeMe::sortDeque(deq);
    end = clock();
    // double deqTime = (double)(end - start) / CLOCKS_PER_SEC * 1e6;

    std::cout << "After: ";
    printContainer(vec);

    std::cout << "Time to process a range of " << vec.size()
              << " elements with std::vector : " << vecTime << " us" << std::endl;
    // std::cout << "Time to process a range of " << deq.size()
            //   << " elements with std::deque : " << deqTime << " us" << std::endl;

    return 0;
}
