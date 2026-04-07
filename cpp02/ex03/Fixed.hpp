#include <iostream>
#include <cmath>

class Fixed
{
    private:
        int value;
        static const int bits;

    public:
        Fixed();
        Fixed(int const n);
        Fixed(float const nf);
        Fixed(const Fixed& copy);
        Fixed &operator=(const Fixed &src);
        ~Fixed();
        int     getRawBits(void) const;
        void    setRawBits(int const b);
        float   toFloat( void ) const;
        int     toInt( void ) const;
        bool operator>(const Fixed &src) const;
        bool operator<(const Fixed &src) const;
        bool operator<=(const Fixed &src) const;
        bool operator>=(const Fixed &src) const;
        bool operator==(const Fixed &src) const;
        bool operator!=(const Fixed &src) const;
        Fixed operator+(const Fixed &src) const;
        Fixed operator-(const Fixed &src) const;
        Fixed operator*(const Fixed &src) const;
        Fixed operator/(const Fixed &src) const;
        Fixed& operator++();
        Fixed& operator--();
        Fixed operator++(int);
        Fixed operator--(int);
        static Fixed& min(Fixed& a, Fixed& b);
        static const Fixed& min(const Fixed& a, const Fixed& b);
        static Fixed& max(Fixed& a, Fixed& b);
        static const Fixed& max(const Fixed& a, const Fixed& b);
};

std::ostream  &operator<<(std::ostream &out, const Fixed &src);
