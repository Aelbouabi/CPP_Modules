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
        ~Fixed();
        Fixed &operator=(const Fixed &src);
        int     getRawBits(void) const;
        void    setRawBits(int const b);
        float   toFloat( void ) const;
        int     toInt( void ) const;
};

std::ostream  &operator<<(std::ostream &out, const Fixed &src);
