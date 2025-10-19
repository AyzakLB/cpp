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
    std::string _line;
    static const std::map<t_date, float> _bitcoinDB;
    public:
        BitcoinExchange(void);
        BitcoinExchange(const std::string &input, const size_t &line);
        BitcoinExchange(const BitcoinExchange& other);
        BitcoinExchange &operator=(const BitcoinExchange &other);
        ~BitcoinExchange();
        void start();
        void parseInput();
        void dateIsValid(); // throws!
        static std::list<std::string> split(std::string string, char delimiter);
        bool hasNonDigit(std::list<std::string> list);
        static long long strToLong(std::string number);
        static t_date splitDate(std::string dateStr);
        t_date getCurrDate();
        static std::string longToStr(long long number);
        std::string error(std::string, std::string);
        static std::map<t_date, float> initDB();
        class invalidDate : public std::exception{
            std::string _message;
            public:
                invalidDate(std::string date, std::string line);
                ~invalidDate() throw();
                const char *what() const throw();
        };
};


