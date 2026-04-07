#include "Fixed.hpp"

const int Fixed::bits = 8;

Fixed::Fixed() : value(0) {
}

Fixed::Fixed(const Fixed &copy)
{
    std::cout << "Copy Constructor called" << std::endl;
    *this = copy;
}

Fixed &Fixed::operator=(const Fixed &src)
{
    std::cout << "Copy Assigment Operator called" << std::endl;
    if(this != &src)
        this->value = src.getRawBits();
    return *this;
}

Fixed::~Fixed() {
}

int Fixed::getRawBits(void) const
{
    return this->value;
}

void Fixed::setRawBits(int const b)
{
    this->value = b;
}

Fixed::Fixed(int const n)
{
    value = n << bits;
}

Fixed::Fixed(float const nf)
{
    value = roundf(nf * (1 << bits));
}

std::ostream  &operator<<(std::ostream &out, const Fixed &src)
{
    out << src.toFloat();
    return out;
}

bool Fixed::operator>(const Fixed &src) const
{
    return (value > src.value);
}
bool Fixed::operator<(const Fixed &src) const
{
    return (value < src.value);
}
bool Fixed::operator<=(const Fixed &src) const
{
    return (value <= src.value);
}
bool Fixed::operator>=(const Fixed &src) const
{
    return (value >= src.value);
}
bool Fixed::operator==(const Fixed &src) const
{
    return (value == src.value);
}
bool Fixed::operator!=(const Fixed &src) const
{
    return (value != src.value);
}

Fixed Fixed::operator+(const Fixed &src) const
{
    return Fixed(this->toFloat() + src.toFloat());
}

Fixed Fixed::operator-(const Fixed &src) const
{
    return Fixed(this->toFloat() - src.toFloat());
}

Fixed Fixed::operator*(const Fixed &src) const
{
    return Fixed(this->toFloat() * src.toFloat());
}

Fixed Fixed::operator/(const Fixed &src) const
{
    return Fixed(this->toFloat() / src.toFloat());
}

Fixed &Fixed::operator++() {
    value++;
    return *this;
}

Fixed Fixed::operator++(int) {
    Fixed tmp = *this;
    value++;
    return tmp;
}

Fixed Fixed::operator--(int) {
    Fixed tmp = *this;
    value--;
    return tmp;
}

Fixed &Fixed::operator--() {
    value--;
    return *this;
}

float   Fixed::toFloat( void ) const
{
    return ((float)this->value / (1 << bits));
}

int   Fixed::toInt( void ) const
{
    return (this->value >> bits);
}

Fixed &Fixed::min(Fixed& a, Fixed& b) {
    if (a < b)
        return a;
    return b;
}
const Fixed &Fixed::min(const Fixed& a,const Fixed& b) {
    if (a < b)
        return a;
    return b;
}

Fixed &Fixed::max(Fixed& a, Fixed& b) {
    if (a < b)
        return b;
    return a;
}
const Fixed &Fixed::max(const Fixed& a,const Fixed& b) {
    if (a < b)
        return b;
    return a;
}