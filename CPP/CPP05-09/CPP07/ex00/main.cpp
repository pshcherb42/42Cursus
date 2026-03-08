#include "whatever.hpp"

//  int main( void ) {
//  	int a = 2;
//  	int b = 3;
//  	std::cout << "Before swap" << std::endl;
//  	std::cout << "a = " << a << ", b = " << b << std::endl;
//  	std::cout << "After swap";
//  	::swap( a, b );
//  	std::cout << std::endl;

//  	std::cout << "a = " << a << ", b = " << b << std::endl;
//  	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
//  	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
//  	std::cout << std::endl;

//  	std::cout << "Strings" << std::endl;
//  	std::string c = "chaine1";
//  	std::string d = "chaine2";
//  	std::cout << "Before swap" << std::endl;
//  	std::cout << "c = " << c << ", d = " << d << std::endl;
//  	std::cout << "After swap";
//  	::swap(c, d);
//  	std::cout << std::endl;
//  	std::cout << "c = " << c << ", d = " << d << std::endl;
//  	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
//  	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;

//  	return 0;
//  }

 class Awesome
 {
 public:
     Awesome(int n) : _n(n) {}

     bool operator==(const Awesome& other) const { return _n == other._n; }
     bool operator!=(const Awesome& other) const { return _n != other._n; }
     bool operator>(const Awesome& other) const { return _n > other._n; }
     bool operator<(const Awesome& other) const { return _n < other._n; }
     bool operator>=(const Awesome& other) const { return _n >= other._n; }
     bool operator<=(const Awesome& other) const { return _n <= other._n; }

     int get() const { return _n; }

 private:
     int _n;
 };

 int main()
 {
     Awesome a(2);
     Awesome b(4);

     std::cout << "min: " << min(a,b).get() << std::endl;
     std::cout << "max: " << max(a,b).get() << std::endl;

     swap(a,b);

     std::cout << "after swap:" << std::endl;
     std::cout << "a = " << a.get() << std::endl;
     std::cout << "b = " << b.get() << std::endl;
 }