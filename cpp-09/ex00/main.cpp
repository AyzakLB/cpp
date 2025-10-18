// #include "BitcoinExchange.hpp"

#include <iostream>
#include <list>
#include <string>
#include <sstream>
#include <exception>

long long strToLong(std::string number)
{
    std::istringstream ss(number);
    long long n;
    ss >> n;
    return n;
}

std::list<std::string> split(std::string string, char delimiter)
{
    std::list<std::string> list;
    int i;
    while ((i = string.find(delimiter)) != -1)
    {
        list.push_back(string.substr(0, i));
        string = string.substr(i + 1);
    }
    if (string.size() >= 1)
        list.push_back(string);
    return list;
}

bool dateIsValid(std::string date)
{
    std::list<std::string> list = split(date, '-');
    if (list.size() != 3)
        throw std::runtime_error("wrong date format");
    std::list<std::string>::iterator it = list.begin();
    long long year = strToLong(*(it++)); 
    if (year ) 
    long long month = strToLong(*(it++)); 
    long long day = strToLong(*(it++)); 
    // std::cout << year << " " << month << " " << day;

    return 1;
}

int main(int ac, char **av){
    if (ac != 2)
    {
        std::cerr << "program format: btc 'FILE'" << std::endl;
        return 1;
    }

    dateIsValid(av[1]);
}
