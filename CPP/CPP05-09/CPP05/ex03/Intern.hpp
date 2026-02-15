#ifndef INTERN_HPP
#define INTERN_HPP
#include "AForm.hpp"
#include <string>

class ShrubberyCreationForm;
class RobotomyRequestForm;
class PresidentialPardonForm;

class Intern {
	private:
        // Helper function for case conversion
        std::string toLowerCase(const std::string& str);
		
        AForm* createShrubbery(const std::string& target);
        AForm* createRobotomy(const std::string& target);
        AForm* createPardon(const std::string& target);		
	public:
		Intern();
		Intern(const Intern& other);
		Intern& operator=(const Intern& other);

		AForm* makeForm(std::string name, std::string target);

		~Intern();
};

#endif