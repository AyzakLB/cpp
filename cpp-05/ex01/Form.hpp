#pragma once
# include <iostream>

class Bureaucrat;
class Form
{
    const std::string _name;
    bool _isSigned;
    const int _gradeToSign;
    const int _gradeToExecute;
    public:
        Form(void);
        Form(const std::string &name, int gradeToSign, int gradeToExecute);
        Form(const Form& other);
        Form &operator=(const Form &other);
        ~Form();
        std::string getName()  const;
        bool getIsSigned() const;
        int  getGradeToSign() const;
        int  getGradeToExecute() const;
        void beSigned(const Bureaucrat &bureaucrat);
        class GradeTooHighException : public std::exception {
            std::string _message;
            public:
                GradeTooHighException(long long grade);
                ~GradeTooHighException() throw() {};
                const char *what() const throw();
        };
        class GradeTooLowException : public std::exception {
            std::string _message;
            public:
                GradeTooLowException();
                GradeTooLowException(long long grade);
                ~GradeTooLowException() throw() {};
                const char *what() const throw();
        };
};
std::ostream &operator<<(std::ostream &os, const Form &form);


