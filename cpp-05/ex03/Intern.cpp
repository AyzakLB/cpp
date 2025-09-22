#include "Intern.hpp"

static std::string forms[3] = {
    "shrubbery creation",
    "robotomy request",
    "presidential pardon"
};

AForm *makeShrub(std::string target) {
    return new ShrubberyCreationForm(target);
}

AForm *makeRobot(std::string target) {
    return new RobotomyRequestForm(target);
}

AForm *makePresidential(std::string target) {
    return new PresidentialPardonForm(target);
}

static formCreator formCreators[3] = {
    &makeShrub,
    &makeRobot,
    &makePresidential
};

Intern::Intern(void){}

Intern::Intern(const Intern &other){ (void) other; }

Intern &Intern::operator=(const Intern &other)
{
    (void) other;
    return (*this);
}

Intern::~Intern(void){}

AForm *Intern::makeForm(std::string formName, std::string target)
{
    int i = -1;
    AForm *newFrom = NULL;

    while (++i < 3)
    {
        if (forms[i] == formName)
            break ;
    }

    if (i == 3)
        std::cerr << "requested form doesn't exist" << std::endl;
    else
        {
            std::cout << "Intern creates " << formName << std::endl;
            newFrom = formCreators[i](target);
        }
    return newFrom;    
}



