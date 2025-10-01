#include <iostream>

int main()
{
    std::string str1("2025-08-23");
    int yearIn = str1.find('-');
    std::string date = str1.substr(0, yearIn);
    int monthIn = str1.find('-', yearIn + 1);
    std::string month = str1.substr(yearIn + 1, monthIn - yearIn - 1);
    int dayIn = str1.find('-', monthIn + 1);
    std::string day = str1.substr(monthIn + 1, dayIn - monthIn - 1);
    std::cout <<  date << std::endl;
    std::cout <<  month << std::endl;
    std::cout << month << std::endl;
}