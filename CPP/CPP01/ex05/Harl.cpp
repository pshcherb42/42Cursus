#include "Harl.hpp"

Harl::~Harl() {};
Harl::Harl() {};
void Harl::debug( void ) {
	std::cout <<  "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-";
	std::cout << "ketchup burger. I really do!" << std::endl;
}

void Harl::info( void ) {
    std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put";
	std::cout << "enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning( void ) {
    std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for";
	std::cout << "years, whereas you started working here just last month." << std::endl;
}

void Harl::error( void ) {
    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain( std::string level ) {
	typedef void (Harl::*MESSAGE) ();

    MESSAGE messages[] = { &Harl::debug, &Harl::info, &Harl::warning, &Harl::error };
	std::string levels[] = { "DEBUG", "INFO", "WARNING", "ERROR" };

	for (size_t i = 0; i < 4; ++i) {
		if (level == levels[i]) {
			(this->*messages[i])();
			return ;
		}
	}
	std::cout << "Unknown level: " << level << std::endl;
}