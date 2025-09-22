#include <iostream>
#include <exception>
#include <sstream>

class Bureaucrat {
    const std::string _name;
    long long _grade;
    public:
        Bureaucrat(void);
        Bureaucrat(const std::string &name, long long grade);
        Bureaucrat(const Bureaucrat &other);
        ~Bureaucrat(void);
        Bureaucrat &operator=(const Bureaucrat &other);
        std::string getName() const;
        int getGrade() const;
        void incrementGrade();
        void decrementGrade();
        class GradeTooHighException : public std::exception {
            std::string _message;
            public:
                GradeTooHighException(long long grade);
                ~GradeTooHighException() throw() {} ;
                const char *what() const throw();
        };
       class GradeTooLowException : public std::exception {
            std::string _message;
            public:
                GradeTooLowException(long long grade);
                ~GradeTooLowException() throw() {};
                const char *what() const throw();
        };
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &slave);