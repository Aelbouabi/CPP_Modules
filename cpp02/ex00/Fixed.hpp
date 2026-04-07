#include <iostream>

class Fixed
{
    private:
        int value;
        static const int bits;

    public:
        Fixed();
        Fixed(const Fixed& copy);
        ~Fixed();
        Fixed &operator=(const Fixed &src);
        int     getRawBits(void) const;
        void    setRawBits(int const b);
};

