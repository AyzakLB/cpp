#pragma once
# include <iostream>
# include "AForm.hpp"
#include <fstream>
#include <ctime>

class PresidentialPardonForm : public AForm
{
    std::string _target;
    public:
        PresidentialPardonForm(void);
        PresidentialPardonForm(std::string target);
        PresidentialPardonForm(const PresidentialPardonForm& other);
        PresidentialPardonForm &operator=(const PresidentialPardonForm &other);
        ~PresidentialPardonForm();
        void execute(Bureaucrat const & executor) const;
};


