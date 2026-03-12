#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <iomanip>
#include <exception>
#include <cstdlib>

class BitcoinExchange {
    private:
        std::map<std::string, double> mymap;
    public :
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange& other);
        BitcoinExchange& operator=(const BitcoinExchange& other);
        ~BitcoinExchange();
        void getRate(std::string date, std::string amount);

};

bool isValidDate(const std::string& fecha);
double stringToDouble(const std::string& str);
int stringToInt(const std::string& str);

#endif