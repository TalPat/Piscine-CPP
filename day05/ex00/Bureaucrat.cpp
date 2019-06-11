#include "Bureaucrat.hpp"
#include <string>
#include <iostream>

Bureaucrat::Bureaucrat(int newGrade, std::string newName): name(newName) {
    this->maximum = 1;
    this->minimum = 150;
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
        this->minimum = obj.minimum;
        this->maximum = obj.maximum;
        (std::string)this->name = obj.name;
    }
    return (*this);
}

void Bureaucrat::incrementGrade() {
    if (this->grade <= this->maximum) {
        throw GradeTooHighException();
    } else {
        this->grade--;
    }
}

void Bureaucrat::decrementGrade() {
    if (this->grade >= this->minimum) {
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
    if (newGrade < this->maximum) {
        throw GradeTooHighException();
    } else if (newGrade > this->minimum) {
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