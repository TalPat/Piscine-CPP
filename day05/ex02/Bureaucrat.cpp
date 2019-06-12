#include "Bureaucrat.hpp"
#include <string>
#include <iostream>

Bureaucrat::Bureaucrat(int newGrade, std::string newName): name(newName) {
    this->setGrade(newGrade);
}

Bureaucrat::~Bureaucrat() {

}

Bureaucrat::Bureaucrat(Bureaucrat &obj) {
    *this = obj;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &obj) {
    if (this != &obj) {
        this->grade = obj.grade;
        (std::string)this->name = obj.name;
    }
    return (*this);
}

void Bureaucrat::incrementGrade() {
    if (this->grade <= Bureaucrat::MAX) {
        throw GradeTooHighException();
    } else {
        this->grade--;
    }
}


void Bureaucrat::signForm(Form &obj) {
    try
    {
        obj.beSigned(*this);
        std::cout << this->getName() << ", signed " << obj.getName() << std::endl;;
    }
    catch(const Form::GradeTooHighException& e)
    {
        std::cerr << e.what() << '\n';
    }
    catch(const Form::GradeTooLowException& e)
    {
        std::cerr << e.what() << '\n';
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}

void Bureaucrat::executeForm(Form const & form) {
    try
    {
        form.execute(*this);
        std::cout << this->getName() << ", executes " << form.getName() << std::endl;;
    }
    catch(const Form::GradeTooHighException& e)
    {
        std::cerr << e.what() << '\n';
    }
    catch(const Form::GradeTooLowException& e)
    {
        std::cerr << e.what() << '\n';
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}





void Bureaucrat::decrementGrade() {
    if (this->grade >= Bureaucrat::MIN) {
        throw GradeTooLowException();
    } else {
        this->grade++;
    }
}

int Bureaucrat::getGrade() const {
    return (this->grade);
}

std::string Bureaucrat::getName() const {
    return (this->name);
}

void Bureaucrat::setGrade(int newGrade) {
    if (newGrade < Bureaucrat::MAX) {
        throw GradeTooHighException();
    } else if (newGrade > Bureaucrat::MIN) {
        throw GradeTooLowException();
    } else {
        this->grade = newGrade;
    }
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
    return("Too low");
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return("Too high");
}

std::ostream &operator<<(std::ostream& out, const Bureaucrat &obj) {
    out << obj.getName() << ", bureaucrat grade " << obj.getGrade();
    return (out);
}