#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main(void) {
    try
    {
        Bureaucrat bob(20, "Bob1");
        Form bobsForm("bobsForm", 30, 20);
        std::cout << bob << ", form: " << bobsForm << std::endl;
        bob.signForm(bobsForm);
        std::cout << bob << ", form: " << bobsForm << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    try
    {
        Bureaucrat bob(40, "Bob2");
        Form bobsForm("bobsForm", 30, 20);
        std::cout << bob << ", form: " << bobsForm << std::endl;
        bob.signForm(bobsForm);
        std::cout << bob << ", form: " << bobsForm << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    try
    {
        Bureaucrat bob(40, "Bob3");
        Form bobsForm("bobsForm", 0, 20);
        std::cout << bob << ", form: " << bobsForm << std::endl;
        bob.signForm(bobsForm);
        std::cout << bob << ", form: " << bobsForm << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    return (0);
}