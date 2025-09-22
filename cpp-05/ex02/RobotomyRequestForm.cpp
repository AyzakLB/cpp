#include "RobotomyRequestForm.hpp"

static bool isSeeded = false;

RobotomyRequestForm::RobotomyRequestForm(void) : AForm("RobotomyRequestForm", 72, 45), _target("default_target") {}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45), _target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) : AForm(other), _target(other._target) {}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
    if (this != &other)
    {
        AForm::operator=(other);
        _target = other._target;
    }
    return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm(void){}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
        execPermission(executor);
        std::cout << "DRILLING NOISES... " << std::endl;
        if (isSeeded == false) {
            std::srand(std::time(0));
            isSeeded = true;
        }
        if (std::rand() % 2 == 0) {
            std::cout << _target << " has been robotomized successfully!" << std::endl;
        } else {
            std::cout << "Robotomy failed for " << _target << "!" << std::endl;
        }
}

