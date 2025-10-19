#include "BitcoinExchange.hpp"




int main(int ac, char **av){
    if (ac != 2)
    {
        std::cerr << "program format: btc 'FILE'" << std::endl;
        return 1;
    }

    try {
        
        BitcoinExchange b(av[1], 1);
        b.start();
    } catch (const std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    
}
