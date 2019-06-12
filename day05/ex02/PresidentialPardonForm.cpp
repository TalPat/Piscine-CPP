#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm():
    Form("Shrubbery", PresidentialPardonForm::SIGN, PresidentialPardonForm::EXEC)
{
    this->setTarget("no target");
}

PresidentialPardonForm::PresidentialPardonForm(std::string newTarget):
    Form("Shrubbery", PresidentialPardonForm::SIGN, PresidentialPardonForm::EXEC)
{
    this->setTarget(newTarget);
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &obj):
    Form("Shrubbery", PresidentialPardonForm::SIGN, PresidentialPardonForm::EXEC) 
{
    *this = obj;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm &obj) {
    if (this != &obj) {
        this->setBeenSigned(obj.getBeenSigned());
    }
    return (*this);
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const {
    if (executor.getGrade() > this->getReqExecute())
        throw GradeTooLowException();
    if (!this->getBeenSigned())
        throw FormNotSignedException();
    std::cout << this->getTarget() << " has been pardoned by Zafod Beeblebrox" << std::endl;
}