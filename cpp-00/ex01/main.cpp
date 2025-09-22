#include "header.hpp"

bool checkEof(std::string& input)
{
    if (!getline(std::cin, input) || std::cin.eof())
    {
        std::cerr << "getline failed OR reached EOF!" << std::endl; 
        return 1;
    }
    return 0;
}

int main()
{
    PhoneBook PhoneBook;
    std::string command;

    while (1)
    {
        std::cout << "Enter one of the following commands: ADD - SEARCH - EXIT " << std::endl;
        if(checkEof(command))
            break;
        if (command == "ADD")
        {
            if (PhoneBook.add())
                break;
        }
        else if (command == "SEARCH")
        {
            if (PhoneBook.search())
                break;
        }
        else if (command == "EXIT")
            break;
        else
            std::cout << "Invalid command." << std::endl;
    }   
    return 0;
}