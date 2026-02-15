#include "Fixed.hpp"

int main( void ) {
    Fixed a;
    Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
    Fixed const c( Fixed( 5.05f ) - Fixed( 2 ) );
    Fixed const d( Fixed( 5.05f ) + Fixed( 2 ) );
    Fixed const e( Fixed( 5.05f ) / Fixed( 2 ) );

    std::cout << "++" << std::endl;
    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;
     std::cout << "--" << std::endl;
    std::cout << a << std::endl;
    std::cout << --a << std::endl;
    std::cout << a << std::endl;
    std::cout << a-- << std::endl;
    std::cout << a << std::endl;
     std::cout << "arithmetic" << std::endl;
    std::cout << b << std::endl;
    std::cout << c << std::endl;
    std::cout << d << std::endl;
    std::cout << e << std::endl;
     std::cout << "min/max" << std::endl;
    std::cout << Fixed::max( a, b ) << std::endl;
    std::cout << Fixed::min( a, b ) << std::endl;
     std::cout << "comparison" << std::endl;
    Fixed x(5.0f);
    Fixed y(3.0f);
    Fixed z(5.0f);

    std::cout << "x = " << x << ", y = " << y << ", z = " << z << std::endl;
    std::cout << "x > y: " << (x > y) << std::endl;   // Should be 1 (true)
    std::cout << "y > x: " << (y > x) << std::endl;   // Should be 0 (false)
    std::cout << "x >= z: " << (x >= z) << std::endl; // Should be 1 (true)
    std::cout << "x <= z: " << (x <= z) << std::endl; // Should be 1 (true)
    std::cout << "x == z: " << (x == z) << std::endl; // Should be 1 (true)
    std::cout << "x != y: " << (x != y) << std::endl; // Should be 1 (true)
    std::cout << "x < y: " << (x < y) << std::endl;   // Should be 0 (false)
    std::cout << "y < x: " << (y < x) << std::endl;   // Should be 1 (true)
    return 0;
}