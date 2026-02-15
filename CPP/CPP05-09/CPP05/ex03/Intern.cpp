#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp" 
#include "PresidentialPardonForm.hpp"
#include <iostream>
#include <cctype>

Intern::Intern() {}
Intern::Intern(const Intern& other) { (void)other; }
Intern& Intern::operator=(const Intern& other) { (void)other; return *this;}

// Helper function to convert to lowercase
std::string Intern::toLowerCase(const std::string& str) {
    std::string result = str;
    for (size_t i = 0; i < result.length(); ++i) {
        result[i] = std::tolower(result[i]);
    }
    return result;
}

AForm* Intern::createShrubbery(const std::string& target) {
    return new ShrubberyCreationForm(target);
}

AForm* Intern::createRobotomy(const std::string& target) {
    return new RobotomyRequestForm(target);
}

AForm* Intern::createPardon(const std::string& target) {
    return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(std::string name, std::string target) {
    // Convert input to lowercase for comparison
    std::string lowerName = toLowerCase(name);

    // All accepted form names - exact matches only
    std::string formNames[] = {
        "shrubbery creation", "shrubberycreationform", "shrubbery",
        "robotomy request", "robotomyrequestform", "robotomy", 
        "presidential pardon", "presidentialpardonform", "pardon"
    };
    
    // Corresponding creator functions (same order as names)
    AForm* (Intern::*creators[])(const std::string&) = {
        &Intern::createShrubbery, &Intern::createShrubbery, &Intern::createShrubbery,
        &Intern::createRobotomy, &Intern::createRobotomy, &Intern::createRobotomy,
        &Intern::createPardon, &Intern::createPardon, &Intern::createPardon
    };
    
    int totalForms = sizeof(formNames) / sizeof(formNames[0]);
    
    for (int i = 0; i < totalForms; i++) {
        if (lowerName == formNames[i]) {
            std::cout << "Intern creates " << name << std::endl;
            return (this->*creators[i])(target);
        }
    }
    
    std::cout << "Error: Form '" << name << "' does not exist" << std::endl;
    return NULL;
}

Intern::~Intern() {}