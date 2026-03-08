#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP
#include <iostream>
#include <string>
#include <stdexcept>
#include <cctype>
#include <iomanip> // for setprecision
#include <sstream>
#include <climits> // for limits
#include <cstdlib>

class ScalarConverter {
    private:
        ScalarConverter();
    public:
        ScalarConverter(const ScalarConverter& other);
        ScalarConverter& operator=(const ScalarConverter& other);

        static void convert(std::string input);

        ~ScalarConverter();
};

bool isValidNumber(const std::string &s);

#endif