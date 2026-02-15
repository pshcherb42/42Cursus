#include <iostream>

class Fixed {
    private:
        int _value;
        static const int _base = 8;
    public:
        Fixed(); // default constructor
        Fixed(const Fixed &copy); // copy constructor
        Fixed &operator=(const Fixed &other); // assignmetn operator
        int getRawBits( void ) const;
        void setRawBits( int const raw);
        ~Fixed();
};