#include "BitcoinExchange.hpp"

int main(int argc, char **argv) {
	(void)argc;
	BitcoinExchange m;

	std::ifstream myfile;
	myfile.open(argv[1], std::ios::in);
	if (!myfile) {
		std::cerr << "Error: could not open file\n";
		return 1;
	}
	std::string str;

	std::getline(myfile, str); 
	while (std::getline(myfile, str)) {
		//std::cout << str << std::endl;
		std::stringstream ss(str);
		std::string date;
		std::string amount;
		std::getline(ss, date, '|');
		std::getline(ss, amount);
		size_t start = amount.find_first_not_of(" \t");
		size_t end = amount.find_last_not_of(" \t");
		if (start != std::string::npos) {
			amount = amount.substr(start, end - start + 1);
		}
		size_t start_d = date.find_first_not_of(" \t");
		size_t end_d = date.find_last_not_of(" \t");
		if (start_d != std::string::npos) {
			date = date.substr(start_d, end_d - start_d + 1);
		}
		try {
			isValidDate(date);
			// Valida amount ANTES de pasarlo a getRate
			double amountVal = stringToDouble(amount);
			if (amountVal < 0)
				throw std::runtime_error("not a positive number");
			if (amountVal > 1000)
				throw std::runtime_error("too large a number");
			m.getRate(date, amount);
		} catch (std::exception& e) {
				std::cerr << "Error: " << e.what() << std::endl;
		}
				
	}
	myfile.close();
}
