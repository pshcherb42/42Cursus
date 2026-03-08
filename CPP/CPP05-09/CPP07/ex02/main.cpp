#include <iostream>
#include "Array.hpp"

 #define MAX_VAL 750
 int main(int, char**)
 {
     // create arrays
     Array<int> numbers(MAX_VAL); // myclass
     int* mirror = new int[MAX_VAL]; // normal array
     // fill with random value, both array are identical
     srand(time(NULL));
     for (int i = 0; i < MAX_VAL; i++)
     {
         const int value = rand();
         numbers[i] = value;
         mirror[i] = value;
     }
     //SCOPE
     {
         Array<int> tmp = numbers; // copy tests
         Array<int> test(tmp); // tmp y test are destroyed , if this explodes the deep copy doesnt work
     }

     for (int i = 0; i < MAX_VAL; i++)
     {
         if (mirror[i] != numbers[i]) // checks the operator[] didnt break values
         {
             std::cerr << "didn't save the same value!!" << std::endl;
             return 1;
         }
     }
     try
     {
         numbers[-2] = 0; // out of bounds tests, throws exception
     }
     catch(const std::exception& e)
     {
         std::cerr << e.what() << '\n';
     }
     try
     {
         numbers[MAX_VAL] = 0; // triggers esception
     }
     catch(const std::exception& e)
     {
         std::cerr << e.what() << '\n';
     }

     for (int i = 0; i < MAX_VAL; i++)
     {
         numbers[i] = rand();
     }
     delete [] mirror;//
     return 0;
 }

// int main () {
//     Array<int> m(3);

//     m[0] = 1; m[1] = 2; m[2] = 3;

//     for (unsigned int i = 0; i < m.size(); ++i) {
//         std::cout << "array int m: " << m[i] << std::endl;
//     }

//     Array<int> a = m;
//     a[0] = 999;
//     std::cout << "\nCopy constructor: " << m[0] << ", " << a[0] << std::endl;

//     Array<int> c;
//     c = a;
//     std::cout << "\nAssignment operator: " << c[0] << ", " << a[0] << std::endl;

//     const Array<int> d = c;
//     std::cout << "\nconstant: " << d[0] << std::endl;

//     std::cout << "\nOut of range access: should throw exception!" << std::endl;
//     try {
//         std::cout << a[10] << std::endl;
//     } catch (std::exception& e) {
//         std::cout << "cought : " << e.what() << std::endl;
//     }

//     std::cout << "\n test string array: \n";
//     Array<std::string> str(3);

//     str[0] = "hola";
//     str[1] = "polina";
//     str[2] = "polilla";
//     for (unsigned int i = 0; i < str.size(); ++i) {
//         std::cout << "str element: " << str[i] << std::endl;
//     }
// }