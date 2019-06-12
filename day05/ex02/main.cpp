#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void) {
    {
        Bureaucrat bob(14, "Bob");
        ShrubberyCreationForm scf("testshrub");

        std::cout << bob << std::endl;
        std::cout << scf << std::endl;

        bob.signForm(scf);
        bob.executeForm(scf);
    }
    {
        Bureaucrat bob(5, "Bob");
        RobotomyRequestForm rrf("testrobo");

        std::cout << bob << std::endl;
        std::cout << rrf << std::endl;

        bob.signForm(rrf);
        bob.executeForm(rrf);
    }
    {
        Bureaucrat bob(5, "Bob");
        PresidentialPardonForm ppf("testpardon");

        std::cout << bob << std::endl;
        std::cout << ppf << std::endl;

        bob.signForm(ppf);
        bob.executeForm(ppf);
    }
    return (0);
}