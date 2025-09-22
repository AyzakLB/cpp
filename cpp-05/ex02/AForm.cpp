#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(void) : _name("nameless form"), _isSigned(false), _gradeToSign(150), _gradeToExecute(150) {}

AForm::AForm(const std::string &name, int gradeToSign, int gradeToExecute)
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
AForm::AForm(const AForm &other) : _name(other._name), _isSigned(other._isSigned), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute) {}

AForm &AForm::operator=(const AForm &other)
{
    if (this != &other)
        _isSigned = other._isSigned;
    return *this;
}

AForm::~AForm(void){}

std::string AForm::getName()  const{ return _name; }

bool AForm::getIsSigned() const { return _isSigned; }

int AForm::getGradeToSign()  const{ return _gradeToSign; }

int AForm::getGradeToExecute()  const{ return _gradeToExecute; }

void AForm::beSigned(const Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() > _gradeToSign)
        throw GradeTooLowException();
    _isSigned = true;
}

std::ostream &operator<<(std::ostream &os, const AForm &form)
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

void AForm::execPermission(Bureaucrat const &slave) const
{
    if (_isSigned == false)
        throw FormNotSigned();
    if (slave.getGrade() > _gradeToExecute)
        throw GradeTooLowException();
}
// exception 

AForm::GradeTooHighException::GradeTooHighException(long long grade)
{
    std::stringstream stream;
    stream << "grade " << grade << " is too high, highest possible grade is 1";
    _message = stream.str();
}

AForm::GradeTooLowException::GradeTooLowException(long long grade)
{
    std::stringstream stream;
    stream << "grade " << grade << " is too low, lowest possible grade is 150";
    _message = stream.str();
}

AForm::GradeTooLowException::GradeTooLowException()
{
    _message = "grade is too low";
}

const char *AForm::GradeTooHighException::what() const throw()
{
    return _message.c_str();
}

const char *AForm::GradeTooLowException::what() const throw()
{
    return _message.c_str();
}


