#include "ScalarConverter.hpp"

int main(int argc, char **argv) {
	if (argc != 2) {
		std::cout << "TEST PROGRAM" << std::endl;
		std::cout << std::endl;

		std::cout << "Character input" << std::endl;
		std::cout << "./convert a" << std::endl;
		ScalarConverter::convert("a");
		std::cout << std::endl;

		std::cout << "Non-printable ASCII" << std::endl;
		std::cout << "./convert 31" << std::endl;
		ScalarConverter::convert("31");
		std::cout << std::endl;

		std::cout << "Maximum int overflow" << std::endl;
		std::cout << "./convert 2147483648" << std::endl;
		ScalarConverter::convert("2147483648");
		std::cout << std::endl;

		std::cout << "Minimum int overflow" << std::endl;
		std::cout << "./convert -2147483649" << std::endl;
		ScalarConverter::convert("-2147483649");
		std::cout << std::endl;

		std::cout << "Valid float with f" << std::endl;
		std::cout << "./convert 42.0f" << std::endl;
		ScalarConverter::convert("42.0f");
		std::cout << std::endl;

		std::cout << "Decimal float" << std::endl;
		std::cout << "./convert 4.2" << std::endl;
		ScalarConverter::convert("4.2");
		std::cout << std::endl;

		std::cout << "nan" << std::endl;
		std::cout << "./convert nan" << std::endl;
		ScalarConverter::convert("nan");
		std::cout << std::endl;

		std::cout << "Infinity" << std::endl;
		std::cout << "./convert -inff" << std::endl;
		ScalarConverter::convert("-inff");
		std::cout << std::endl;
		std::cout << "./convert +inff" << std::endl;
		ScalarConverter::convert("+inff");
		std::cout << std::endl;
		std::cout << "./convert +inf" << std::endl;
		ScalarConverter::convert("+inf");
		std::cout << std::endl;
		std::cout << "./convert -inf" << std::endl;
		ScalarConverter::convert("-inf");
		std::cout << std::endl;

		std::cout << "Garbage input" << std::endl;
		std::cout << "./convert hello" << std::endl;
		ScalarConverter::convert("hello");
		std::cout << std::endl;
		std::cout << "./convert 42abc" << std::endl;
		ScalarConverter::convert("42abc");
		std::cout << std::endl;
		std::cout << "./convert 4.2.3" << std::endl;
		ScalarConverter::convert("4.2.3");
		std::cout << std::endl;
		std::cout << "./convert 4.2.3f" << std::endl;
		ScalarConverter::convert("4.2.3f");
		std::cout << std::endl;

		std::cout << "Asterisk" << std::endl;
		std::cout << "./convert '*'" << std::endl;
		ScalarConverter::convert("*");
		std::cout << std::endl;

		std::cout << "Edge ASCII values" << std::endl;
		std::cout << "./convert 127" << std::endl;
		ScalarConverter::convert("127");
		std::cout << std::endl;
		std::cout << "./convert 128" << std::endl;
		ScalarConverter::convert("128");
		std::cout << std::endl;

		std::cout << "Zero variations" << std::endl;
		std::cout << "./convert 0" << std::endl;
		ScalarConverter::convert("0");
		std::cout << std::endl;
		std::cout << "./convert 0.0" << std::endl;
		ScalarConverter::convert("0.0");
		std::cout << std::endl;
		std::cout << "./convert 0.0f" << std::endl;
		ScalarConverter::convert("0.0f");
		std::cout << std::endl;

		std::cout << "The single NASTIEST input" << std::endl;
		std::cout << "./convert 42f" << std::endl;
		ScalarConverter::convert("42f");

	} else
		ScalarConverter::convert(argv[1]);
}