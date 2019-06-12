#ifndef FORM_HPP
#define FORM_HPP

#include <string>

class Bureaucrat;

class Form
{
private:
    static const int MAX = 1;
    static const int MIN = 150;

    std::string target;
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
    virtual void execute(Bureaucrat const &executor) const = 0;

    std::string getName() const;
    std::string getTarget() const;
    void setTarget(std::string newTarget);
    void setBeenSigned(bool newBeenSigned);
    int getReqSign() const;
    int getReqExecute() const;
    bool getBeenSigned() const;

    class GradeTooHighException;

    class GradeTooLowException;

    class FormNotSignedException;
};

class Form::GradeTooHighException : public std::exception {
    public:
        virtual const char* what() const throw();
};

class Form::GradeTooLowException : public std::exception {
    public:
        virtual const char* what() const throw();
};

class Form::FormNotSignedException : public std::exception {
    public:
        virtual const char* what() const throw();
};

std::ostream &operator<<(std::ostream& out, const Form &obj);

#endif