#pragma once
# include <iostream>

class Bureaucrat;
class AForm
{
    const std::string _name;
    bool _isSigned;
    const int _gradeToSign;
    const int _gradeToExecute;
    public:
        AForm(void);
        AForm(const std::string &name, int gradeToSign, int gradeToExecute);
        AForm(const AForm& other);
        AForm &operator=(const AForm &other);
        ~AForm();
        std::string getName()  const;
        bool getIsSigned() const;
        int  getGradeToSign() const;
        int  getGradeToExecute() const;
        void beSigned(const Bureaucrat &bureaucrat);
        virtual void execute(Bureaucrat const & executor) const = 0;
        void execPermission(Bureaucrat const &slave) const;
        // exceptions

        class FormNotSigned : public std::exception {
            public:
                const char *what() const throw(){
                    return "Form not signed";
                };
        };
        class GradeTooHighException : public std::exception {
            std::string _message;
            public:
                GradeTooHighException(long long grade);
                ~GradeTooHighException() throw() {};
                virtual const char *what() const throw();
        };
        class GradeTooLowException : public std::exception {
            std::string _message;
            public:
                GradeTooLowException();
                GradeTooLowException(long long grade);
                ~GradeTooLowException() throw() {};
                virtual const char *what() const throw();
        };
};
std::ostream &operator<<(std::ostream &os, const AForm &form);
