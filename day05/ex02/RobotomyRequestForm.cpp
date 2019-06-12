#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
#include <time.h>
#include <stdlib.h>

RobotomyRequestForm::RobotomyRequestForm():
    Form("Shrubbery", RobotomyRequestForm::SIGN, RobotomyRequestForm::EXEC)
{
    this->setTarget("no target");
}

RobotomyRequestForm::RobotomyRequestForm(std::string newTarget):
    Form("Shrubbery", RobotomyRequestForm::SIGN, RobotomyRequestForm::EXEC)
{
    this->setTarget(newTarget);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &obj):
    Form("Shrubbery", RobotomyRequestForm::SIGN, RobotomyRequestForm::EXEC) 
{
    *this = obj;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &obj) {
    if (this != &obj) {
        this->setBeenSigned(obj.getBeenSigned());
    }
    return (*this);
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const {
    srand(time(0));
    if (executor.getGrade() > this->getReqExecute())
        throw GradeTooLowException();
    if (!this->getBeenSigned())
        throw FormNotSignedException();
    std::cout << this->getTarget() << " has been robotomized " << (rand() % 2 > 0 ? "successfully" : "unsuccessfully") << std::endl;
}