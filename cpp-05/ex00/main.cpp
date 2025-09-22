#include "Bureaucrat.hpp"

int main()
{
    
    
    try {

        Bureaucrat slave1("slave", 21474836489);
        Bureaucrat slave150("slave", 150);
        // Bureaucrat slave0("slave", 0); // throws exception
        // Bureaucrat slave151("slave", 151); // throws exception
        Bureaucrat slave2(slave1); 
        Bureaucrat slave3;
        slave3 = slave1;
        std::cout << slave1;
        // slave1.incrementGrade(); // should throw GradeTooHighException
        // slave150.decrementGrade(); // should throw GradeTooLowException
    }
    catch (std::exception &e)
    {
        std::cout << "exception caught: " << e.what() << std::endl;
    }
}