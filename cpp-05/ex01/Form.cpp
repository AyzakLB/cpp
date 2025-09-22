#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(void) : _name("nameless form"), _isSigned(false), _gradeToSign(150), _gradeToExecute(150) {}

Form::Form(const std::string &name, int gradeToSign, int gradeToExecute)
    : _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
    if (gradeToSign < 1)
        throw GradeTooHighException(gradeToSign);
    if (gradeToExecute < 1)
        throw GradeTooHighException(gradeToExecute);
    if (gradeToSign > 150)
        throw GradeTooLowException(gradeToSign);
    if (gradeToExecute > 150)
        throw GradeTooLowException(gradeToExecute);
}
Form::Form(const Form &other) : _name(other._name), _isSigned(other._isSigned), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute) {}

Form &Form::operator=(const Form &other)
{
    if (this != &other)
        _isSigned = other._isSigned;
    return *this;
}

Form::~Form(void){}

std::string Form::getName()  const{ return _name; }

bool Form::getIsSigned() const { return _isSigned; }

int Form::getGradeToSign()  const{ return _gradeToSign; }

int Form::getGradeToExecute()  const{ return _gradeToExecute; }

void Form::beSigned(const Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() > _gradeToSign)
        throw GradeTooLowException();
    _isSigned = true;
}

std::ostream &operator<<(std::ostream &os, const Form &form)
{
    os << "name: " << form.getName() << std::endl;
    if (form.getIsSigned())
        os << "the form is signed" << std::endl;
    else
        os << "the form is not signed" << std::endl;
    os << "grade to sign: " << form.getGradeToSign() << std::endl
       << "grade to execute: " << form.getGradeToExecute() << std::endl;
    return os;
}

// exception 

Form::GradeTooHighException::GradeTooHighException(long long grade)
{
    std::stringstream stream;
    stream << "grade " << grade << " is too high, highest possible grade is 1";
    _message = stream.str();
}

Form::GradeTooLowException::GradeTooLowException(long long grade)
{
    std::stringstream stream;
    stream << "grade " << grade << " is too low, lowest possible grade is 150";
    _message = stream.str();
}

Form::GradeTooLowException::GradeTooLowException()
{
    _message = "grade is too low";
}

const char *Form::GradeTooHighException::what() const throw()
{
    return _message.c_str();
}

const char *Form::GradeTooLowException::what() const throw()
{
    return _message.c_str();
}


