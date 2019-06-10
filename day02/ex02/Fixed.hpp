#ifndef FIXED_HPP
#define FIXED_HPP
#include <iostream>

class Fixed
{
private:
    int fpv;
    static const int fb = 8;
public:
    Fixed();
    Fixed(const Fixed &obj);
    Fixed(const int newfpv);
    Fixed(const float newfpv);

    void operator=(const Fixed &obj);
    Fixed operator+(const Fixed& obj);
    Fixed operator-(const Fixed& obj);
    Fixed operator*(const Fixed& obj);
    Fixed operator/(const Fixed& obj);

    bool operator>(const Fixed& obj);
    bool operator<(const Fixed& obj);
    bool operator>=(const Fixed& obj);
    bool operator<=(const Fixed& obj);
    bool operator==(const Fixed& obj);
    bool operator!=(const Fixed& obj);

    Fixed& operator++();
    Fixed& operator--();
    Fixed operator++(int);
    Fixed operator--(int);

    ~Fixed();

    int getRawBits(void) const;
    void setRawBits(int const raw);
    float toFloat(void) const;
    int toInt(void) const;

    static Fixed min(Fixed& a, Fixed& b);
    static Fixed max(Fixed& a, Fixed& b);
};


std::ostream& operator<<(std::ostream& stream, const Fixed &obj);

#endif