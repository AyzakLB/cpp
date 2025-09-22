#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("nameless bureaucrat"), _grade(150) {}

Bureaucrat::Bureaucrat(const std::string &name, long long grade) : _name(name)
{
    if (grade < 1)
        throw GradeTooHighException(grade);
    else if (grade > 150)
        throw GradeTooLowException(grade);
    _grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : _name(other._name), _grade(other._grade) {}

Bureaucrat::~Bureaucrat(){}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other) {
    if (this != &other)
        _grade = other._grade;
    return *this;
}

int Bureaucrat::getGrade() const
{
    return _grade;
}

std::string Bureaucrat::getName() const
{
    return _name;
}

void Bureaucrat::incrementGrade()
{
    if (_grade == 1)
        throw GradeTooHighException(_grade - 1);
    _grade--;
}

void Bureaucrat::decrementGrade()
{
    if (_grade == 150)
        throw GradeTooLowException(_grade + 1);
    _grade++;
}

void Bureaucrat::signForm(Form &form)
{
    try {
        form.beSigned(*this);
        std::cout << getName() << " signed " << form.getName() << std::endl;
    } catch (const Form::GradeTooLowException &e) {
        std::cout << getName() << " couldn't sign " << form.getName() << " because " << e.what() << ", required grade to sign is " << form.getGradeToSign() << std::endl;
    }
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &slave)
{
    os << slave.getName() << ", bureaucrat grade " << slave.getGrade() << std::endl;
    return os;
}

// exceptions

Bureaucrat::GradeTooHighException::GradeTooHighException(long long grade)
{
    std::stringstream stream;
    stream << "grade " << grade << " is too high, highest possible grade is 1";
    _message = stream.str();
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
    return _message.c_str();
}

Bureaucrat::GradeTooLowException::GradeTooLowException(long long grade)
{
    std::stringstream stream;
    stream << "grade " << grade << " is too low, lowest possible grade is 150";
    _message = stream.str();
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
    return _message.c_str();
}
