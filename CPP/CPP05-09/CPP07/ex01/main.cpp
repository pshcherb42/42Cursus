#include "iter.hpp"

template<typename T>
void increment(T& x) { ++x; };

template< typename T >
void print( T const & x ) { std::cout << x << std::endl; return; }

//   int main() {
//       int arr[8] = {0,1,2,3,4,5,6,7};

//       iter(&arr[0], 8, print<int>);
//       iter(arr, 8, increment<int>);
//       iter(&arr[0], 8, print<int>);

//       std::string str[3] = {"hello", "world", "polina"};
//       iter(str, 3, print<std::string>);
//   }

 class Awesome
 {
     public:
         Awesome( void ) : _n( 42 ) { return; }
         int get( void ) const { return this->_n; }
     private:
         int _n;
 };

 std::ostream & operator<<( std::ostream & o, Awesome const & rhs ) { o << rhs.get(); return o; }

 int main() {
     int tab[] = { 0, 1, 2, 3, 4 };
     Awesome tab2[5];
     iter( tab, 5, print<int> );
     iter( tab2, 5, print<Awesome> );

     iter( tab, 5, print );
     iter( tab2, 5, print );
     return 0;
 }