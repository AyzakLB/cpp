#include "PmergeMe.hpp"

int main(int ac, char **av)
{
    
    if (ac < 2)
    {
        std::cerr << "Error: provide integers as arguments" << std::endl;
        return 1;
    }

    PmergeMe p;
    try {
        p.start(ac, av);
    } catch (const std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    
}
