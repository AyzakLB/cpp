#include "BitcoinExchange.hpp"
std::list<std::string> BitcoinExchange::split(std::string string, char delimiter)
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


const std::map<t_date, float> BitcoinExchange::_bitcoinDB = BitcoinExchange::initDB();

std::map<t_date, float> BitcoinExchange::initDB()
{
    std::map<t_date, float> db;
    std::fstream inputFile("data.csv");
    if (inputFile.is_open() == false)
        throw std::runtime_error("couldn't open 'data.csv'");
    
    std::string line;
    std::getline(inputFile, line);
    while(std::getline(inputFile, line))
    {
        std::list<std::string> list = split(line, ',');
        std::istringstream ss(list.back()); list.pop_back();
        std::string date = list.back(); list.pop_back();
        t_date d = splitDate(date);
        double value;
        ss >> value;
        db[d] = value;
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

BitcoinExchange::BitcoinExchange() {} 
BitcoinExchange::BitcoinExchange(const std::string &input, const size_t &line) : _input(input), _line(longToStr(line)) {} 
BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) : _date(other._date) {}
BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
    if (this != &other)
        return *this;
    return (*this);
}
BitcoinExchange::~BitcoinExchange(void) {}


bool BitcoinExchange::hasNonDigit(std::list<std::string> list)
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

long long BitcoinExchange::strToLong(std::string number)
{
    std::istringstream ss(number);
    long long n;
    ss >> n;
    return n;
}
t_date BitcoinExchange::splitDate(std::string _date)
{
    t_date date;
    std::list<std::string> list = split(_date, '-');
    if (list.size() != 3)
        throw invalidDate(_date, _line);
    if (hasNonDigit(list))
        throw invalidDate(_date, _line);
    date.day = strToLong(list.back()); list.pop_back();
    date.month = strToLong(list.back()); list.pop_back();
    date.year = strToLong(list.back());
    return date;
}

t_date BitcoinExchange::getCurrDate()
{
    time_t currentTime;
    time(&currentTime);
    struct tm* localTime = localtime(&currentTime);
    char dateBuffer[80];
    strftime(dateBuffer, sizeof(dateBuffer), "%Y-%m-%d", localTime);
    return splitDate(dateBuffer);
}
std::string BitcoinExchange::longToStr(long long number)
{
    std::ostringstream ss;
    ss << number;
    return ss.str();
}

void BitcoinExchange::dateIsValid() // throws!
{
    
    t_date date = splitDate(_date);
    t_date currDate = getCurrDate();
    if (date.year > currDate.year || date.year < 2009)
        throw invalidDate(_date, _line);
    else if (date.month > 12 || date.month < 1)
        throw invalidDate (_date, _line);
    else if (date.day < 1)
        throw invalidDate(_date, _line);
    else if ((date.month == 4 || date.month == 6 || date.month == 9 || date.month == 11) && date.day > 30)
        throw invalidDate(_date, _line);
    else if ((date.month == 1 || date.month == 3 || date.month == 5 || date.month == 7  ||  date.month == 8 || date.month == 10 || date.month == 12 ) && date.day > 31)
        throw invalidDate(_date, _line);
    else if (date.month == 2)
    {
        bool isLeap = ((date.year % 4 == 0) && (date.year % 100 != 0 || date.year % 400 == 0));
        if (date.day > 29)
            throw invalidDate(_date, _line);
        else if (date.day == 29 && (isLeap == false))
            throw invalidDate(_date, _line);
    } else if (date.year == 2009 && date.month == 1 && date.day == 1)
        throw invalidDate(_date, _line);
}

void BitcoinExchange::parseInput()
{
    std::list<std::string> list = split(_input, '|');
    if (list.size() != 2)
        throw std::runtime_error(error("bad input", _input));
    std::string number = trim(list.back()); list.pop_back();
    _date = trim(list.back());
    for (size_t i = 0; i <  number.size(); ++i)
    {
        if (isspace(number[i]))
            continue;
        if (number[i] < '0' || number[i] > '9')
            throw std::runtime_error(error("invalid value", number));
    }
    long long n = strToLong(number);
    if (n < 0)
        throw std::runtime_error(error("not a positive number", number));
    if (n > 1000)
        throw std::runtime_error(error("too large a number", number));
    _value = n;
}
void BitcoinExchange::start()
{
    try 
    {
        parseInput();
        dateIsValid();
        t_date date = splitDate(_date);
        
    } catch (const std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    
}

std::string BitcoinExchange::error(std::string errorMsg, std::string value)
{
    return "Error: " + errorMsg + ": '" + value + "' at line ==> [" + _line + "]";
}
// exception implementations
BitcoinExchange::invalidDate::~invalidDate() throw() {}
BitcoinExchange::invalidDate::invalidDate(std::string date, std::string line) : _message("invalid date format ==> " + date + " at line " + line) {}
const char *BitcoinExchange::invalidDate::what() const throw()  {return _message.c_str();}