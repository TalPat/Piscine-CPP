#include "Fixed.hpp"
#include <iostream>
#include <cmath>

// --Constructorss

Fixed::Fixed()
{
    // std::cout << "Default constructor called" << std::endl;
    this->fpv = 0;
}

Fixed::Fixed(const int newfpv)
{
    // std::cout << "Int constructor called" << std::endl;
    this->fpv = newfpv * 256;
}

Fixed::Fixed(const float newfpv)
{
    // std::cout << "Float constructor called" << std::endl;
    this->fpv = (int)(newfpv * 256);
}

Fixed::Fixed(const Fixed &obj) {
    // std::cout << "Copy constructor called" << std::endl;
    *this = obj;
}

// --Operator overloads

void Fixed::operator=(const Fixed &obj) {
    // std::cout << "Assignation operator called" << std::endl;
    this->fpv = obj.getRawBits();
}

std::ostream& operator<<(std::ostream& stream, const Fixed &obj) {
    stream << obj.toFloat();
    return stream;
}

Fixed Fixed::operator+(const Fixed& obj) {
    Fixed fixed;
    fixed.fpv = this->fpv + obj.fpv;
    return (fixed);
}

Fixed Fixed::operator-(const Fixed& obj){
    Fixed fixed;
    fixed.fpv = this->fpv - obj.fpv;
    return (fixed);
}

Fixed Fixed::operator*(const Fixed& obj){
    Fixed fixed(this->toFloat() * obj.toFloat());
    // fixed.fpv = ((this->fpv * obj.fpv) / 256) / 256;
    return (fixed);
}

Fixed Fixed::operator/(const Fixed& obj){
    Fixed fixed( this->toFloat() / obj.toFloat());
    return (fixed);
}

bool Fixed::operator>(const Fixed& obj){
    if(this->toFloat()>obj.toFloat()) {
        return true;
    } else {
        return false;
    }
}
bool Fixed::operator<(const Fixed& obj){
    if(this->toFloat()<obj.toFloat()) {
        return true;
    } else {
        return false;
    }
}
bool Fixed::operator>=(const Fixed& obj){
    if(this->toFloat()>=obj.toFloat()) {
        return true;
    } else {
        return false;
    }
}
bool Fixed::operator<=(const Fixed& obj){
    if(this->toFloat()<=obj.toFloat()) {
        return true;
    } else {
        return false;
    }
}
bool Fixed::operator==(const Fixed& obj){
    if(this->toFloat()==obj.toFloat()) {
        return true;
    } else {
        return false;
    }
}
bool Fixed::operator!=(const Fixed& obj){
    if(this->toFloat()!=obj.toFloat()) {
        return true;
    } else {
        return false;
    }
}

Fixed& Fixed::operator++(){
    this->fpv = this->fpv + 1;
    return *this;
}
Fixed& Fixed::operator--(){
    this->fpv = this->fpv - 1;
    return *this;
}
Fixed Fixed::operator++(int) {
    Fixed temp(*this);
    ++(*this);
    return temp;
}
Fixed Fixed::operator--(int){
    Fixed temp(*this);
    --(*this);
    return temp;
}

// --Destructor

Fixed::~Fixed()
{
    // std::cout << "Destructor called" << std::endl;
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

Fixed Fixed::min(Fixed& a, Fixed& b){
    if (a > b) {
        return b;
    }
    return a;
}
Fixed Fixed::max(Fixed& a, Fixed& b){
    if (a > b) {
        return a;
    }
    return b;

}