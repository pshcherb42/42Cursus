#ifndef SED_HPP
#define SED_HPP

# include <iostream>
# include <fstream>
# include <string>

class Sed {
    private:
        std::string line;
        std::string s1;
        std::string s2;
    public:
        Sed();
        Sed(std::string line, std::string s1, std::string s2);
        ~Sed();
        std::string replaceStr (std::string line, std::string s1, std::string s2);
};

#endif