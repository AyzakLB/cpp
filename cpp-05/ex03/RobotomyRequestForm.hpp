#pragma once
# include <iostream>
# include "AForm.hpp"
#include <fstream>
#include <ctime>
#include <cstdlib>

class RobotomyRequestForm : public AForm
{
    std::string _target;
    public:
        RobotomyRequestForm(void);
        RobotomyRequestForm(std::string target);
        RobotomyRequestForm(const RobotomyRequestForm& other);
        RobotomyRequestForm &operator=(const RobotomyRequestForm &other);
        ~RobotomyRequestForm();
        void execute(Bureaucrat const & executor) const;
};


