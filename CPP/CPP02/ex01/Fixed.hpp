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
        ~Fixed(); // Destructor
};

std::ostream& operator<<(std::ostream& os, const Fixed& obj); // overload << operator