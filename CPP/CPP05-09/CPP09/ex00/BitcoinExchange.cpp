#include "BitcoinExchange.hpp"


BitcoinExchange::BitcoinExchange() {
    
	std::ifstream myfile;
	std::string str;
	std::string date;
    std::string rate;
	myfile.open("data.csv", std::ios::in);
	if (!myfile) {
		std::cout << "No such file is present\n";
        return;
	} 
    // read a particular record
    std::getline(myfile, str);
    while (std::getline(myfile, str)) {
        std::stringstream ss(str);
        
        if (std::getline(ss, date, ',')) {
            if (std::getline(ss, rate)) {
                double rateVal = strtod(rate.c_str(), NULL);
                mymap[date] = rateVal;
            }
        }
    }
    myfile.close();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) {
    mymap = other.mymap;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
    if (this != &other) {
        mymap = other.mymap;
    }
    return *this;
}

void BitcoinExchange::getRate(std::string date, std::string amount) {
    double a = stringToDouble(amount);
    std::map<std::string, double>::const_iterator it = mymap.lower_bound(date);
    if (it != mymap.end() && it->first == date) {
        std::cout << it->first << " => " << amount << " = " << (it->second * a) << std::endl;
        return ;
    }
    if (it != mymap.begin()) {
        --it;
        std::cout << it->first << " => " << amount << " = " << (it->second * a) << std::endl;
        return ;
    }
    throw std::runtime_error("date too early");
}

double stringToDouble(const std::string& str) {
    std::stringstream ss(str);
    double value;
    ss >> value;

    if (ss.fail() || !ss.eof()) {
        throw std::invalid_argument("Invalid double value: " + str);
    }
    return value;
}

int stringToInt(const std::string& str) {
    std::stringstream ss(str);
    int value;
    ss >> value;

    if (ss.fail() || !ss.eof()) {
        throw std::invalid_argument("Invalid integer value: " + str);
    }
    return value;
}

BitcoinExchange::~BitcoinExchange() {}

bool isValidDate(const std::string& date)
{
    // Format check: exactly "NNNN-NN-NN"
    if (date.size() != 10 || date[4] != '-' || date[7] != '-')
        throw std::runtime_error("bad input => " + date);

    // All other characters must be digits
    for (size_t i = 0; i < date.size(); ++i)
    {
        if (i == 4 || i == 7)
            continue;
        if (!std::isdigit(date[i]))
            throw std::runtime_error("bad input => " + date);
    }

    // Parse components
    int year  = std::atoi(date.substr(0, 4).c_str());
    int month = std::atoi(date.substr(5, 2).c_str());
    int day   = std::atoi(date.substr(8, 2).c_str());

    if (year < 1 || month < 1 || month > 12 || day < 1 || day > 31)
        throw std::runtime_error("bad input => " + date);

    // Days per month (no leap year needed — tema only requires format validity)
    int days_in_month[] = { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    if (day > days_in_month[month - 1])
        throw std::runtime_error("bad input => " + date);

    return true;
}