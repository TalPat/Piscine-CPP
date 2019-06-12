#include <fstream>
#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

ShrubberyCreationForm::ShrubberyCreationForm():
    Form("Shrubbery", ShrubberyCreationForm::SIGN, ShrubberyCreationForm::EXEC)
{
    this->setTarget("no target");
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string newTarget):
    Form("Shrubbery", ShrubberyCreationForm::SIGN, ShrubberyCreationForm::EXEC)
{
    this->setTarget(newTarget);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &obj):
    Form("Shrubbery", ShrubberyCreationForm::SIGN, ShrubberyCreationForm::EXEC) 
{
    *this = obj;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &obj) {
    if (this != &obj) {
        this->setBeenSigned(obj.getBeenSigned());
    }
    return (*this);
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const {
    std::ofstream outfile;

    if (executor.getGrade() > this->getReqExecute())
        throw GradeTooLowException();
    if (!this->getBeenSigned())
        throw FormNotSignedException();
    outfile.open(this->getTarget()+"_shrubbery");
    outfile << "\
                    v .   ._, |_  .,\n\
            `-._\\/  .  \\ /    |/_\n\
                \\  _\\, y | \\//\n\
            _\\_.___\\, \\/ -.\\||\n\
            `7-,--.`._||  / / ,\n\
            /'     `-. `./ / |/_.'\n\
                        |    |//\n\
                        |_    /\n\
                        |-   |\n\
                        |   =|\n\
                        |    |\n\
    --------------------/ ,  . \\--------._\n\
    " << std::endl;
    outfile.close();
}