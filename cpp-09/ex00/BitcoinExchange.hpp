#pragma once
// #include "exceptions.cpp"
#include <iostream>
#include <list>
#include <string>
#include <sstream>
#include <exception>
#include <ctime>
#include <map>
#include <fstream>                                     
typedef struct s_date 
{
    long long year;
    long long month;
    long long day;
} t_date;

class BitcoinExchange
{
    std::string _date;
    float _value;
    std::string _input;
    std::string _inputFileName;
    std::string _line;
    static  const std::map<std::string, float> _bitcoinDB;
    BitcoinExchange(void);
    public:
        BitcoinExchange(const std::string&);
        BitcoinExchange(const BitcoinExchange& other);
        BitcoinExchange &operator=(const BitcoinExchange &other);
        ~BitcoinExchange();
        void start();
        void parseInput();
        t_date splitDate(std::string dateStr);
        std::string longToStr(double number);
        std::string error(std::string, std::string);
        static std::map<std::string, float> initDB();
        std::map<std::string, float>::const_iterator getValue();
};


