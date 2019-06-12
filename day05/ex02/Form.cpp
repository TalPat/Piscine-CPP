#include "Form.hpp"
#include <string>
#include <iostream>
#include "Bureaucrat.hpp"

Form::Form(std::string newName, int newReqSign, int newReqExecute): name(newName), reqSign(newReqSign), reqExecute(newReqExecute) {
    if (newReqSign < Form::MAX || newReqExecute < Form::MAX) {
        throw GradeTooHighException();
    } else if (newReqSign > Form::MIN || newReqExecute > Form::MIN) {
        throw GradeTooLowException();
    }
    this->beenSigned = 0;
}

Form::~Form() {

}

Form::Form(const Form &obj): name(obj.name), reqSign(obj.reqSign), reqExecute(obj.reqExecute){
    *this = obj;
}

Form& Form::operator=(const Form &obj) {
    if (this != &obj) {
        this->beenSigned = obj.beenSigned;
    }
    return (*this);
}

void Form::beSigned(Bureaucrat &obj) {
    if (obj.getGrade() > this->getReqSign()) {
        throw GradeTooLowException();
    } else {
        this->beenSigned = true;
    }
}

std::string Form::getName() const {
    return (this->name);
}

int Form::getReqSign() const {
    return (this->reqSign);
}

int Form::getReqExecute() const {
    return (this->reqExecute);
}

bool Form::getBeenSigned() const {
    return (this->beenSigned);
}

const char* Form::GradeTooLowException::what() const throw() {
    return("Too low");
}

const char* Form::GradeTooHighException::what() const throw() {
    return("Too high");
}

const char* Form::FormNotSignedException::what() const throw() {
    return("Not signed");
}

std::ostream &operator<<(std::ostream& out, const Form &obj) {
    out << obj.getName() << ", Form sign requirement " << obj.getReqSign() << ", Form execute requirement " << obj.getReqExecute() << (obj.getBeenSigned() ? ", signed" : ", unsigned");
    return (out);
}


std::string Form::getTarget() const{
    return (this->target);
}

void Form::setTarget(std::string newTarget){
    this->target = newTarget;
}


void Form::setBeenSigned(bool newBeenSigned) {
    this->beenSigned = newBeenSigned;
}