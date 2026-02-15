#include "Fixed.hpp"

Fixed::Fixed() : _value(0) {
    std::cout << "Default constructor called" << std::endl;
};

Fixed::Fixed(int const param) {
    _value = param << _base;
    std::cout << "Int constructor called" << std::endl;
};

Fixed::Fixed( float const num) {
    _value = roundf(num * (1 << _base));
    std::cout << "Float constructor called" << std::endl;
};

Fixed::Fixed(const Fixed &copy) : _value(copy._value) {
    std::cout << "Copy constructor called" << std::endl;
};

Fixed& Fixed::operator=(const Fixed &other) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other) {
        _value = other._value;
    }
    return (*this);
};

int Fixed::getRawBits( void ) const {
    std::cout << "getRawBits member function called" << std::endl;
    return (_value);
};

void Fixed::setRawBits( int const raw ) {
    _value = raw;
};

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

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
};

std::ostream& operator<<(std::ostream& os, const Fixed& obj) {
    return os << obj.toFloat();
};