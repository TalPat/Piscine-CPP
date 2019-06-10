#include "Fixed.hpp"
#include <iostream>

// --Constructorss

Fixed::Fixed()
{
    std::cout << "Default constructor called" << std::endl;
    this->fpv = 0;
}

Fixed::Fixed(const int newfpv)
{
    std::cout << "Int constructor called" << std::endl;
    this->fpv = newfpv * 256;
}

Fixed::Fixed(const float newfpv)
{
    std::cout << "Float constructor called" << std::endl;
    this->fpv = (int)(newfpv * 256);
}

Fixed::Fixed(const Fixed &obj) {
    std::cout << "Copy constructor called" << std::endl;
    *this = obj;
}

// --Operator overloads

void Fixed::operator=(const Fixed &obj) {
    std::cout << "Assignation operator called" << std::endl;
    this->fpv = obj.getRawBits();
}

std::ostream& operator<<(std::ostream& stream, const Fixed &obj) {
    stream << obj.toFloat();
    return stream;
}

// --Destructor

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

// --Member functions

int Fixed::getRawBits(void) const{
    return this->fpv;
}

void Fixed::setRawBits(int const raw) {
    this->fpv = raw;
}

float Fixed::toFloat(void) const {
    float a = this->fpv;
    return (a/256);
}

int Fixed::toInt(void) const {
    return (this->fpv/256);
}