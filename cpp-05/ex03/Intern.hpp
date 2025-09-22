#pragma once
# include <iostream>
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

typedef AForm *(*formCreator)(std::string target);
class Intern
{
    public:
        Intern(void);
        Intern(const Intern& other);
        Intern &operator=(const Intern &other);
        ~Intern();
        AForm *makeForm(std::string formName, std::string target);

};


