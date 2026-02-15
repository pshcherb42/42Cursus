#include "Sed.hpp"

Sed::~Sed() {};
Sed::Sed() {};
Sed::Sed(std::string line, std::string s1, std::string s2) : line(line), s1(s1), s2(s2) {};
std::string Sed::replaceStr (std::string line, std::string s1, std::string s2) {
    std::string str = line;
	size_t pos = 0;
	while ((pos = str.find(s1, pos)) != std::string::npos) {
			str.erase(pos, s1.length());
			str.insert(pos, s2);
			pos += s2.length();
	}
	return ( str );
}