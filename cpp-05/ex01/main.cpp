#include "Bureaucrat.hpp"

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
        // ex01
        Form form("Form1", 50, 100);
        slave1.signForm(form);
        slave150.signForm(form); // should throw GradeTooLowException
        std::cout << form; // should show form details including whether it's signed or not
    }
    catch (std::exception &e)
    {
        std::cout << "exception caught: " << e.what() << std::endl;
    }
}