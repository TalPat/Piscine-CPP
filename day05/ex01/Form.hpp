#ifndef FORM_HPP
#define FORM_HPP

#include <string>

class Bureaucrat;

class Form
{
private:
    static const int MAX = 1;
    static const int MIN = 150;

    const std::string name;
    bool beenSigned;
    const int reqSign, reqExecute;

public:
    Form();
    Form(std::string newName, int newReqSign, int reqExecute);
    Form(const Form &obj);
    ~Form();
    Form& operator=(const Form &obj);
    
    void beSigned(Bureaucrat &obj);

    std::string getName() const;
    int getReqSign() const;
    int getReqExecute() const;
    bool getBeenSigned() const;

    class GradeTooHighException;

    class GradeTooLowException;
};

class Form::GradeTooHighException : public std::exception {
    public:
        virtual const char* what() const throw();
};

class Form::GradeTooLowException : public std::exception {
    public:
        virtual const char* what() const throw();
};

std::ostream &operator<<(std::ostream& out, const Form &obj);

#endif