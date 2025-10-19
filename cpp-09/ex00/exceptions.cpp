#include <exception>
#include <iostream>

class invalidDate : public std::exception
{   
    std::string _date;
    public:
        invalidDate(std::string date) : _date("invalid date format ==> " + date) {} 
        virtual ~invalidDate() throw() {};
        const char *what() const throw() {
            return _date.c_str();
        }
};