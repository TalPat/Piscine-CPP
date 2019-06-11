#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>

class Bureaucrat
{
private:
    int maximum, minimum, grade;
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

    class GradeTooHighException : public std::exception {
        public:
            virtual const char* what() const throw();
    };

    class GradeTooLowException : public std::exception {
        public:
            virtual const char* what() const throw();
    };
};

std::ostream &operator<<(std::ostream& out, const Bureaucrat &obj);

#endif
