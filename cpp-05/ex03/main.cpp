#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"


int main()
{
    
    
    try {
        // ex00
        Bureaucrat slave1("slave", 1);
        Bureaucrat slave150("slave", 150);
        
        // Form form2("Form2", 200, 30); // should throw GradeTooLowException
        // Form form3("Form3", 10, 0); // should throw GradeTooHighException
        // Bureaucrat slave0("slave", 0); // throws exception
        // Bureaucrat slave151("slave", 151); // throws exception
        Bureaucrat slave2(slave1); 
        Bureaucrat slave3;
        slave3 = slave1;
        std::cout << slave1;
        // slave1.incrementGrade(); // should throw GradeTooHighException
        // slave150.decrementGrade(); // should throw GradeTooLowException

        // ex02
        ShrubberyCreationForm shrubForm("jrda");
        RobotomyRequestForm robotForm("robot");
        PresidentialPardonForm presForm("president");

        slave1.signForm(shrubForm);
        slave1.executeForm(shrubForm);
        Bureaucrat slave72("slave75", 72);
        slave72.signForm(robotForm);
        slave72.executeForm(robotForm);
        slave1.executeForm(robotForm);
        slave1.signForm(presForm);
        slave1.executeForm(presForm);
        // ex03
        Intern intern;
        AForm *form2 = intern.makeForm("robotomy request", "robot");
        if (form2) {
            slave1.signForm(*form2);
            slave1.executeForm(*form2);
            delete form2;
        }
        AForm *form3 = intern.makeForm("imaginary form", "ayoub");
        if (form3) {
            slave1.signForm(*form3);
            slave1.executeForm(*form3);
            delete form3;
        }
    }
    catch (std::exception &e)
    {
        std::cout << "exception caught: " << e.what() << std::endl;
    }
}