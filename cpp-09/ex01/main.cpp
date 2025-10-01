#include "RPN.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cerr << "Error" << std::endl;
        return 1;
    }
    try{
        RPN::calculate(av[1]);
    } catch (const std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    return 0;
}