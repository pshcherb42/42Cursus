#include "Fixed.hpp"

Fixed::Fixed() : _value(0) {
    //std::cout << "Default constructor called" << std::endl;
};

Fixed::Fixed(int const param) {
    _value = param << _base;
    //std::cout << "Int constructor called" << std::endl;
};

Fixed::Fixed( float const num) {
    _value = roundf(num * (1 << _base));
    //std::cout << "Float constructor called" << std::endl;
};
// copy 
Fixed::Fixed(const Fixed &copy) : _value(copy._value) {
    //std::cout << "Copy constructor called" << std::endl;
};
// copy operator
Fixed& Fixed::operator=(const Fixed &other) {
    //std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other) {
        _value = other._value;
    }
    return (*this);
};
// ex00
int Fixed::getRawBits( void ) const {
    //std::cout << "getRawBits member function called" << std::endl;
    return (_value);
};

void Fixed::setRawBits( int const raw ) {
    _value = raw;
};
// ex01
float Fixed::toFloat( void ) const {
    float num;
    num = (float)_value / (1 << _base);
    return (num);
};

int Fixed::toInt( void ) const {
    int param;
    param = _value >> _base;
    return (param);
};
// increment operators
Fixed& Fixed::operator++() {
    ++_value;
    return *this;
};

Fixed Fixed::operator++(int) {
    Fixed temp = *this;
    ++_value;
    return temp;
};
// decrement operators
Fixed& Fixed::operator--() {
    --_value;
    return *this;
};

Fixed Fixed::operator--(int) {
    Fixed temp = *this;
    --_value;
    return temp;
};
// min max static
Fixed Fixed::min(Fixed& a, Fixed& b) {
    if (a._value > b._value)
        return b;
    return a;
};

Fixed Fixed::min(const Fixed& a, const Fixed& b) {
    if (a._value > b._value)
        return b;
    return a;
};

Fixed Fixed::max(Fixed& a, Fixed& b) {
    if (a._value < b._value)
        return b;
    return a;
};

Fixed Fixed::max(const Fixed& a, const Fixed& b) {
    if (a._value < b._value)
        return b;
    return a;
};
// destructor
Fixed::~Fixed() {
    //std::cout << "Destructor called" << std::endl;
};
// cout overload
std::ostream& operator<<(std::ostream& os, const Fixed& obj) {
    return os << obj.toFloat();
};
// ex02
// comparison operators
bool operator>(const Fixed &left, const Fixed &right) {
    return (left.getRawBits() > right.getRawBits());
};

bool operator<(const Fixed &left, const Fixed &right) {
    return (left.getRawBits() < right.getRawBits());
};

bool operator>=(const Fixed &left, const Fixed &right) {
    return !(left.getRawBits() < right.getRawBits());
};

bool operator<=(const Fixed &left, const Fixed &right) {
    return !(left.getRawBits() > right.getRawBits());
};

bool operator==(const Fixed &left, const Fixed &right) {
    return (left.getRawBits() == right.getRawBits());
};

bool operator!=(const Fixed &left, const Fixed &right) {
    return !(left.getRawBits() == right.getRawBits());
};

// arithmetic operators
Fixed operator+(const Fixed& left, const Fixed& right) {
    Fixed result;
    result.setRawBits( left.getRawBits() + right.getRawBits() );
    return (result);
};

Fixed operator-(const Fixed& left, const Fixed& right) {
    Fixed result;
    result.setRawBits( left.getRawBits() - right.getRawBits() );
    return (result);
};

Fixed operator*(const Fixed& left, const Fixed& right) {
    return Fixed( left.toFloat() * right.toFloat() );
};

Fixed operator/(const Fixed& left, const Fixed& right) {
    return Fixed( left.toFloat() / right.toFloat() );
};
