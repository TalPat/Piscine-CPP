#ifndef FORM_HPP
#define FORM_HPP

#include <string>

class Form
{
private:
    const std::string name;
    bool beenSigned;
    const int reqSign, reqExecute;

public:
    Form(/* args */);
    Form(const Form &obj);
    ~Form();
    

    std::string getName();
    int getReqSign();
    int getReqExecute();
    bool getBeenSigned();

    class GradeTooHighException : public std::exception {
        public:
            virtual const char* what() const throw();
    };

    class GradeTooLowException : public std::exception {
        public:
            virtual const char* what() const throw();
    };
};

std::ostream &operator<<(std::ostream& out, const Form &obj);

#endif