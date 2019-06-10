#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed(/* args */)
{
    std::cout << "Default constructor called" << std::endl;
    this->fpv = 0;
}

Fixed::Fixed(const Fixed &obj) {
    std::cout << "Copy constructor called" << std::endl;
    *this = obj;
}

void Fixed::operator=(const Fixed &obj) {
    std::cout << "Assignation operator called" << std::endl;
    this->fpv = obj.getRawBits();
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const{
    std::cout << "getRawBits member function called" << std::endl;
    return this->fpv;
}

void Fixed::setRawBits(int const raw) {
    this->fpv = raw;
}