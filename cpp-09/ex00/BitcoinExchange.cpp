#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() : _line("0") {} 
BitcoinExchange::BitcoinExchange(const std::string &inputFileName) : _inputFileName(inputFileName), _line("0") {} 
BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) : _date(other._date) {}
BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
    if (this != &other)
        return *this;
    return (*this);
}
BitcoinExchange::~BitcoinExchange(void) {}

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

const std::map<std::string, float> BitcoinExchange::_bitcoinDB = BitcoinExchange::initDB();


std::map<std::string, float> BitcoinExchange::initDB()
{
    std::map<std::string, float> db;
    std::ifstream inputFile("data.csv");
    if (!inputFile.is_open())
        throw std::runtime_error("couldn't open data.csv");
    std::string line;
    std::getline(inputFile, line);
    while(std::getline(inputFile, line))
    {
        std::list<std::string> list = split(line, ',');
        std::istringstream ss(list.back()); list.pop_back();
        std::string date = list.back();
        double value;
        ss >> value;
        db[date] = value;;
    }
    inputFile.close();
    return db;
}

std::string trim(std::string string)
{
    size_t first = string.find_first_not_of(" \t\r\n\f\v");
    size_t last = string.find_last_not_of(" \t\r\n\f\v");
    return string.substr(first, last - first + 1);
}



bool hasNonDigit(std::list<std::string> list)
{
    std::list<std::string>::iterator it = list.begin();
    for (; it != list.end() ; ++it)
    {
        std::string number = *it;
        for (size_t i = 0; i < number.size(); i++)
        {
            if (number[i] < '0' || number[i] > '9')
                return true;
        }
    }
    return false;
}

float strToLong(std::string number)
{
    std::istringstream ss(number);
    double n;
    ss >> n;
    return n;
}
t_date BitcoinExchange::splitDate(std::string _date)
{
    t_date date;
    std::list<std::string> list = split(_date, '-');
    if (list.size() != 3)
        throw std::runtime_error(error("invalid date format", _date));
    if (hasNonDigit(list))
        throw std::runtime_error(error("invalid date format", _date));
    date.day = strToLong(list.back()); list.pop_back();
    date.month = strToLong(list.back()); list.pop_back();
    date.year = strToLong(list.back());
    return date;
}

std::string BitcoinExchange::longToStr(double number)
{
    std::ostringstream ss;
    ss << number;
    return ss.str();
}

t_date getCurrentDate()
{
    time_t now = time(0);
    tm *localTime = localtime(&now);
    t_date date;
    date.year = 1900 + localTime->tm_year;
    date.month = 1 + localTime->tm_mon;
    date.day = localTime->tm_mday;
    return date;
}

void BitcoinExchange::parseInput()
{
    std::list<std::string> list = split(_input, '|');
    if (list.size() != 2)
        throw std::runtime_error(error("bad input", _input));
    std::string number = trim(list.back()); list.pop_back();
    _date = trim(list.back());
    bool hasSign = false;
    bool hasDot = false;
    for (size_t i = 0; i <  number.size(); ++i)
    {
        if ((number[i] == '-' || number[i] == '+' )&& hasSign == false)
        {
            hasSign = true; 
            continue;
        }
        if (number[i] == '.' && hasDot == false)
        {
            hasDot = true; 
            continue;

        }
        if (number[i] < '0' || number[i] > '9' )
            throw std::runtime_error(error("invalid value", number));
    }
    float n = strToLong(number);
    if (n < 0)
        throw std::runtime_error(error("not a positive number", number));
    if (n > 1000)
        throw std::runtime_error(error("too large a number", number));
    _value = n;
}
static void checkHeader(std::string line)
{
    if (line != "date | value")
        throw std::runtime_error("Error: bad header in input file");
}
void BitcoinExchange::start()
{
    try
    {
        std::ifstream inputFile(_inputFileName.c_str());
        if (inputFile.is_open() == false)
            throw std::runtime_error("couldn't open " + _inputFileName);
        std::string line;
        std::getline(inputFile, line);
        checkHeader(line);  
        while (std::getline(inputFile, line))
        {
            try 
            {
                _input = line;
                parseInput();
                std::map<std::string, float>::const_iterator it = getValue();
                std::cout << _date << " => " << _value << " = " << it->second * _value << std::endl ;
            } catch (const std::exception &e)
            {
                std::cout << e.what() << std::endl;
            }
            long long n = strToLong(_line);
            n++;
            _line = longToStr(n);
        }

    } catch (const std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    
}

std::string BitcoinExchange::error(std::string errorMsg, std::string value)
{
    return "Error: " + errorMsg + ": '" + value + "' at line ==> [" + _line + "]";
}

std::map<std::string, float>::const_iterator BitcoinExchange::getValue()
{
    t_date date = splitDate(_date);
    t_date currDate = getCurrentDate();
    if (date.month > 12 || date.month < 1)
        throw std::runtime_error(error("invalid date format", _date));
    else if (date.day < 1)
        throw std::runtime_error(error("invalid date format", _date));
    else if ((date.month == 4 || date.month == 6 || date.month == 9 || date.month == 11) && date.day > 30)
        throw std::runtime_error(error("invalid date format", _date));
    else if ((date.month == 1 || date.month == 3 || date.month == 5 || date.month == 7  ||  date.month == 8 || date.month == 10 || date.month == 12 ) && date.day > 31)
        throw std::runtime_error(error("invalid date format", _date));
    else if (date.month == 2)
    {
        bool isLeap = ((date.year % 4 == 0) && (date.year % 100 != 0 || date.year % 400 == 0));
        if (date.day > 29)
            throw std::runtime_error(error("invalid date format", _date));
        else if (date.day == 29 && (isLeap == false))
            throw std::runtime_error(error("invalid date format", _date));
    }
    std::map<std::string, float>::const_iterator it;
    if (date.year > currDate.year || (date.year == currDate.year && date.month > currDate.month) || (date.year == currDate.year && date.month  == currDate.month && date.day > currDate.day))
        it = _bitcoinDB.end();
    else
        it = _bitcoinDB.lower_bound(_date);
    if (it != _bitcoinDB.begin() && it->first != _date)
        --it;
    return it;
}