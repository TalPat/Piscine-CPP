#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed
{
private:
    int fpv;
    static const int fb = 8;
public:
    Fixed(/* args */);
    Fixed(const Fixed &obj);
    void operator=(const Fixed &obj);
    ~Fixed();
    int getRawBits(void) const;
    void setRawBits(int const raw);
};

#endif