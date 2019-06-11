#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>

class Bureaucrat
{
private:
    static const int MAX = 1;
    static const int MIN = 150;

    int grade;
    const std::string name;
public:
    Bureaucrat(int newGrade, std::string newName);
    ~Bureaucrat();
    Bureaucrat(Bureaucrat &obj);
    Bureaucrat& operator=(const Bureaucrat &obj);

    void incrementGrade();
    void decrementGrade();

    int getGrade() const;
    std::string getName() const;

    void setGrade(int newGrade);

    class GradeTooHighException;
    
    class GradeTooLowException;
};


class Bureaucrat::GradeTooLowException : public std::exception {
    public:
        virtual const char* what() const throw();
};

class Bureaucrat::GradeTooHighException : public std::exception {
    public:
        virtual const char* what() const throw();
};

std::ostream &operator<<(std::ostream& out, const Bureaucrat &obj);

#endif
