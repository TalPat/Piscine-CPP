#include "Bureaucrat.hpp"
#include <iostream>

int main(void) {
    Bureaucrat bob(150, "Bob");
    Bureaucrat janice(1, "Janice");
    try
    {
        std::cout << bob << std::endl;
        bob.decrementGrade();
        std::cout << bob << std::endl;
        bob.incrementGrade();
        std::cout << bob << std::endl;
    }
    catch(const Bureaucrat::GradeTooHighException& e)
    {
        std::cerr << e.what() << std::endl;
        std::cout << 1 << std::endl;
    }
    catch(const Bureaucrat::GradeTooLowException& e)
    {
        std::cerr << e.what() << std::endl;
        std::cout << 2 << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
        std::cout << 3 << std::endl;
    }

    try
    {
        std::cout << janice << std::endl;
        janice.incrementGrade();
        std::cout << janice << std::endl;
        janice.decrementGrade();
        std::cout << janice << std::endl;
    }
    catch(const Bureaucrat::GradeTooHighException& e)
    {
        std::cerr << e.what() << std::endl;
        std::cout << 4 << std::endl;
    }
    catch(const Bureaucrat::GradeTooLowException& e)
    {
        std::cerr << e.what() << std::endl;
        std::cout << 5 << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
        std::cout << 6 << std::endl;
    }

    try
    {
        Bureaucrat phil(160, "phil");
    }
    catch(const Bureaucrat::GradeTooHighException& e)
    {
        std::cerr << e.what() << std::endl;
        std::cout << 4 << std::endl;
    }
    catch(const Bureaucrat::GradeTooLowException& e)
    {
        std::cerr << e.what() << std::endl;
        std::cout << 5 << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
        std::cout << 6 << std::endl;
    }

    try
    {
        Bureaucrat phil(0, "tree");
    }
    catch(const Bureaucrat::GradeTooHighException& e)
    {
        std::cerr << e.what() << std::endl;
        std::cout << 4 << std::endl;
    }
    catch(const Bureaucrat::GradeTooLowException& e)
    {
        std::cerr << e.what() << std::endl;
        std::cout << 5 << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
        std::cout << 6 << std::endl;
    }
    
    return (0);
}