#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm("ShrubberyCreationForm", 145, 137), _target("shrubrub"){}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : AForm(other), _target(other._target) {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
    if (this != &other)
    {
        AForm::operator=(other);
        _target = other._target;
    }
    return (*this);
}


ShrubberyCreationForm::~ShrubberyCreationForm(void){}


void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{

    execPermission(executor);
    std::ofstream outfile;
    std::string filename;
    filename = _target + "_shrubbery";
    outfile.open(filename.c_str());
    if (outfile.is_open() == false)
        throw std::runtime_error("could not open file");
    
    std::string ascii_tree =
    "       ccee88oo\n"
    "  C8O8O8Q8PoOb o8oo\n"
    " dOB69QO8PdUOpugoO9bD\n"
    "CgggbU8OU qOp qOdoUOdcb\n"
    "    6OuU  /p u gcoUodpP\n"
    "      \\\\//  /douUP\n"
    "        \\\\\\\\\n"
    "         |||/\\\n"
    "         |||\\/\n"
    "         |||||\n"
    "   .....//||||\\....\n";

    outfile << ascii_tree;
    outfile.close();
    
}
