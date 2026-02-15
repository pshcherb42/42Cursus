#include <iostream>
#include <cmath>

class Fixed {
    private:
        int _value;
        static const int _base = 8;
    public:
        Fixed(); // default constructor
        Fixed( int const param ); // integer constructor
        Fixed( float const num); // float constructor
        Fixed(const Fixed &copy); // copy constructor
        Fixed &operator=(const Fixed &other); // assigment operator
        // ex00
        int getRawBits( void ) const;
        void setRawBits( int const raw);
        // ex01
        float toFloat( void ) const; // converts fixed-point to float
        int toInt( void ) const; // converts fixed to int
        // ex02
        // increment operatoras
        Fixed& operator++(); // prefix
        Fixed operator++(int); // postfix
        // decrement operators
        Fixed& operator--(); // prefix
        Fixed operator--(int); // postfix
        // min max static
        static Fixed min(Fixed& a, Fixed& b);
        static Fixed min(const Fixed& a, const Fixed& b);
        static Fixed max(Fixed& a, Fixed& b);
        static Fixed max(const Fixed& a, const Fixed& b);
        ~Fixed(); // Destructor
};

std::ostream& operator<<(std::ostream& os, const Fixed& obj); // overload << operator
// comparison operators
bool operator>(const Fixed &left, const Fixed &right);
bool operator<(const Fixed &left, const Fixed &right);
bool operator>=(const Fixed &left, const Fixed &right);
bool operator<=(const Fixed &left, const Fixed &right);
bool operator==(const Fixed &left, const Fixed &right);
bool operator!=(const Fixed &left, const Fixed &right);
// arithmetic operators
Fixed operator+(const Fixed& left, const Fixed& right);
Fixed operator-(const Fixed& left, const Fixed& right);
Fixed operator*(const Fixed& left, const Fixed& right);
Fixed operator/(const Fixed& left, const Fixed& right);