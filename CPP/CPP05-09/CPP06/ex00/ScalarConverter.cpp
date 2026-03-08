#include "ScalarConverter.hpp"


ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& other) { (void)other; }

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) { 
	(void)other;
	//because the class has no members
	// the def const is private static utilit class. I never create objects
	// scalarConverter::convert(value)
	return *this;
}

void ScalarConverter::convert(std::string input) {
	if (input.length() == 1 && !std::isdigit(input[0])) {
		char c = input[0];
		std::cout << "char : '" << c << "'" << std::endl;
		std::cout << "int : " << static_cast<int>(c) << std::endl;
		std::cout << std::fixed << std::setprecision(1);
		std::cout << "float : " << static_cast<float>(c) << "f" << std::endl;
		std::cout << "double : " << static_cast<double>(c) << std::endl;
	}
	
	else if (input == "nan" || input == "nanf") {
		std::cout << "char : impossible" << std::endl;
		std::cout << "int : impossible" << std::endl;
		std::cout << "float : nanf" << std::endl;
		std::cout << "double : nan" << std::endl;
	}
	else if (input == "+inf" || input == "-inf" || input == "+inff" || input == "-inff") {
		std::string sign = (input[0] == '-') ? "-" : "+";

		std::cout << "char : impossible" << std::endl;
		std::cout << "int : impossible" << std::endl;
		std::cout << "float : " << sign << "inff" << std::endl;
		std::cout << "double : " << sign << "inf" << std::endl;
	}
	else {
		try {
			if (isValidNumber(input)) {
				double d = std::strtod(input.c_str(), NULL);
				if (d < 0 || d > 127)
					std::cout << "char : impossible" << std::endl;
				else if(!std::isprint(static_cast<char>(d)))
					std::cout << "char : Non displayable" << std::endl;
				else 
					std::cout << "char : '" << static_cast<char>(d) << "'" << std::endl;
				if (d < INT_MIN || d > INT_MAX)
					std::cout << "int : impossible" << std::endl;
				else
					std::cout << "int : " << static_cast<int>(d) << std::endl;
				std::cout << std::fixed << std::setprecision(1);
				std::cout << "float : " << static_cast<float>(d) << "f" << std::endl;
				std::cout << "double : " << static_cast<double>(d) << std::endl; 
			} else {
				throw std::invalid_argument("invalid input");
			}
			
		}
		catch(...){
			std::cout << "char : impossible" << std::endl;
			std::cout << "int : impossible" << std::endl;
			std::cout << "float : impossible" << std::endl;
			std::cout << "double : impossible" << std::endl;
		}
	}
}

bool isValidNumber(const std::string &s) {
	char *end;
	std::strtod(s.c_str(), &end);
	if(*end == '\0')
		return true;
	if (*end == 'f' && *(end + 1) == '\0')
		return s.find('.') != std::string::npos;
	return false;
}

ScalarConverter::~ScalarConverter() {}